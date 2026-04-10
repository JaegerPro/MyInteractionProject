// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyProjectEditorTool.generated.h"

/**
 * 自定义编辑器工具类
 * 提供常用的编辑器辅助功能
 */
UCLASS(Blueprintable, BlueprintType)
class UMyProjectEditorTool : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * 批量重命名选中的Actor
	 * @param Prefix 名称前缀
	 * @param Suffix 名称后缀
	 * @return 重命名的Actor数量
	 */
	UFUNCTION(BlueprintCallable, Category = "MyProject|Editor")
	static int32 BatchRenameActors(const FString& Prefix, const FString& Suffix);

	/**
	 * 批量移动选中的Actor到指定位置
	 * @param Offset 位置偏移
	 * @return 移动的Actor数量
	 */
	UFUNCTION(BlueprintCallable, Category = "MyProject|Editor")
	static int32 BatchMoveActors(const FVector& Offset);

	/**
	 * 为选中的Actor添加标签
	 * @param TagName 标签名称
	 * @return 添加标签的Actor数量
	 */
	UFUNCTION(BlueprintCallable, Category = "MyProject|Editor")
	static int32 AddTagToSelectedActors(const FName& TagName);

	/**
	 * 获取选中的Actor数量
	 * @return 选中的Actor数量
	 */
	UFUNCTION(BlueprintPure, Category = "MyProject|Editor")
	static int32 GetSelectedActorCount();
};
