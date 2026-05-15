// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomNetRelevantComponent.generated.h"

class APawn;
class AActor;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UCustomNetRelevantComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomNetRelevantComponent();

public:	
    /** 把一个 Pawn 加入白名单；加入后会强刷一次相关性，避免要等到下次 IsNetRelevantFor 检查。 */
    UFUNCTION(BlueprintCallable, Category = "NetRelevancy")
    void AddRelevantPawn(APawn* Pawn);

    /** 从白名单移除；同样强刷一次，让对应客户端尽快关闭 Channel。 */
    UFUNCTION(BlueprintCallable, Category = "NetRelevancy")
    void RemoveRelevantPawn(APawn* Pawn);

    UFUNCTION(BlueprintCallable, Category = "NetRelevancy")
    void ClearRelevantPawns();

    /**
     * 宿主 Actor 在自己的 IsNetRelevantFor 里调本函数。
     * @return 当前 Viewer 对应的 Pawn 是否在白名单内。
     *         注意：白名单为空时，默认认为"对所有人不相关"（更保守、更易调试）。
     *         如果你希望"白名单为空 = 对所有人都相关"，把 bDefaultWhenEmpty 改成 true 即可。
     */
    bool IsViewerRelevant(const AActor* RealViewer) const;

protected:
    /**
     * 服务器端白名单。只在服务器使用，不参与属性同步：
     * 客户端没必要知道"还有谁能看到这个 Actor"，且这个 Actor 本身可能就根本没同步到该客户端。
     */
    UPROPERTY(Transient)
    TArray<TWeakObjectPtr<APawn>> RelevantPawns;

    /** 白名单为空时的默认结果。false=不相关（更安全）。 */
    UPROPERTY(EditAnywhere, Category = "NetRelevancy")
    bool bDefaultWhenEmpty = false;

private:
    /**
     * 白名单变化后强刷相关性：
     *   - ForceNetUpdate：让宿主 Actor 在本次 ServerTick 内立即被考虑同步。
     *   - ForceUpdateRelevancy：对每个 Connection 立刻重算 IsNetRelevantFor，
     *     新加入白名单的 Pawn 不用等下一次定时检查就能拿到 Channel；
     *     被移除的 Pawn 对应 Channel 会在不相关后被关闭。
     */
    void RefreshRelevancyForAllConnections();
		
};
