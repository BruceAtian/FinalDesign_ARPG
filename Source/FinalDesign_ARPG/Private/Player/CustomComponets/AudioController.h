#pragma once

#include "components/AudioComponent.h"
#include "components/ActorComponent.h"
#include "components/SkeletalMeshComponent.h"
#include "GameDefine.h"
#include "AudioController.generated.h"

USTRUCT(BlueprintType)
struct FSoundData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName RelativeSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FSoundName SoundName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USoundBase* SoundFile;

	UAudioComponent* SoundPlayer = nullptr;
};


UCLASS(ClassGroup = (CustomComponents), meta = (BlueprintSpawnableComponent))
class  UAudioController : public UActorComponent
{
	GENERATED_BODY()
public:
	UAudioController();

	bool PlaySoundEffect(FSoundName SoundName);

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FSoundData> SoundInfos;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USkeletalMeshComponent* CharacterMesh;
};