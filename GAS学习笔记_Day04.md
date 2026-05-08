# GAS 学习笔记 · Day 04

> 日期：2026-05-07  
> 工程：`D:\UnrealProjects\MyProject`  
> 主题：**Debuff 工程化 + UI 监听取舍 + Attribute 联动 CMC**  
> 对应总纲：学习路线图 Day04

---

## 一、今天解决了什么（先看结果）

- **Debuff 施加链路清晰了**：技能命中后，`ApplyGameplayEffectSpecToTarget` 才是"挂 Debuff"的核心。
- **免疫从 if 分支升级为数据驱动**：优先用 GE 的 `Application Tag Requirements` / Immunity，而不是在 C++ 到处写判断。
- **Burn UI 不再硬拧**：Tag 只做显隐，层数走 ActiveGE，秒数可用本地倒计时 + 事件校准。
- **补齐了高含金量缺口**：`MoveSpeed` 等属性与 `CharacterMovementComponent` 的联动，走属性变化委托同步。

---

## 二、速查表（把今天踩坑一次记住）

| # | 现象 / 问题 | 根因 | 建议做法 |
|---|---|---|---|
| 1 | `OnBurnTagChanged` 只有 0/1 | Tag 计数是"是否存在"，不是层数 | 层数用 `GetCurrentStackCount` 或 StackChangeDelegate |
| 2 | 想监听 Burn 层数变化 | 只绑了 Tag 事件 | 改绑 ActiveGE 的 `OnGameplayEffectStackChangeDelegate` |
| 3 | Burn 剩余时间难拿 | 直接从 Tag 推时间不成立 | 用 `GetActiveEffectsTimeRemaining(Query)`，UI 本地跑并定期校准 |
| 4 | 眩晕恢复后速度不对 | 直接在 Stun 回调里写死速度 | 用 Attribute（如 `MoveSpeed`）统一驱动 CMC |
| 5 | Duration/Infinite Buff 改属性没触发联动 | 只在 `PostGameplayEffectExecute` 里处理 | 在角色绑定 `GetGameplayAttributeValueChangeDelegate` 同步 |

---

## 三、Debuff 架构：从能跑到能扩展

### 1) 入口不变：命中时 Apply GE

- 施加 Debuff 的本质：**对目标 ASC 应用 Duration/Infinite GE**。
- 你可以在投射物命中、近战命中事件、或 GameplayEvent 回调里统一调用。

### 2) 组合方式推荐：Main GE + 子 GE

- **`GE_Hit_Main`**：做入口和公共条件。
- **子 GE**（`GE_Debuff_Burn`、`GE_Debuff_Stun`...）：只管各自机制。
- 优势：新增 Debuff 时改资产多、改 C++ 少，维护成本低。

### 3) 免疫与准入放到 GE 配置

优先顺序：
1. `Application Tag Requirements`
2. Immunity / Ongoing Requirements
3. 最后才是 C++ 兜底分支

> 一句话：**能用 GE 资产表达的规则，不要写死在代码里**。

---

## 四、Burn UI：工程化取舍（别为 UI 绑死主链路）

### UI 三要素拆开看

- **显隐**：监听 `State.Debuff.Burn`（Tag 事件足够）
- **层数**：从 ActiveGE 查 `StackCount`
- **秒数**：本地倒计时（`Tick/Timer`）+ 事件校准（层变/刷新时重置）

### 推荐策略

- **战斗主链路优先**：先做图标 + 层数，秒数后补。
- **避免高频重查**：有 Handle 时直接查 Handle，没 Handle 再用 Query。

---

## 五、属性联动 CMC（今天最关键补丁）

## 结论先行

- **`PostGameplayEffectExecute` 适合处理 Instant 结果落地（如 Damage→Health）**。
- **Duration/Infinite 对移动速度这类持续属性的联动，不应只依赖 PostExecute**。
- 正确主路径：
  1. AttributeSet 提供 `MoveSpeed`（含 Clamp/复制）
  2. Character 在初始化时绑定属性变化委托
  3. 委托回调里 `CMC->MaxWalkSpeed = NewValue`
// MyCharacter.cpp —— 在 ASC 初始化完成后（PossessedBy / OnRep_PlayerState 里）调用一次
void AMyCharacter::BindAttributeDelegates()
{
    if (!AbilitySystemComponent || !AttributeSet) return;

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
        AttributeSet->GetMoveSpeedAttribute()
    ).AddUObject(this, &AMyCharacter::OnMoveSpeedChanged);

    // 首帧同步一次，避免初始化顺序问题
    if (auto* CMC = GetCharacterMovement())
    {
        CMC->MaxWalkSpeed = AttributeSet->GetMoveSpeed();
    }
}

void AMyCharacter::OnMoveSpeedChanged(const FOnAttributeChangeData& Data)
{
    if (auto* CMC = GetCharacterMovement())
    {
        CMC->MaxWalkSpeed = Data.NewValue;
    }
}

### 为什么这更稳

- 任何来源（Buff、Debuff、装备、被动）改到 `MoveSpeed`，都会走同一套同步路径。
- 眩晕结束、减速移除、装备脱下都不会遗漏恢复逻辑。
- 代码语义清晰：**移动速度由属性统一管理，不由技能状态硬编码**。

---

## 六、Day04 最小闭环清单

- [ ] Burn 可叠层（层数正确变化）
- [ ] Stun 可阻断输入（并可恢复）
- [ ] Debuff 免疫可配置（不靠 if）
- [ ] UI 显示 Burn 图标与层数
- [ ] `MoveSpeed` 属性变化可实时同步到 CMC

---

## 七、今天的心法

1. **Tag 是状态开关，不是叠层计数器。**
2. **Debuff 规则尽量数据驱动，不要代码分支爆炸。**
3. **UI 不要拖死战斗主链路，先可用再精细。**
4. **角色运动由属性统一驱动，CMC 只是执行端。**

---

## 八、下一步建议（Day05）

- 把 `Burn/Stun` 从"可用"升级到"可运营"：
  - 抗性（Resistance）
  - 净化（Cleanse Query）
  - Debuff 图标统一管理器
- 同时切入**装备 / 被动系统**：`Infinite GE + Granted Ability`，形成完整战斗构筑链。