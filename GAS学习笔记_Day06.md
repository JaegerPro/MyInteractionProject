# GAS 学习笔记 · Day 06

> 日期：2026-05-09  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：**PredictionKey 深水课 —— 客户端预测的底层原理**  
> 对应总纲：原路线图 Day06 是「GA 生命周期串讲」，本日实际走向了**深水区 A（Prediction 原理）**。  
> 形式：不加新功能，**只读原理**。所有代码定位点参照 `UGA_Fireball.cpp`。

---

## 一、今天收获了什么（先看结论）

- 把"GAS 为什么能自动回滚"这件事**从 API 层打到实现层**，彻底理解了 PredictionKey 的生命周期。
- 区分清楚**激活 ≠ 扣费**、**Ability 决策 ≠ ASC 执行**、**ScopedPredictionKey ≠ PredictionKeyWhenActivated** 这三组容易混的概念。
- 推演了一个真实面试会问的问题：**「会不会出现不扣蓝的火球？」**——答：当前代码有三道防线挡着，但只要破坏任一道就会翻车。
- 拿到了一段**可以直接背给面试官听的「五分钟 Prediction 讲法」**（见第十节）。

---

## 二、一句话速记（想不起来时先看这行）

> **PredictionKey 是客户端预测期所有副作用共享的票根。ASC 用 `FScopedPredictionWindow` 做隐式上下文把 Key 自动贴到 GE/Tag/Task 上，同时登记"失败回滚"回调到 `FPredictionKeyDelegates::DelegateMap`。服务器发回执时，失败就广播那把 Key 触发所有已登记的回滚，成功就 `CatchUpTo` 清掉记录。**

这一段里埋的关键字：**PredictionKey / ScopedPredictionWindow / DelegateMap / CatchUpTo / BroadcastRejected**。会说这几个词并能展开讲，就是"看过源码"的水平。

---

## 三、PredictionKey 是什么

### 3.1 定位

`FPredictionKey` 是一个**轻量 struct**（不是 UObject）。含三个关键字段：

| 字段 | 作用 |
|------|------|
| `Current` | 当前这把 Key 的编号（`int16`，会回环） |
| `Base` | 派生关系：这把 Key 是基于哪一把生成的（嵌套预测用） |
| `PredictiveConnection` | 哪条网络连接生成的（服务器用它区分不同客户端的同号 Key） |

### 3.2 生活类比（想不起来时用这个）

**取餐号小票**：  
- 客户端点单 → 服务器给一张小票（Key #73）
- 客户端拿着小票想象自己喝到拿铁（= 预测）
- 做成了 → 喊号兑现，小票作废
- 做不成 → 喊号退钱，小票作废，**预测副作用一笔勾销**

### 3.3 谁生成它

**只有客户端生成。** 服务器不生成新 Key，它只**接收**客户端发来的 Key 并沿用。

生成时机：`ASC->TryActivateAbility` 内部自增：

```cpp
FPredictionKey Key;
Key.Current = ++ASC->ReplicatedPredictionKeyCounter;
Key.PredictiveConnection = ASC->GetOwnerNetConnection();
```

### 3.4 它的核心价值

**一次激活产生的 5 件副作用（扣蓝、加 Tag、加 Cue、启动 Task、Spawn）共享同一把 Key。** 服务器拒绝这把 Key 时，**5 件事一起回滚**——不是一件件回滚，是按 Key 整批撤销。这是 GAS 敢允许客户端"假激活"的真正底气。

---

## 四、Key 是怎么"自动贴"到副作用上的

### 4.1 反向问题引入

看 `UGA_Fireball.cpp` 的这行：

```cpp
// OnInputReleased 里
if (!CommitAbilityCost(CachedHandle, CachedActorInfo, CachedActivationInfo))
```

`CommitAbilityCost` 内部会 Apply Cost GE，理应带 Key。**但你没把 Key 显式传进去**——那 GE 怎么知道自己该贴 Key 的？

