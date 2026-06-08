// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "AbilitySystemComponent.h"
#include "GAS/GASLearnGameplayAbility.h"
#include "GAS/GASLearnGameplayTags.h"
#include "GameplayTagContainer.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CustomActor/CustomNetRelevantInterface.h"
#include <Net/UnrealNetwork.h>

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicateUsingRegisteredSubObjectList = true;
	StateComponent = CreateDefaultSubobject<UPawnStateComponent>(TEXT("PawnStateComponent"));
	PersistComponent = CreateDefaultSubobject<UPersistBaseComponent>(TEXT("PersistComponent"));
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);                                      // 开启网络同步
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);  // 混合模式：自己的 Effect 全同步，别人的只同步 GameplayCue/Tag

	// 创建 AttributeSet（不是组件，是普通 UObject，但必须是 ASC 所在 Actor 的 SubObject）
	AttributeSet = CreateDefaultSubobject<UGASLearnAttributeSet>(TEXT("AttributeSet"));

	HealthBarWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarWidgetComp"));
	HealthBarWidgetComp->SetupAttachment(GetMesh()); // 或 RootComponent，看你想不想跟动画
	HealthBarWidgetComp->SetRelativeLocation(FVector(0.f, 0.f, 220.f)); // 头顶上方
	HealthBarWidgetComp->SetWidgetSpace(EWidgetSpace::Screen);          // 永远面向相机
	HealthBarWidgetComp->SetDrawSize(FVector2D(180.f, 24.f));
	HealthBarWidgetComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AMyCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

void AMyCharacter::AddCustomNetRelevantInterface(TScriptInterface<ICustomNetRelevantInterface> Interface)
{
	 if (Interface)
	{
		AddtiveCustomNetRelevant.Add(Interface);
		Interface->OnRegisterTo(this);
	}
}

void AMyCharacter::RemoveCustomNetRelevantInterface(TScriptInterface<ICustomNetRelevantInterface> Interface)
{
	if (Interface)
	{
		AddtiveCustomNetRelevant.Remove(Interface);
		Interface->OnUnRegisterTo(this);
	}
}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
void AMyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	// 服务器端初始化
	InitAbilitySystem();
}

void AMyCharacter::OnAbility1Pressed()
{
	if (AbilitySystemComponent)
	{
		// 这个函数告诉 ASC："ID = Ability1 的 Ability 被按下了"
		// ASC 会自动找到绑定到这个 ID 的 Ability 并激活
		AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EGASLearnAbilityInputID::Ability1));
	}
}

void AMyCharacter::OnAbility1Released()
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EGASLearnAbilityInputID::Ability1));
	}
}
void AMyCharacter::OnAbility2Pressed()
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AbilityLocalInputPressed(static_cast<int32>(EGASLearnAbilityInputID::Ability2));
	}
}

void AMyCharacter::OnAbility2Released()
{
	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->AbilityLocalInputReleased(static_cast<int32>(EGASLearnAbilityInputID::Ability2));
	}
}
void AMyCharacter::OnCancelPressed()
{
	if (!AbilitySystemComponent) return;
	// 优先取消 Targeting
	AbilitySystemComponent->LocalInputCancel();
	// 取消所有带 Ability.Fireball 标签的 Ability
	FGameplayTagContainer CancelTags(GASTags::Ability_Fireball);
	AbilitySystemComponent->CancelAbilities(&CancelTags);
}
void AMyCharacter::OnStunTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if (UCharacterMovementComponent* MoveComp = GetCharacterMovement())
	{
		if (NewCount > 0)
		{
			MoveComp->StopMovementImmediately();
			MoveComp->DisableMovement();
		}
		else
		{
			MoveComp->SetMovementMode(MOVE_Walking);
		}
	}
}

void AMyCharacter::GiveDefaultAbilities()
{
	// 只在服务器授予（Ability 会自动同步到客户端）
	if (!HasAuthority() || !AbilitySystemComponent) return;

	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		if (!AbilityClass) continue;

		// 如果是我们的基类，读 AbilityInputID
		int32 InputID = INDEX_NONE;
		if (UGASLearnGameplayAbility* CDO = Cast<UGASLearnGameplayAbility>(AbilityClass->GetDefaultObject()))
		{
			InputID = static_cast<int32>(CDO->AbilityInputID);
		}
		// InputID 用 -1 表示不绑定输入（后面我们用 Tag 触发）
		FGameplayAbilitySpec Spec(AbilityClass, /*Level=*/1, InputID, this);
		AbilitySystemComponent->GiveAbility(Spec);
	}
}

