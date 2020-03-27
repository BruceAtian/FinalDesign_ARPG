#include "VRGameCharacter.h"

AVRGameCharacter::AVRGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}


void AVRGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AVRGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AVRGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