### 4.2 答案：`FScopedPredictionWindow`（RAII）

ASC 身上有一个成员 `ScopedPredictionKey`（"**我现在做的事该贴什么 Key**"），默认为空。`FScopedPredictionWindow` 是一个栈上 RAII 对象：

```cpp
struct FScopedPredictionWindow
{
    UAbilitySystemComponent* ASC;
    FPredictionKey RestoreKey;

    FScopedPredictionWindow(UAbilitySystemComponent* InASC, FPredictionKey NewKey)
    {
        ASC = InASC;
        RestoreKey = ASC->ScopedPredictionKey;
        ASC->ScopedPredictionKey = NewKey;      // 进入窗口
    }
    ~FScopedPredictionWindow()
    {
        ASC->ScopedPredictionKey = RestoreKey;  // 离开窗口
    }
};
```

**机制意义**：只要你的代码**跑在 ActivateAbility 调用栈里**，ASC 内部所有 API 读 `ScopedPredictionKey` 都能拿到 #73。你**不需要、也不应该**手动贴 Key。

### 4.3 嵌套预测：派生 Key（Base 链）

`OnInputReleased` 是异步回调，**不在 `ActivateAbility` 栈上**。GAS 的处理是：Task 在回调客户端前**派生新 Key**：

```cpp
FPredictionKey DerivedKey = FPredictionKey::CreateNewPredictionKey(ASC);
DerivedKey.Base = #73;   // 指向激活时那把 Key
FScopedPredictionWindow Window(ASC, DerivedKey);
OnRelease.Broadcast(TimeHeld);   // 用户的 OnInputReleased 跑在这里
```

派生 Key 的意义：
- **服务器回滚 #73（整次激活作废）** → 子 Key 全废
- **服务器只回滚 #74（只拒绝扣蓝）** → 火球本身不受影响

### 4.4 一次激活的 Key 树（示意）

```
     #73 (ActivateAbility 时生成)
      │
      ├── #74 (OnInputReleased 时派生)   Base=#73
      │     └── 扣蓝 GE 贴 #74
      │
      ├── #75 (OnFireballLaunchEvent 时派生)   Base=#73
      │     └── (被 HasAuthority 拦截，客户端不 Spawn)
      │
      └── ...
```

---

## 五、回滚怎么实现的（魔法不存在）

### 5.1 三个朴素的数据结构

| 结构 | 作用 |
|------|------|
| `FActiveGameplayEffect` | 每条生效中的 GE，带 `PredictionKey` 字段 |
| `FActiveGameplayEffectsContainer` | ASC 上装所有 ActiveGE 的 `TArray` |
| `FPredictionKeyDelegates::DelegateMap` | `TMap<int16, 回调列表>`，**核心**：Key → 所有"失败时要执行的动作" |

### 5.2 Apply 时同时做两件事

`UAbilitySystemComponent::ApplyGameplayEffectSpecToSelf` 的关键两行：

```cpp
// 1. 把 Key 缝在 ActiveGE 上
NewActive.PredictionKey = ScopedPredictionKey;

// 2. 登记"失败回滚"回调到 Key 的委托表
ScopedPredictionKey.NewRejectedDelegate().BindUObject(
    this,
    &UAbilitySystemComponent::RemoveActiveGameplayEffect_NoReturn,
    NewActive.Handle);   // 闭包捕获"该删哪条"
```

**产生副作用的代码，顺手生成它的撤销代码。** 这是整套系统最优雅的一手（设计模式上接近 Command + Observer）。

### 5.3 服务器回执

```cpp
if (bSuccess)
    ClientActivateAbilitySucceed(Handle, ClientKey);
else
    ClientActivateAbilityFailed(Handle, ClientKey.Current);
```

### 5.4 客户端收到"失败"的 10 行代码

