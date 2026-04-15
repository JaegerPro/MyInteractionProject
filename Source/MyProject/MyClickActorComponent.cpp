// Fill out your copyright notice in the Description page of Project Settings.


#include "MyClickActorComponent.h"
#include <Components/CanvasPanelSlot.h>
#include <Components/GridSlot.h>
#include "MyPlayerController.h"

// Sets default values for this component's properties
UMyClickActorComponent::UMyClickActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyClickActorComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* Actor = GetOwner();
	UActorComponent* Com = nullptr;
	UComponentSelectorStatics::GetComponentBySelector(Actor, OverlapCompoentSelector, Com);
	ClickComponent = Cast<UShapeComponent>(Com);
	InitIndex();
	// ...
	SetComponentTickEnabled(false);
	if (Actor)
	{
		SetIsReplicated(Actor->GetIsReplicated());
	}
	if (NeedCheck())
	{
		if (ClickComponent)
		{
			ClickComponent->OnComponentBeginOverlap.AddDynamic(this, &UMyClickActorComponent::OnBeginOverlap);
			ClickComponent->OnComponentEndOverlap.AddDynamic(this, &UMyClickActorComponent::OnEndOverlap);
		}
	}
}

void UMyClickActorComponent::UpdateTick()
{
	if (!NeedCheck())
	{
		return;
	}
	if (VaildPC.Num())
	{
		SetComponentTickEnabled(true);
	}
	else
	{
		SetComponentTickEnabled(false);
	}
}

void UMyClickActorComponent::CheckValid(APlayerController* PC, FClickInfo& Info)
{
	if (PC)
	{
		FClick_Param Param;
		Param.Message = Info.ExtraMessage;
		Param.PlayerController = PC;

		FClick_ValidInfo Vaild;
		Vaild.PC = PC;
		Vaild.PassInfo.PassID = Info.ID;
		Vaild.PassInfo.BeginTimeStamp = Info.UIInfo.GlobalCDBeginTimeStamp;
		Vaild.PassInfo.EndTimeStamp = Info.UIInfo.GlobalCDEndTimeStamp;

		if (Info.CheckFunction.Invoke(GetOwner(), Param))
		{
			if (ENetMode::NM_DedicatedServer == GetNetMode())
			{
				AddRepValidInfo(Vaild);
			}
			else
			{
				if (!LocalValidInfo.Contains(Vaild))
				{
					HandleAddButton(Vaild);
				}
			}
		}
		else
		{
			if (ENetMode::NM_DedicatedServer == GetNetMode())
			{
				RemoveRepValidInfo(Vaild);
			}
			else
			{
				if (LocalValidInfo.Contains(Vaild))
				{
					HandleRemoveButton(Vaild);
				}
			}
		}
	}
}

bool UMyClickActorComponent::NeedCheck()
{
	AActor* Actor = GetOwner();
	if (Actor&&Actor->GetIsReplicated())
	{
		return GetNetMode() == ENetMode::NM_DedicatedServer;
	}
	return GetNetMode() == ENetMode::NM_Client;
}


// Called every frame
void UMyClickActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (FClickInfo& Var : ClickButtonInfo)
	{
		for (APlayerController* PC : VaildPC)
		{
			CheckValid(PC, Var);
		}
	}
}

void UMyClickActorComponent::InitIndex()
{
	if (bHaveInitIndex)
	{
		return;
	}

	int32 Index = 1;

	for (FClickInfo& Info : ClickButtonInfo)
	{
		Info.ID = Index++;
	}

	bHaveInitIndex = true;
}

void UMyClickActorComponent::AddRepValidInfo(FClick_ValidInfo& Valid)
{
	if (IClickActorPCInterface* Interface = Cast<IClickActorPCInterface>(Valid.PC))
	{
		Interface->AddRepValidInfo(this, Valid);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::AddRepValidInfo Cast IClickActorPCInterface Failed!!"));
	}
}

