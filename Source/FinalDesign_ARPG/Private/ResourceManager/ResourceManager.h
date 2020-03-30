#pragma once

#include "CoreMinimal.h"
#include "core/event.h"
#include "GameDefine.h"
#include "Sound/AmbientSound.h"
#include "ResourceManager.generated.h"

UCLASS()
class AResourceManager : public AActor
{
	GENERATED_BODY()
public:
	AAmbientSound* CreateSoundInTargetLocation(const FVector& Location,int SoundIndex, bool IsPlayNow = false);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<USoundBase*> Sounds;
};