```cpp
void FPredictionKeyDelegates::BroadcastRejectedDelegate(int16 Key)
{
    FDelegates* D = Get().DelegateMap.Find(Key);
    if (!D) return;
    for (auto& Event : D->RejectedDelegates)
        Event.ExecuteIfBound();   // 注册时绑定的所有回滚一次性跑完
    Get().DelegateMap.Remove(Key);
}
```

**没有复杂算法、没有状态机、没有事务**——`TMap` 查 Key、循环跑闭包。

### 5.5 嵌套 Key 的回滚：注册时展平

Apply 时若 Key = #74、Base = #73，注册回调**同时挂到 #74 和 #73 下**：

```cpp
int16 Cur = 74;
while (Cur != 0) {
    DelegateMap.FindOrAdd(Cur).RejectedDelegates.Add(Callback);
    Cur = LookupBase(Cur);   // 73 → 0 停
}
```

- 广播 #74 → 只触发挂在 74 下的回调（火球继续）
- 广播 #73 → 触发挂在 73 下的所有回调（包含 74 当初登记的那份）→ **整棵子树一起回滚**

**关键认知**：运行时**根本没有"树"这种数据结构**，是注册时就把冒泡关系展平成多份登记。**用空间换时间**。

### 5.6 成功路径：`CatchUpTo`

```cpp
for (int16 i = 0; i <= Key; ++i)
{
    if (auto* D = DelegateMap.Find(i)) {
        for (auto& E : D->CaughtUpDelegates) E.ExecuteIfBound();
        DelegateMap.Remove(i);
    }
}
```

意义：**"你预测的一切被服务器认账了，票根作废。"** 大多数副作用不需要 CaughtUp 做额外动作（本来就 Apply 上了）。

---

## 六、容易混的三组概念

### 6.1 激活 ≠ 扣费

**超市会员卡类比**：办卡 = 激活（授权状态）。卡本身不扣钱，**真正打折发生在结账那一刻**（= Apply GE）。

对应到代码：`TryActivateAbility` 只开启预测窗口、调 ActivateAbility，它**从不 Apply 任何 GE**，也**从不写任何 ActiveGE.PredictionKey**。写 Key 发生在"真的 Apply GE 的那一刻"。

### 6.2 Ability 决策 ≠ ASC 执行

| 角色 | 职责 |
|------|------|
| **GA** | 决定"做什么"（扣蓝、加 Tag、开 Task） |
| **ASC** | 决定"怎么做"（Apply GE 细节、贴 Key、注册回滚） |
| **`FScopedPredictionWindow`** | 提供"在什么上下文做"（当前 Key 是几号） |

**GA 从不直接操作 ActiveGE 列表**，它只向 ASC 下单。所以你在 GA 里写代码感知不到 Key——这是**封装意图**，不是疏忽。

### 6.3 `ScopedPredictionKey` ≠ `PredictionKeyWhenActivated`

| 字段 | 挂在哪 | 意义 |
|------|--------|------|
| `ASC->ScopedPredictionKey` | ASC 成员 | 当前上下文的 Key（**会变**，随 Window 开关） |
| `ActivationInfo.PredictionKeyWhenActivated` | 激活信息里 | **激活时**那把 Key（固定不变的快照） |

举例：`OnInputReleased` 里 `ScopedPredictionKey == #74`（派生子 Key），但 `CachedActivationInfo.PredictionKeyWhenActivated == #73`（最初那把）。

`HasAuthority(&ActivationInfo)` 内部读的是 `PredictionKeyWhenActivated`——它问的是"**这次激活是谁权威**"，不是"当前这个子操作是谁权威"。

---

## 七、对着 `UGA_Fireball.cpp` 把整条链跑一遍（带回滚）

