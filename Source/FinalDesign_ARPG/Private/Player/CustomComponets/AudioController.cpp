#include "AudioController.h"

UAudioController::UAudioController()
{

}

bool UAudioController::PlaySoundEffect(FSoundName SoundName)
{
	for (auto& Info : SoundInfos)
	{
		if (Info.SoundName == SoundName && Info.SoundPlayer != nullptr)
		{
			Info.SoundPlayer->SetSound(Info.SoundFile);
			Info.SoundPlayer->Play();
			return true;
		}
	}
	return false;
}

void UAudioController::BeginPlay()
{
	Super::BeginPlay();
	if (CharacterMesh)
	{
		for (auto& SoundInfo : SoundInfos)
		{
			if (SoundInfo.SoundPlayer == nullptr)
			{
				FString ComponentName = SoundInfo.RelativeSocketName.ToString() + "Player";
				SoundInfo.SoundPlayer = CreateDefaultSubobject<UAudioComponent>(FName(*ComponentName));
				SoundInfo.SoundPlayer->SetupAttachment(CharacterMesh, SoundInfo.RelativeSocketName);
				for (auto& Info : SoundInfos)
				{
					if (Info.RelativeSocketName == SoundInfo.RelativeSocketName
						&& Info.SoundPlayer == nullptr)
						Info.SoundPlayer = SoundInfo.SoundPlayer;
				}
			}
		}
	}
}

