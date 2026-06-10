
#include "ActivitySequenceWrapper.h" 

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
	SequenceActor->AddBinding(Binding, Actor);
}
void FActivitySequenceWrapper::RemoveBinding(const FMovieSceneObjectBindingID& Binding, AActor* Actor)
{
	SequenceActor->RemoveBinding(Binding, Actor);
}
void FActivitySequenceWrapper::StartPlay(float Time)
{
	InitLevelSequencePlayer();
	if (IsValid(Owner))
	{
		if (LevelSequence && SequenceActor)
		{
			if (UMovieScene* MS = LevelSequence->GetMovieScene())
			{
				AActor* OwnerActor = Cast<AActor>(Owner);
				for (int32 i = 0; i < MS->GetPossessableCount(); ++i)
				{
					const FMovieScenePossessable& P = MS->GetPossessable(i);
					if (P.GetPossessedObjectClass() &&
						OwnerActor->GetClass()->IsChildOf(P.GetPossessedObjectClass()))
					{
						SequenceActor->AddBinding(FMovieSceneObjectBindingID(P.GetGuid()), OwnerActor);
					}
				}
			}
		}
		if (Time > 0.f)
		{
			FMovieSceneSequencePlaybackParams Params;
			Params.Frame = FFrameTime::FromDecimal(Time * LevelSequencePlayer->GetFrameRate().AsDecimal());
			Params.UpdateMethod = EUpdatePositionMethod::Jump;
			LevelSequencePlayer->SetPlaybackPosition(Params);
		}
		FTimerHandle TimerHandle;
		Owner->GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
			{
				LevelSequencePlayer->Play();
				UE_LOG(LogTemp, Warning, TEXT("CurrentTime after 1 frame: %f"),
					LevelSequencePlayer->GetCurrentTime().AsSeconds());
			}, 0.1f, false);
			
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