```
Client 按 Q
  │
  ├─ ASC 生成 Key #73
  ├─ FScopedPredictionWindow(#73) 开
  │   ├─ UGA_Fireball::ActivateAbility 跑
  │   │   ├─ CachedActivationInfo = ActivationInfo   ← 顺手把 #73 存下
  │   │   ├─ CommitAbilityCooldown → Apply CDGE
  │   │   │    ├─ 缝 #73 到 CDGE.PredictionKey
  │   │   │    └─ 登记"#73 失败 → 移除 CDGE"到 DelegateMap[73]
  │   │   ├─ ASC->AddGameplayCue(Cue_Fireball_Charging)
  │   │   │    └─ ⚠️ 走 NetMulticast 路径，不带 Key，不参与回滚
  │   │   │        （所以 EndAbility 里手动 Remove 那行兜底是必要的）
  │   │   └─ WaitInputRelease Task::ReadyForActivation
  │   │        └─ 登记"#73 失败 → 杀该 Task"到 DelegateMap[73]
  │   └─ Window 析构（ScopedKey 复位）
  │
  ├─ ServerTryActivateAbility RPC(#73)（网络）
  │      ──── 并发 ────
  │      Server: 跑 ActivateAbility → 结果回执 ClientActivateAbilitySucceed / Failed
  │
  ├─（松手）WaitInputRelease 回调：
  │   ├─ 派生 Key #74（Base=#73）
  │   ├─ FScopedPredictionWindow(#74) 开
  │   │   ├─ RemoveGameplayCue（仍无 Key）
  │   │   ├─ CommitAbilityCost → Apply CostGE
  │   │   │    ├─ 缝 #74 到 CostGE.PredictionKey
  │   │   │    └─ 同时登记回滚回调到 DelegateMap[74] 和 DelegateMap[73]
  │   │   ├─ PlayMontageAndWait Task → 两张表都登记
  │   │   └─ WaitGameplayEvent Task → 两张表都登记
  │   └─ Window 析构（恢复到 #73）
  │
  └─ 收到 Server 回执：
      ├─ 成功 #73 → CatchUpTo(73)：所有 ≤73 的待确认表项作废
      └─ 失败 #73 → BroadcastRejected(73)：DelegateMap[73] 里所有回调依次跑
                    - 移除 CDGE
                    - 移除 CostGE（74 当初也挂在 73 下）
                    - 杀 WaitInputRelease / Montage / WaitGameplayEvent Task
                    - Cue 不在列表里 → 需要 EndAbility 里手动清
```

---

## 八、「会不会出现不扣蓝的火球？」专题

### 8.1 结论

**在当前代码结构下：不会。** 但有三道防线挡着，**任何一道破掉就会翻车**。

### 8.2 三道防线

| 防线 | 作用 |
|------|------|
| `SpawnFireball` 里 `HasAuthority(&ActivationInfo)` 守卫 | 客户端永远不自己 Spawn，避免"客户端伪火球" |
| `SpawnFireball` 里 `IsActive()` 守卫 | Ability 已 End 时，回调即使晚到也不 Spawn |
| Server 的 `OnInputReleased` 里 CommitCost 失败就 return | 扣蓝失败根本走不到 Spawn 路径 |

### 8.3 翻车场景（反面教材）

**错误改法 A**：去掉 `HasAuthority` 守卫让客户端也 Spawn 一颗火球。  
- Client 预测扣蓝 + 本地 Spawn 火球
- Server 判断蓝不够 → 回滚 Key #74（蓝回来了）
- **但客户端那颗预测 Spawn 的 Actor 没缝 Key，不会被回滚**
- → 蓝没扣、火球还在，真正的"不扣蓝的火球"

**错误改法 B**：在 `ActivateAbility` 里就 CommitCost，`OnInputReleased` 里直接 Spawn 不再 Commit，**且**同时去掉 Spawn 的 `HasAuthority` 守卫。同理会产生本地伪火球。

### 8.4 根本原因

**Actor 不是 GE，不参与 Prediction 回滚，一旦 Spawn 就回不去了。** GAS 的解法：**让所有"不可回滚的副作用"只在服务器做**——Spawn Actor、一次性音效、发送网络消息都必须在 `HasAuthority` 后执行。

