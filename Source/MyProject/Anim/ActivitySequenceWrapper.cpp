
#include "ActivitySequenceWrapper.h" 
#include <MyProject/MyActivityActor.h>

FActivitySequenceWrapper::FActivitySequenceWrapper()
{
}

void FActivitySequenceWrapper::Init(UObject* InOwner)
{
	check(InOwner);
	Owner = InOwner;
	InitLevelSequencePlayer();
}

void FActivitySequenceWrapper::ChangeSequence()
{
	LevelSequence = nullptr;
}
void FActivitySequenceWrapper::ChangeSequence(ULevelSequence* Sequence)
{
	LevelSequence = Sequence;
}
FString FActivitySequenceWrapper::GetCurrentName()
{
	FString Ret = TEXT("Null");

	if (LevelSequence)
	{
		Ret = FString::Printf(TEXT("LevelSequence_%s"), *LevelSequence->GetName());
	}

	return Ret;
}
void FActivitySequenceWrapper::InitLevelSequencePlayer()
{
	if (!LevelSequence)
	{
		return;
	}
	if (LevelSequencePlayer)
	{
		return;
	}
	FMovieSceneSequencePlaybackSettings Settings;
	ALevelSequenceActor* OutActor = nullptr;
	LevelSequencePlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(
		Owner->GetWorld(), LevelSequence, Settings, OutActor);
	SequenceActor = OutActor;
}
void FActivitySequenceWrapper::AddBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor)
{
	if (SequenceActor)
	{
		SequenceActor->AddBinding(Binding, Actor);
	}
}
void FActivitySequenceWrapper::RemoveBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor)
{
	if (SequenceActor)
	{
		SequenceActor->RemoveBinding(Binding, Actor);
	}
}
bool FActivitySequenceWrapper::GetCurrentSequenceIsEnd()
{
	if (LevelSequence)
	{
		InitLevelSequencePlayer();
		return !(LevelSequencePlayer->IsPlaying() || LevelSequencePlayer->IsPaused());
	}

	return true;
}
void FActivitySequenceWrapper::StartPlay(float Time)
{
	if (!LevelSequence)
	{
		UE_LOG(LogTemp, Warning, TEXT("StartPlay: LevelSequence is null, skipping"));
		return;
	}

	InitLevelSequencePlayer();
	if (IsValid(Owner))
	{
		if (LevelSequence && SequenceActor)
		{
			if (UMovieScene* MS = LevelSequence->GetMovieScene())
			{
				AMyActivityActor* OwnerActor = Cast<AMyActivityActor>(Owner);
				for (int32 i = 0; i < MS->GetPossessableCount(); ++i)
				{
					const FMovieScenePossessable& P = MS->GetPossessable(i);
					if (P.GetPossessedObjectClass() &&
						OwnerActor->GetClass()->IsChildOf(P.GetPossessedObjectClass()))
					{
						SequenceActor->AddBinding(FMovieSceneObjectBindingID(P.GetGuid()), OwnerActor);
					}
				}
				OwnerActor->OnSequenceLoaded();
			}
			if (Time > 0.f)
			{
				FMovieSceneSequencePlaybackParams Params;
				Params.Frame = FFrameTime::FromDecimal(Time * LevelSequencePlayer->GetFrameRate().AsDecimal());
				Params.UpdateMethod = EUpdatePositionMethod::Jump;
				LevelSequencePlayer->SetPlaybackPosition(Params);
			}
			LevelSequencePlayer->Play();
		}
	}
}

void FActivitySequenceWrapper::Stop()
{
	if (LevelSequencePlayer)
	{
		LevelSequencePlayer->Stop();
		LevelSequencePlayer = nullptr;
	}
	if (SequenceActor)
	{
		SequenceActor->Destroy();
		SequenceActor = nullptr;
	}
}