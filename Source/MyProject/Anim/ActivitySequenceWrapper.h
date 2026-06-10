// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelSequencePlayer.h"
#include "LevelSequenceActor.h"
#include "ActivitySequenceWrapper.generated.h"
/**
 * 
 */
USTRUCT()
struct FActivitySequenceWrapper
{
	GENERATED_BODY()

	FActivitySequenceWrapper();

	void Init(UObject* Owner);

	void ChangeSequence();

	void ChangeSequence(ULevelSequence* Sequence);

	FString GetCurrentName();

	void InitLevelSequencePlayer();

	void AddBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor);

	void RemoveBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor);

	void StartPlay(float Time);
	void Stop();
	ULevelSequencePlayer* GetLevelSequencePlayer() { return LevelSequencePlayer; }
private:

	UPROPERTY(Transient)
	ULevelSequencePlayer* LevelSequencePlayer;

	UPROPERTY(Transient)
	UObject* Owner;
	FTransform LevelSequenceTransformOrign;
	UPROPERTY(Transient)
	ULevelSequence* LevelSequence;
	UPROPERTY(Transient)
	TObjectPtr<ALevelSequenceActor> SequenceActor = nullptr;
};