### 8.5 业务上真需要客户端零延迟表现怎么办？

答：**Predicted Projectile 方案**（非 GAS 原生，要自己写）：
- 客户端 Spawn 一颗**轻量预测弹**（无碰撞、无伤害、纯视觉）
- 服务器的真弹同步过来后做位置对齐
- 预测失败时**手动销毁预测弹**

这就是 Fortnite 里那个专门子系统的职责。

---

## 九、关于 `AddGameplayCue` 的一个坑（补 Day05 伏笔）

**Cue 有两条添加路径**：

| 路径 | 是否带 PredictionKey | 参与回滚 |
|------|---------------------|---------|
| `ASC->AddGameplayCue(Tag)` | ❌ 不带，纯 NetMulticast | ❌ 不参与 |
| GE 资产上挂 GameplayCue → Apply GE | ✅ 带，随 GE 回滚 | ✅ 参与 |

所以总纲 6.3 说"**Cue 推荐挂在 GE 上**"——根本原因不是语义统一，是**为了享受预测/回滚的免费午餐**。

### 当前代码的兜底

`UGA_Fireball::EndAbility` 里这一段：

```cpp
if (UAbilitySystemComponent* ASC = ActorInfo->AbilitySystemComponent.Get())
{
    ASC->RemoveGameplayCue(GASTags::Cue_Fireball_Charging);
}
```

**语义上是正确的**：既然蓄力 Cue 不参与自动回滚，就要在**所有出口**手动清。可作为 STAR 面试小故事：

> "我之前发现：技能被 Cancel 时蓄力光环不消失。原因是 Cue 没随 Ability 的 `ActivationOwnedTags` 自动清理范围，而 `AddGameplayCue` 这条路径也不参与 PredictionKey 的回滚链路。改法是在 `EndAbility` 里统一手动 `RemoveGameplayCue`。"

---

## 十、可以背给面试官的五分钟版本

> GAS 的客户端预测建立在 `PredictionKey` 上。每次 `TryActivateAbility` 时 ASC 生成一把 Key，通过 `FScopedPredictionWindow` 作为隐式上下文被所有 GAS API 感知。客户端预测期产生的 GE、Tag、Task 都会把 Key 缝在身上，并**同时**登记"失败回滚"回调到 Key 的 `DelegateMap` 里。
>
> 嵌套的异步回调会派生子 Key（`Base` 字段指向父 Key），登记回调时会同时写入所有祖先 Key 的条目，这样服务器拒绝父 Key 时整棵子树能一起回滚。
>
> 服务器权威回执通过 RPC 回到客户端，成功走 `CatchUpTo` 清记录，失败走 `BroadcastRejectedDelegate` 触发所有已登记的回滚动作。
>
> 不可回滚的副作用（Spawn Actor、一次性 Cue）必须在 `HasAuthority` 后执行，避免绕过这个系统——否则会出现"不扣蓝的火球"这种脏局面。如果业务需要客户端零延迟的投射物表现，那得走 Predicted Projectile，客户端 Spawn 一颗轻量预测弹，失败时手动销毁——这是 GAS 原生没给的能力，Fortnite 里是一整个子系统。

背到这里，面试官基本就认定"这人读过 GAS 源码"。

---

## 十一、自检题（回答不出就翻回去看对应小节）

