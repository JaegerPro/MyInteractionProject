// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectEditorTool.h"
#include "Editor.h"
#include "EditorViewportClient.h"
#include "Selection.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"

int32 UMyProjectEditorTool::BatchRenameActors(const FString& Prefix, const FString& Suffix)
{
	int32 RenamedCount = 0;
	
	if (GEditor)
	{
		USelection* SelectedActors = GEditor->GetSelectedActors();
		if (SelectedActors)
		{
			for (FSelectionIterator It(*SelectedActors); It; ++It)
			{
				if (AActor* Actor = Cast<AActor>(*It))
				{
					FString OldName = Actor->GetName();
					FString NewName = Prefix + OldName + Suffix;
					
					Actor->Rename(*NewName);
					RenamedCount++;
				}
			}
		}
	}
	
	return RenamedCount;
}

int32 UMyProjectEditorTool::BatchMoveActors(const FVector& Offset)
{
	int32 MovedCount = 0;
	
	if (GEditor)
	{
		USelection* SelectedActors = GEditor->GetSelectedActors();
		if (SelectedActors)
		{
			for (FSelectionIterator It(*SelectedActors); It; ++It)
			{
				if (AActor* Actor = Cast<AActor>(*It))
				{
					FVector CurrentLocation = Actor->GetActorLocation();
					Actor->SetActorLocation(CurrentLocation + Offset);
					MovedCount++;
				}
			}
		}
	}
	
	return MovedCount;
}

int32 UMyProjectEditorTool::AddTagToSelectedActors(const FName& TagName)
{
	int32 TaggedCount = 0;
	
	if (GEditor)
	{
		USelection* SelectedActors = GEditor->GetSelectedActors();
		if (SelectedActors)
		{
			for (FSelectionIterator It(*SelectedActors); It; ++It)
			{
				if (AActor* Actor = Cast<AActor>(*It))
				{
					Actor->Tags.Add(TagName);
					TaggedCount++;
				}
			}
		}
	}
	
	return TaggedCount;
}

int32 UMyProjectEditorTool::GetSelectedActorCount()
{
	if (GEditor)
	{
		USelection* SelectedActors = GEditor->GetSelectedActors();
		if (SelectedActors)
		{
			return SelectedActors->Num();
		}
	}
	
	return 0;
}
