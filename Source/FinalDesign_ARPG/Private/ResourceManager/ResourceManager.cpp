#include "ResourceManager.h"
#include "Engine/World.h"
#include "Components/AudioComponent.h"

AAmbientSound* AResourceManager::CreateSoundInTargetLocation(const FVector& Location, int SoundIndex, bool IsPlayNow)
{
	FTransform Trans;
	Trans.SetLocation(Location);
	AAmbientSound* SoundActor = GetWorld()->SpawnActor<AAmbientSound>(AAmbientSound::StaticClass(), Trans);
	if (SoundActor)
	{
		SoundActor->bAutoDestroyWhenFinished = true;
		if (Sounds.Num() > SoundIndex)
			SoundActor->GetAudioComponent()->SetSound(Sounds[SoundIndex]);
		if (IsPlayNow)
			SoundActor->Play();
	}
	return SoundActor;
}