1. `PredictionKey` 是 UObject 还是 struct？谁生成它？ → §3
2. 一次激活期间，客户端做的 5 个副作用（扣蓝、加 Tag、加 Cue、播动画、Spawn）会带几把 Key？ → §4.4
3. `FScopedPredictionWindow` 的析构函数做了什么？为什么要做？ → §4.2
4. `OnInputReleased` 里 Apply 的 Cost GE 带的 Key 是 #73 还是 #74？为什么？ → §4.3
5. 如果服务器只告诉客户端"#74 失败"，但 #73 没失败，火球还能放出去吗？ → §5.5 / §4.3
6. 客户端的 `ActiveGameplayEffect.PredictionKey` 是什么时候、谁写进去的？ → §5.2 / §6.2（**不是 TryActive 那刻；不是 Ability 干的；是 ASC 的 `ApplyGameplayEffectSpecToSelf` 干的**）
7. `DelegateMap` 里一个 Key 的回调列表能装几种不同类型的回调？ → §5.2（任意多种，每个副作用自己登记自己的撤销动作）
8. 服务器告诉客户端"#73 成功"时，客户端需要做什么清理动作吗？ → §5.6（大多副作用不需要额外做事，只清表项）
9. "不扣蓝的火球"会不会在你当前代码里出现？破坏哪道防线会出？ → §8

---

## 十二、心法总结

1. **好系统的魔法拆开都是"就这"**：PredictionKey 回滚 = `TMap` 查键 + 闭包循环跑完。看到复杂现象时，相信底层是朴素的。
2. **Apply 的同时登记撤销**（Command + Observer）：这个模式不止 GAS 用，任何"可能失败的操作"都适合这么写。
3. **隐式上下文优于显式参数**：如果每个 GAS API 都要多传一个 `PredictionKey`，代码会很丑、很容易漏贴。`ScopedPredictionKey + RAII` 让"贴 Key"变成**想不贴都不行**。
4. **可回滚副作用 vs 不可回滚副作用**是永恒的分界线：GE、Tag、部分 Cue 可回滚 → 放在预测里；Spawn Actor、网络消息、一次性音效不可回滚 → 必须服务器权威。
5. **激活不等于承诺代价**：这就是为什么 `CommitAbility` 独立于 `ActivateAbility` 存在。超市会员卡办了不扣钱，结账才扣。
6. **系统级思考 vs API 级思考**：API 级是"CommitAbilityCost 怎么用"，系统级是"CommitAbilityCost 失败时整条数据流哪里会漏？" ——面试官考察的永远是后者。

---

## 十三、下一步建议

今天是**纯原理日**，没碰代码。下面几个方向按兴趣选：

- **A. 回到总纲路线图 Day06 的原计划**：把 GA 生命周期串讲补完（结合今天讲的预测机制，理解会更深一层）。
- **B. 眼见为实**：在 `UGA_Fireball` 里加几行 `UE_LOG` 把 `GetCurrentActivationInfo().GetActivationPredictionKey()` 打出来，实际看一把 #73 → #74 的派生。
- **C. Day07 GE 数据流串讲**：今天理解了"GE 怎么回滚"，配合"GE 怎么生效"形成闭环。
- **D. 直接进 Day08 做 Cooldown/Cost 正式化**：今天懂了 Cost GE 内部贴 Key 的机制，再回头把 Cost UI 写工整。

**个人判断**：推荐 **B → A → C** 的顺序。加日志是把今天的原理"落到眼睛能看到"的最省事办法，半小时就能做完，做完再走 A 会有"原来如此"的踏实感。

---

## 十四、状态自述（非技术，但重要）

今天这一课是在**低能量状态下从"暗黑 4 无聊"里回弹出来后**完成的。能把三段深水内容看下来并主动追问"PredictionKey 是 TryActive 时写的吗、是 Ability 干的吗"，**本身就是一次有效的回血**。

**教训**：

- 回弹 ≠ 满电。下次再出现"想学但怕自己看不懂"的时候，**允许自己每次只读一段**、**允许随时喊停**，比硬撑 3 小时效率高得多。
- "装懂过去"是学 GAS 的头号敌人。**把猜测摊出来问**（像今天问"是不是 TryActive 时写的"）才是对的姿态——被纠正一次比看十遍原文管用。
- 不要用"进度"衡量今天——今天**只**学了 PredictionKey 一个主题，但这个主题是很多人学一年 GAS 都没真正啃过的底层。质胜于量。

---

