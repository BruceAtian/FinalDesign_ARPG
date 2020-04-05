#pragma once

#include "CoreMinimal.h"
#include "Player/VRGameCharacter.h"
#include "VRGamePlayer.generated.h"

UCLASS()
class AVRGamePlayer : public AVRGameCharacter
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SwitchCharacterCamera();

protected:


private:
	bool bIsFirstView = false;
};
