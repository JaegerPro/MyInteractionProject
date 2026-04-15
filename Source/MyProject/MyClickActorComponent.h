// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/PanelWidget.h"
#include "GameFramework/Character.h"
#include "CustomActor/CustomTypeDefine.h"
#include "Blueprint/UserWidget.h"
#include "MyClickActorComponent.generated.h"

class UClickButtonWidget;

USTRUCT(BlueprintType)
struct FClick_PassInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	int32 PassID;

	UPROPERTY(BlueprintReadWrite)
	float BeginTimeStamp = -1;

	UPROPERTY(BlueprintReadWrite)
	float EndTimeStamp = -1;

	bool operator==(const FClick_PassInfo& Info)const
	{
		return Info.PassID == PassID;
	}

	bool IsNeedResetGlobalCD(const FClick_PassInfo& Info) const
	{
		if (Info.PassID != PassID)
		{
			// 这边check一下， 理论上判断的时候 PassID是相等的
			check(0);
			return false;
		}

		if (Info.BeginTimeStamp != BeginTimeStamp || Info.EndTimeStamp != EndTimeStamp)
		{
			return true;
		}

		return false;
	}
};

USTRUCT(BlueprintType)
struct  FClick_ValidInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	APlayerController* PC = nullptr;

	UPROPERTY(BlueprintReadWrite)
	FClick_PassInfo PassInfo;

	bool operator==(const FClick_ValidInfo& Info)const
	{
		return Info.PC == PC && Info.PassInfo == PassInfo;
	}

	bool IsNeedResetGlobalCD(const FClick_ValidInfo& Info)const
	{
		if (Info.PC != PC || Info.PassInfo.PassID != PassInfo.PassID)
		{
			return false;
		}

		return PassInfo.IsNeedResetGlobalCD(Info.PassInfo);
	}
};

USTRUCT(BlueprintType)
struct FClickUIInfo
{
	GENERATED_BODY()

	//是否对条件取非
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FName ButtonName = TEXT("Click");

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UTexture2D* ButtonUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Config")
	FString  MountWidgetName = TEXT("VerticalBox_GISVerticalContainer");

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float ClientCD = -1;

	//需要长按的时间
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float PressureTime = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category = "Config")
	TSoftClassPtr<UUserWidget> OuterClass = nullptr;

	UPROPERTY(EditAnywhere, Category = "Layout|Canvas Slot", AdvancedDisplay, meta = (DisplayName = "Size To Content"))
	bool bAutoSize = false;

	/** The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top). */
	UPROPERTY(EditAnywhere, Category = "Layout|Canvas Slot")
	int32 ZOrder = 0;

	/** The order priority this widget is rendered in.  Higher values are rendered last (and so they will appear to be on top). */
	UPROPERTY(EditAnywhere, Category = "Config")
	int32 SortOrder = 0;

	//不配就是默认class，配了为重载的class
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UClickButtonWidget> ButtonClass;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString ExtraMessage;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float RenderOpacity = 1.0f;

	// 全局CD结束时间戳
	UPROPERTY(BlueprintReadWrite)
	float GlobalCDEndTimeStamp = -1;

	UPROPERTY(BlueprintReadWrite)
	float GlobalCDBeginTimeStamp = -1;

	// 默认情况下 按钮音效在 0,0,0 ，在使用AKRoom 的情况下可能会导致听不到声音
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool BisPostEventAtPlayerLocation = false;

};

USTRUCT(BlueprintType)
struct  FClick_Param
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	APlayerController* PlayerController = nullptr;

	UPROPERTY(BlueprintReadWrite)
	FString Message;
};

USTRUCT(BlueprintType)
struct FClick_CheckFunctionName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	FName CustomFunctionName;

	bool Invoke(AActor* InActor, FClick_Param& Param);

	UPROPERTY(Transient)
	UFunction* Function = nullptr;

	MYPROJECT_API static bool IsValidFunction(UFunction* Function);
};

