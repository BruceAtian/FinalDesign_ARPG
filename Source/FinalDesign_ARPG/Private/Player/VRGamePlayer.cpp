#include "VRGamePlayer.h"
#include "components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/GameEngine.h"

void AVRGamePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVRGamePlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("SwitchFVCamera", IE_Pressed, this, &AVRGamePlayer::SwitchCharacterCamera);
}

void AVRGamePlayer::SwitchCharacterCamera()
{
	TArray<UActorComponent*> Cameras = this->GetComponentsByClass(UCameraComponent::StaticClass());
	APlayerController* Player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GEngine->AddOnScreenDebugMessage(1, 4, FColor::Blue, FString("SwitchCamera"));
	if (bIsFirstView)
	{
		Cameras[1]->bIsActive = false;
		Cameras[0]->bIsActive = true;
		bIsFirstView = !bIsFirstView;
	}
	else
	{
		Cameras[0]->bIsActive = false;
		Cameras[1]->bIsActive = true;
		bIsFirstView = !bIsFirstView;
	}
}