void UMyClickActorComponent::RemoveRepValidInfo(FClick_ValidInfo& Valid)
{
	if (IClickActorPCInterface* Interface = Cast<IClickActorPCInterface>(Valid.PC))
	{
		Interface->RemoveRepValidInfo(this, Valid);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::RemoveRepValidInfo Cast IClickActorPCInterface Failed!!"));
	}
}
void UMyClickActorComponent::HandleAddButton(FClick_ValidInfo& Valid)
{
	InitIndex();

	UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);

	APlayerController* PC = Valid.PC;
	if (!PC)
	{
		UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton Failed!! DelayMountWidgets %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);
		return;
	}

	for (int32 i = Widgets.Num() - 1; i >= 0; i--)
	{
		UClickButtonWidget* Var = Widgets[i];
		if (Var && Var->IsEqual(Valid))
		{
#if UE_BUILD_DEVELOPMENT
			UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);
#endif
			return;
		}
	}

	for (FClickInfo& Info : ClickButtonInfo)
	{
		if (Info.ID == Valid.PassInfo.PassID)
		{
			TSubclassOf<UClickButtonWidget> WidgetClass =  Info.UIInfo.ButtonClass;
			if (WidgetClass == nullptr)
			{
				UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton Failed!! WidgetClass is nullptr"));
				return;
			}

			UClickButtonWidget* UserWidget = CreateWidget<UClickButtonWidget>(Valid.PC, WidgetClass);
			if (!UserWidget)
			{
				UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton Failed!! UserWidget is nullptr"));
				return;
			}
			UserWidget->Init(Info.UIInfo, Valid, GetOwner());
			UserWidget->OnClickButton.AddUniqueDynamic(this, &UMyClickActorComponent::OnButtonClick);
			if (!MainWidget)
			{
				MainWidget = CreateWidget<UUserWidget>(Valid.PC, MainWidgetClass);
				MainWidget->AddToViewport();
			}

			UWidget* Widget = MainWidget->GetWidgetFromName(FName(TEXT("VerticalBox")));
			UPanelWidget* Canvas = Cast<UPanelWidget>(Widget);
			if (Canvas)
			{
				Canvas->AddChild(UserWidget);
				UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(UserWidget->Slot);
				if (Slot)
				{
					Slot->SetAutoSize(Info.UIInfo.bAutoSize);
					Slot->SetZOrder(Info.UIInfo.ZOrder);
				}

				if (UGridSlot* pGridPanelSlot = Cast<UGridSlot>(UserWidget->Slot))
				{

					TArray<UWidget*> Children;
					for (int32 i = 0; i < Canvas->GetChildrenCount(); i++)
					{
						if (UWidget* ChildWidget = Canvas->GetChildAt(i))
						{
							Children.Add(ChildWidget);
						}
					}

					for (int32 i = 0; i < Children.Num(); i++)
					{
						if (!Children[i])
						{
							continue;
						}

						if (UGridSlot* pGridPanelSlot1 = Cast<UGridSlot>(Children[i]->Slot))
						{
							pGridPanelSlot1->SetRow(i);
						}
					}
				}
			}
			else
			{
				UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton Failed!! DelayMountWidgets %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);
				return;
			}
			Widgets.Add(UserWidget);
			LocalValidInfo.Add(Valid);
			UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleAddButton Sucess %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);

			return;
		}
	}
}

void UMyClickActorComponent::HandleRemoveButton(FClick_ValidInfo Valid)
{
	UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleRemoveButton %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);
	TArray<UClickButtonWidget*> TmpWidgets = Widgets;
	for (int32 i = TmpWidgets.Num() - 1; i >= 0; i--)
	{
		UClickButtonWidget* Var = Widgets[i];
		if (Var && Var->IsEqual(Valid))
		{
			Var->OnButtonRemove();
			Widgets.Remove(Var);

			UPanelWidget* Canvas = Var->GetParent();
			Var->RemoveFromParent();
			if (Canvas && Cast<UGridSlot>(Var->Slot))
			{
				TArray<UWidget*> Children;
				for (int32 j = 0; j < Canvas->GetChildrenCount(); j++)
				{
					Children.Add(Canvas->GetChildAt(j));
				}

				for (int32 j = 0; j < Children.Num(); j++)
				{
					if (Children[j])
					{
						if (UGridSlot* pGridPanelSlot1 = Cast<UGridSlot>(Children[j]->Slot))
						{
							pGridPanelSlot1->SetRow(j);
						}
					}
				}
			}
			Var->OnClickButton.RemoveAll(this);

			UE_LOG(LogTemp, Log, TEXT("UClickActorComponentBase::HandleRemoveButton Sucess %s %s %d"), GetOwner() ? *GetOwner()->GetFullName() : TEXT("Null"), Valid.PC ? TEXT("Valid") : TEXT("Null"), Valid.PassInfo.PassID);
		}
	}

	LocalValidInfo.Remove(Valid);
}
void UMyClickActorComponent::HandlePCIn(APlayerController* PC)
{
}
void UMyClickActorComponent::HandlePCOut(APlayerController* PC)
{
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		if (IClickActorPCInterface* Interface = Cast<IClickActorPCInterface>(PC))
		{
			Interface->HandleClearValidInfo(this);
		}
	}
	else
	{
		TArray<FClick_ValidInfo> Tmp = LocalValidInfo;

		for (int32 i = Tmp.Num() - 1; i >= 0; i--)
		{
			if (Tmp[i].PC == PC)
			{
				HandleRemoveButton(Tmp[i]);
			}
		}
	}

}
void UMyClickActorComponent::OnButtonClick(FClick_ValidInfo Info)
{

	for (FClickInfo& Var : ClickButtonInfo)
	{
		if (Var.ID == Info.PassInfo.PassID)
		{
			if (Info.PC)
			{
				if (GetNetMode() == ENetMode::NM_Client && !NeedCheck())
				{
					Cast<AMyPlayerController>(Info.PC)->ExcuteClientClickRequest(this, Info.PassInfo.PassID);
				}

				FClick_Param Param;
				Param.Message = Var.ExtraMessage;
				Param.PlayerController = Info.PC;

				if (Var.CheckFunction.Invoke(GetOwner(), Param))
				{
					Var.ExcuteFunction.Invoke(GetOwner(), Param);
				}
			}
			return;
		}
	}

}
void UMyClickActorComponent::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		APlayerController* PC = Cast<APlayerController>(Character->GetController());;
		if (PC)
		{
			VaildPC.AddUnique(PC);
			UpdateTick();
		}
	}
}
void UMyClickActorComponent::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		APlayerController* PC = Cast<APlayerController>(Character->GetController());;
		if (PC)
		{
			VaildPC.Remove(PC);
			HandlePCOut(PC);
			UpdateTick();
		}
	}
}

