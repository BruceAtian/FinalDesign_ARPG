#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "core/event.h"
#include "GameDefine.h"
#include "VRGameCharacterAnimInstance.generated.h"


UCLASS()
class UVRGameCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	core::event<void(FSoundName)> NotifyPlaySound;

protected:
	UFUNCTION(BlueprintCallable)
	void PlayGameSoundEffect(FSoundName SoundName);
	
};