USTRUCT(BlueprintType)
struct FClick_ExecuteFunctionName
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	FName CustomFunctionName;

	void Invoke(AActor* InActor, FClick_Param& Param);

	UPROPERTY(Transient)
	UFunction* LocalFunction = nullptr;

	MYPROJECT_API static bool IsValidFunction(UFunction* Function);
};
USTRUCT(BlueprintType)
struct FClickInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FClick_CheckFunctionName CheckFunction;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FClick_ExecuteFunctionName ExcuteFunction;
	//是否对条件取非
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FClickUIInfo UIInfo;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FString ExtraMessage;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float GlobalCD = -1;

	UPROPERTY(BlueprintReadWrite)
	int32 ID;

	UPROPERTY(BlueprintReadWrite)
	int32 TlogID = -1;

	UPROPERTY(BlueprintReadWrite)
	bool bAddDynamically = false;
};
USTRUCT()
struct FClick_ValidInfo_Rep
{
	GENERATED_BODY()

public:
	UPROPERTY()
	AActor* OwingActor = nullptr;

	UPROPERTY()
	UMyClickActorComponent* Component;

	UPROPERTY()
	TArray<FClick_PassInfo> PassInfo;

	void HandleChange(APlayerController* PC, TArray<FClick_PassInfo>& PassInfo);

	void HandleClear(APlayerController* PC);

	FString ToString() const;
};
UINTERFACE(BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class UClickActorPCInterface : public UInterface
{
	GENERATED_BODY()
};

class  IClickActorPCInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AddRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& Vaild) {};
	virtual void RemoveRepValidInfo(UMyClickActorComponent* Compoent, FClick_ValidInfo& Vaild) {};
	virtual void HandleClearValidInfo(UMyClickActorComponent* Compoent) {};
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UMyClickActorComponent : public UActorComponent
{
	GENERATED_BODY()

	friend struct FClick_ValidInfo_Rep;
	friend class  UClickButtonWidget;
public:	
	// Sets default values for this component's properties
	UMyClickActorComponent();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	UPROPERTY()
	TArray<APlayerController*> VaildPC;

private:
	UUserWidget* MainWidget = nullptr;
	bool bHaveInitIndex = false;
	UPROPERTY()
	TArray<FClick_ValidInfo> LocalValidInfo;
	UPROPERTY()
	TArray<UClickButtonWidget*> Widgets;
private:
	void InitIndex();
	void AddRepValidInfo(FClick_ValidInfo& Vaild);
	void RemoveRepValidInfo(FClick_ValidInfo& Vaild);
	void HandleAddButton(FClick_ValidInfo& Valid);
	void HandleRemoveButton(FClick_ValidInfo Valid);
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UUserWidget> MainWidgetClass;
	UPROPERTY()
	UShapeComponent* ClickComponent;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (InteractionButton))
	TArray<FClickInfo> ClickButtonInfo;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FShapeComponentSelector OverlapCompoentSelector;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void UpdateTick();
	void CheckValid(APlayerController* PC, FClickInfo& Info);
	bool NeedCheck();
	void HandlePCIn(APlayerController* PC);
	void HandlePCOut(APlayerController* PC);
	UFUNCTION(BlueprintCallable)
	void OnButtonClick(FClick_ValidInfo Info);
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
public:
	void ExcuteClientClick(APlayerController* PC, int32 ID, bool bCondsiderSafe = false);
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickButton, FClick_ValidInfo, Info);

UCLASS()
class  UClickButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void Init(const FClickUIInfo& InUIInfo, const FClick_ValidInfo& Info, const TWeakObjectPtr<class AActor> InWeakOwner);

	UFUNCTION(BlueprintImplementableEvent)
	void Init_BP(const FClickUIInfo& UIInfo);

	virtual void OnButtonRemove();

	UFUNCTION(BlueprintImplementableEvent)
	void OnButtonRemove_BP();

	bool IsEqual(const FClick_ValidInfo& Info) { return VaildInfo == Info; }

	UFUNCTION(BlueprintCallable)
	AActor* GetOwner() { return WeakOwner.Get(); }

	const FClick_ValidInfo& GetValidInfo() { return VaildInfo; }

	const FClickUIInfo& GetClickUIInfo() { return UIInfoLocal; }

public:
	UPROPERTY(BlueprintCallable, BlueprintReadWrite, BlueprintAssignable)
	FOnClickButton OnClickButton;
protected:

protected:
	int32 CallID = -1;

	UPROPERTY(BlueprintReadWrite)
	FClick_ValidInfo VaildInfo;

	UPROPERTY()
	TWeakObjectPtr<class AActor> WeakOwner;

	UPROPERTY()
	FClickUIInfo UIInfoLocal;
};
