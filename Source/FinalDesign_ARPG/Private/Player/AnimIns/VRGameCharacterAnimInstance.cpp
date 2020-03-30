#include "VRGameCharacterAnimInstance.h"

void UVRGameCharacterAnimInstance::PlayGameSoundEffect(FSoundName SoundName)
{
	NotifyPlaySound(SoundName);
}
