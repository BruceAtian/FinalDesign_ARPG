#include "VRGameCharacter.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimInstance.h"
#include "CustomComponets/AudioController.h"
#include "AnimIns/VRGameCharacterAnimInstance.h"
AVRGameCharacter::AVRGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}


void AVRGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	mCharacterAudioController = Cast<UAudioController>(
		this->GetComponentByClass(UAudioController::StaticClass()));

	mCharacterAnimIns = Cast<UVRGameCharacterAnimInstance>(
		this->GetMesh()->GetAnimInstance());

 	if (mCharacterAnimIns)
 	{
		if (mCharacterAudioController)
		{
			mCharacterAnimIns->NotifyPlaySound += [this](FSoundName SoundName) {
				mCharacterAudioController->PlaySoundEffect(SoundName);
			};
		}
 	}
}


void AVRGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AVRGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

