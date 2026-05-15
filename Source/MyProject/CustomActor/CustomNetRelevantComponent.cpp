// Demo: 自定义网络相关性组件实现

#include "CustomNetRelevantComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "Engine/NetConnection.h"
#include "Engine/NetDriver.h"
#include "Engine/ActorChannel.h"

UCustomNetRelevantComponent::UCustomNetRelevantComponent()
{
    // 本组件不需要 Tick，也不需要把组件本身复制到客户端。
    // 白名单只在服务器使用，整组件相当于"服务器侧的小工具"。
    PrimaryComponentTick.bCanEverTick = false;
    SetIsReplicatedByDefault(false);
}

void UCustomNetRelevantComponent::AddRelevantPawn(APawn* Pawn)
{
    // 客户端调用本接口没有意义（白名单只在服务器读），直接挡掉避免误用。
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    if (!Pawn)
    {
        return;
    }

    // 用 weak ptr 装，避免 Pawn 销毁后这里残留野指针；同时 Contains 比较时按 raw 指针即可。
    const TWeakObjectPtr<APawn> Weak(Pawn);
    if (RelevantPawns.Contains(Weak))
    {
        return;
    }
    RelevantPawns.Add(Weak);

    // 关键：白名单变了必须立刻刷一次，否则要等到 NetDriver 下一次相关性轮询，
    // 视觉上会出现"加入白名单后过几秒才看到 Actor"的延迟。
    RefreshRelevancyForAllConnections();
}

void UCustomNetRelevantComponent::RemoveRelevantPawn(APawn* Pawn)
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    if (!Pawn)
    {
        return;
    }

    const int32 Removed = RelevantPawns.Remove(TWeakObjectPtr<APawn>(Pawn));
    if (Removed > 0)
    {
        // 移除后同样刷一次：让被踢出的客户端尽快关掉这个 Actor 的 Channel。
        RefreshRelevancyForAllConnections();
    }
}

void UCustomNetRelevantComponent::ClearRelevantPawns()
{
    if (!GetOwner() || !GetOwner()->HasAuthority())
    {
        return;
    }
    if (RelevantPawns.Num() == 0)
    {
        return;
    }
    RelevantPawns.Empty();
    RefreshRelevancyForAllConnections();
}

bool UCustomNetRelevantComponent::IsViewerRelevant(const AActor* RealViewer) const
{
    // 白名单为空时按可配置默认值返回。把这个判断放在最前面，
    // 这样调试时清空白名单就能快速切换"全部隐藏/全部可见"两种行为。
    if (RelevantPawns.Num() == 0)
    {
        return bDefaultWhenEmpty;
    }

    // RealViewer 在大多数情况下是 PlayerController（参考 AActor::IsNetRelevantFor 的标准调用链），
    // 我们要从它身上拿到 Pawn 再去白名单里查。
    const APlayerController* PC = Cast<APlayerController>(RealViewer);
    if (!PC)
    {
        // 也可能 RealViewer 直接就是个 Pawn（部分场景/相机视角），兼容一下。
        if (const APawn* PawnViewer = Cast<APawn>(RealViewer))
        {
            return RelevantPawns.Contains(TWeakObjectPtr<APawn>(const_cast<APawn*>(PawnViewer)));
        }
        return bDefaultWhenEmpty;
    }

    APawn* ViewerPawn = PC->GetPawn();
    if (!ViewerPawn)
    {
        // PC 还没 Possess Pawn（比如刚进服那一帧）。这种情况下保守返回 false：
        // 等它 Possess 之后下一次相关性检查会被自动重新评估。
        return false;
    }

    return RelevantPawns.Contains(TWeakObjectPtr<APawn>(ViewerPawn));
}

void UCustomNetRelevantComponent::RefreshRelevancyForAllConnections()
{
    AActor* Owner = GetOwner();
    if (!Owner)
    {
        return;
    }

    UWorld* World = Owner->GetWorld();
    if (!World)
    {
        return;
    }

    UNetDriver* NetDriver = World->GetNetDriver();
    if (!NetDriver)
    {
        // 单机或还没建立网络环境，直接跳过即可：本组件在那种情况下也不会被查询。
        return;
    }

    // 1) 标记 Owner 需要立即被同步评估。仅这一步还不够：
    //    ForceNetUpdate 只是把"下一次 ServerReplicateActors 优先考虑我"，
    //    但相关性本身可能仍被缓存为 false，所以还需要 ForceUpdateRelevancy。
    Owner->ForceNetUpdate();

    // 2) 对所有连接强制重算相关性。这里不区分"加入还是移除"，统一刷。
    //    项目原版还会顺带遍历 GetAttachedActors 一并刷子 Actor，demo 暂不做：
    //    保持 demo 聚焦在"白名单"主线上，子 Actor 联动可以作为后续扩展。
    for (UNetConnection* Conn : NetDriver->ClientConnections)
    {
        if (!Conn)
        {
            continue;
        }
        if (UActorChannel* Channel = Conn->FindActorChannelRef(Owner))
        {
            Channel->RelevantTime = 0.f;
        }
    }
}