void AMyCharacter::InitAbilitySystem()
{
	if (!AbilitySystemComponent || !AttributeSet) return;

	if (AbilitySystemComponent)
	{
		// OwnerActor 和 AvatarActor 都是自己
		// OwnerActor = 逻辑所有者（比如 PlayerState）
		// AvatarActor = 世界里的物理载体（Pawn）
		// 本课简化：都传 this
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		// 初始化完 ASC 后，立即应用默认属性 Effect
		ApplyInitialEffects();
		GiveDefaultAbilities();  
		if (!bInitAbilitySystem)
		{
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute())
				.AddLambda([this](const FOnAttributeChangeData&) { RefreshHealthBar(); });
			AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
				UGASLearnAttributeSet::GetMaxHealthAttribute())
				.AddLambda([this](const FOnAttributeChangeData&) { RefreshHealthBar(); });
			AbilitySystemComponent->RegisterGameplayTagEvent(GASTags::State_Debuff_Stun, EGameplayTagEventType::NewOrRemoved)
				.AddUObject(this, &AMyCharacter::OnStunTagChanged);
			AbilitySystemComponent->RegisterGameplayTagEvent(GASTags::State_Debuff_Burn, EGameplayTagEventType::AnyCountChange)
				.AddUObject(this, &AMyCharacter::OnBurnTagChanged);
			bInitAbilitySystem = true;
		}
		RefreshHealthBar();
	}
}
void AMyCharacter::RefreshHealthBar()
{
	if (!HealthBarWidgetComp || !AttributeSet) return;

	// 懒加载拿到 UserWidget 实例
	if (!HealthBarWidget)
	{
		HealthBarWidget = Cast<UHealthBarWidget>(HealthBarWidgetComp->GetUserWidgetObject());
	}
	if (!HealthBarWidget) return;

	HealthBarWidget->SetHealthPercent(
		AttributeSet->GetHealth(),
		AttributeSet->GetMaxHealth());
}
void AMyCharacter::OnBurnTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	if (!AbilitySystemComponent || !HealthBarWidget) return;

	const FGameplayEffectQuery Query = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(FGameplayTagContainer(GASTags::State_Debuff_Burn));

	float MaxRemain = 0.f;

	TArray<float> Remains = AbilitySystemComponent->GetActiveEffectsTimeRemaining(Query);
	for (float T : Remains)
	{
		MaxRemain = FMath::Max(MaxRemain, T);
	}

	HealthBarWidget->SetBurnInfo(NewCount, MaxRemain);
}

void AMyCharacter::ApplyInitialEffects()
{
	if (!AbilitySystemComponent || !DefaultAttributesEffect) return;

	// 创建一个 EffectContext，记录"谁施加了这个 Effect"
	FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
	ContextHandle.AddSourceObject(this);

	// 生成 Spec（Effect 的"实例"，Effect 类是模板，Spec 才是运行时的数据）
	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		DefaultAttributesEffect,
		/*Level=*/ 1.f,
		ContextHandle);

	if (SpecHandle.IsValid())
	{
		// 对自己应用这个 Effect
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}
void AMyCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// 客户端初始化（本课暂时不涉及 PlayerState，预留）
	InitAbilitySystem();
}
// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (HealthBarWidgetComp && HealthBarWidgetClass)
	{
		HealthBarWidgetComp->SetWidgetClass(HealthBarWidgetClass);
		HealthBarWidgetComp->InitWidget(); // 立即实例化 UserWidget
	}

	RefreshHealthBar();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
bool AMyCharacter::IsNetRelevantFor(const AActor* RealViewer, const AActor* ViewTarget, const FVector& SrcLocation) const
{
	bool Ret = Super::IsNetRelevantFor(RealViewer, ViewTarget, SrcLocation);
	for (const TScriptInterface<ICustomNetRelevantInterface>& Var : AddtiveCustomNetRelevant)
	{
		if (Var.GetObject())
		{
			Ret = (Ret && Var->IsNetRelevantFor(RealViewer, ViewTarget, SrcLocation, this));
		}
	}
	return Ret;
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// ... 模板原有的移动/跳跃绑定 ...

		if (Ability1Action)
		{
			EIC->BindAction(Ability1Action, ETriggerEvent::Started, this, &AMyCharacter::OnAbility1Pressed);
			EIC->BindAction(Ability1Action, ETriggerEvent::Completed, this, &AMyCharacter::OnAbility1Released);
		}
		if (Ability2Action)
		{
			EIC->BindAction(Ability2Action, ETriggerEvent::Started, this, &AMyCharacter::OnAbility2Pressed);
			EIC->BindAction(Ability2Action, ETriggerEvent::Completed, this, &AMyCharacter::OnAbility2Released);
		}
		if (CancelAction)
		{
			EIC->BindAction(CancelAction, ETriggerEvent::Started, this, &AMyCharacter::OnCancelPressed);
		}
		if (ConfirmAction)
		{
			EIC->BindAction(ConfirmAction, ETriggerEvent::Started, this, &AMyCharacter::OnConfirmPressed);
		}
	}
}
void AMyCharacter::OnConfirmPressed()
{
	if (AbilitySystemComponent)
	{
		// 这一行就是 Target Actor 在等的信号
		AbilitySystemComponent->LocalInputConfirm();
	}
}

void AMyCharacter::Jump()
{
	Super::Jump();
	StateComponent->EnterState(EPawnState::Jump);
}

void AMyCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	StateComponent->LeaveState(EPawnState::Jump);
}

