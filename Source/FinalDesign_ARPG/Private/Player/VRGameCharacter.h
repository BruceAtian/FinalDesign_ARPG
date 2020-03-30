#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameDefine.h"
#include "VRGameCharacter.generated.h"

class UAudioController;
class UVRGameCharacterAnimInstance;

UCLASS()
class AVRGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AVRGameCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UAudioController* mCharacterAudioController = nullptr;

	UVRGameCharacterAnimInstance* mCharacterAnimIns = nullptr;
};