void UMyClickActorComponent::ExcuteClientClick(APlayerController* PC, int32 ID, bool bCondsiderSafe)
{

	if (bCondsiderSafe && !(VaildPC.Contains(PC) ))
	{
		return;
	}

	for (FClickInfo& Var : ClickButtonInfo)
	{
		if (Var.ID == ID)
		{
			FClick_Param Param;
			Param.Message = Var.ExtraMessage;
			Param.PlayerController = PC;

			if (Var.CheckFunction.Invoke(GetOwner(), Param))
			{
				Var.ExcuteFunction.Invoke(GetOwner(), Param);
			}

		}
	}
}

bool FClick_CheckFunctionName::Invoke(AActor* InActor, FClick_Param& Param)
{
	check(InActor);

	if (!IsValid(InActor))
	{
		return false;
	}

	if (!Function)
	{
		Function = InActor->FindFunction(CustomFunctionName);

		if (!Function)
		{
			return false;
		}

		if (!FClick_CheckFunctionName::IsValidFunction(Function))
		{
			Function = nullptr;
			return false;
		}
	}

	struct TempStruct {
		FClick_Param param;
		bool result = false;
	};

	TempStruct condStruct;
	condStruct.param = Param;
	InActor->ProcessEvent(Function, &condStruct);

	return condStruct.result;
}

bool FClick_CheckFunctionName::IsValidFunction(UFunction* Function)
{
	if (!Function || !Function->HasAnyFunctionFlags(EFunctionFlags::FUNC_BlueprintCallable | EFunctionFlags::FUNC_Event))
	{
		return false;
	}
	int32 BoolReturnValNum = 0;
	int32 ParamNum = 0;

	int32 TotalParamNum = 0;
	int32 TotalRetNum = 0;


	for (TFieldIterator<FProperty> It(Function); It; ++It)
	{
		if (It->PropertyFlags & (CPF_ReturnParm | CPF_OutParm))
		{
			if (FBoolProperty* BoolProperty = CastField<FBoolProperty>(*It))
			{
				++BoolReturnValNum;
			}
			++TotalRetNum;
		}
		else if ((It->PropertyFlags & (CPF_Parm | CPF_ReturnParm)) == CPF_Parm)
		{
			if (FStructProperty* StructProperty = CastField<FStructProperty>(*It))
			{

				UScriptStruct* pfunctionParam = StructProperty->Struct;
				UScriptStruct* pParam = FClick_Param::StaticStruct();
				if (pParam == pfunctionParam && pfunctionParam != nullptr)
				{
					++ParamNum;
				}

			}
			++TotalParamNum;
		}
	}

	return  (TotalParamNum == 1 && ParamNum == 1 && BoolReturnValNum == 1);
}

void FClick_ExecuteFunctionName::Invoke(AActor* InActor, FClick_Param& InParam)
{
	if (!IsValid(InActor))
	{
		return;
	}

	if (!LocalFunction)
	{
		LocalFunction = InActor->FindFunction(CustomFunctionName);
		if (!LocalFunction)
		{
			return;
		}

		if (!FClick_ExecuteFunctionName::IsValidFunction(LocalFunction))
		{
			LocalFunction = nullptr;
			return;
		}
	}

	FClick_Param Param = InParam;
	InActor->ProcessEvent(LocalFunction, &Param);
}

bool FClick_ExecuteFunctionName::IsValidFunction(UFunction* Function)
{
	if (!Function || !Function->HasAnyFunctionFlags(EFunctionFlags::FUNC_BlueprintCallable | EFunctionFlags::FUNC_Event))
	{
		return false;
	}
	int32 BoolReturnValNum = 0;
	int32 ParamNum = 0;

	int32 TotalParamNum = 0;
	int32 TotalRetNum = 0;


	for (TFieldIterator<FProperty> It(Function); It; ++It)
	{
		if (It->PropertyFlags & (CPF_ReturnParm | CPF_OutParm))
		{
			if (FBoolProperty* BoolProperty = CastField<FBoolProperty>(*It))
			{
				++BoolReturnValNum;
			}
			++TotalRetNum;
		}
		else if ((It->PropertyFlags & (CPF_Parm | CPF_ReturnParm)) == CPF_Parm)
		{
			if (FStructProperty* StrucpProperty = CastField<FStructProperty>(*It))
			{

				UScriptStruct* pfunctionParam = StrucpProperty->Struct;
				UScriptStruct* pParam = FClick_Param::StaticStruct();
				if (pParam == pfunctionParam && pfunctionParam != nullptr)
				{
					++ParamNum;
				}

			}
			++TotalParamNum;
		}
	}

	return  (TotalParamNum == 1 && ParamNum == 1 && TotalRetNum == 0);
}

void UClickButtonWidget::Init(const FClickUIInfo& InUIInfo, const FClick_ValidInfo& Info, TWeakObjectPtr <AActor> InWeakOwner)
{
	VaildInfo = Info;
	WeakOwner = InWeakOwner;
	UIInfoLocal = InUIInfo;
	SetRenderOpacity(InUIInfo.RenderOpacity);
	Init_BP(UIInfoLocal);
}

void UClickButtonWidget::OnButtonRemove()
{
	OnButtonRemove_BP();
}
FString FClick_ValidInfo_Rep::ToString() const
{
	FString stringinfo;
	stringinfo.Append(TEXT("OwingActor: "));
	stringinfo.Append(OwingActor ? *OwingActor->GetFullName() : TEXT("NULL"));
	stringinfo.Append(TEXT("Component: "));
	stringinfo.Append(Component ? *Component->GetName() : TEXT("NULL"));
	for (auto& Var : PassInfo)
	{
		stringinfo.Append(TEXT("	PassInfo: "));
		stringinfo.Append(FString::FromInt(Var.PassID));
	}
	return stringinfo;
}

void FClick_ValidInfo_Rep::HandleChange(APlayerController* PC, TArray<FClick_PassInfo>& LocalPassInfo)
{
	if (!IsValid(Component))
	{
		return;
	}


	for (auto& Var : PassInfo)
	{
		bool NeedAddButton = true;
		for (auto& localInfo : LocalPassInfo)
		{
			if (localInfo == Var )
			{
				FClick_ValidInfo Valid;
				Valid.PC = PC;
				Valid.PassInfo = Var;
				NeedAddButton = false;
				break;
			}
		}
		for (const FClickInfo& Tmp : Component->ClickButtonInfo)
		{
			if (Tmp.bAddDynamically && (Var.PassID == Tmp.ID))
			{
				bool bWidgetCreated = false;
				FClick_ValidInfo Valid;
				Valid.PC = PC;
				Valid.PassInfo = Var;
				for (int32 i = 0; i < Component->Widgets.Num(); i++)
				{
					if (Component->Widgets.IsValidIndex(i) && Component->Widgets[i] && Component->Widgets[i]->IsEqual(Valid))
					{
						bWidgetCreated = true;
						break;
					}
				}

				if (!bWidgetCreated)
				{
					NeedAddButton = true;
				}
			}
		}

		if (NeedAddButton)
		{
			FClick_ValidInfo Valid;
			Valid.PC = PC;
			Valid.PassInfo = Var;
			Component->HandleAddButton(Valid);
		}
	}

	for (auto& Var : LocalPassInfo)
	{
		if (!PassInfo.Contains(Var))
		{
			FClick_ValidInfo Valid;
			Valid.PC = PC;
			Valid.PassInfo = Var;
			Component->HandleRemoveButton(Valid);
		}
	}

}

void FClick_ValidInfo_Rep::HandleClear(APlayerController* PC)
{
	if (!IsValid(Component))
	{
		return;
	}

	for (auto& Var : PassInfo)
	{
		FClick_ValidInfo Valid;
		Valid.PC = PC;
		Valid.PassInfo = Var;
		Component->HandleRemoveButton(Valid);
	}
}
