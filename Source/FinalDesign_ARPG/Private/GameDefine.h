#pragma once

#include "CoreMinimal.h"

struct PlayerCharacterInitInfo
{
	FTransform Trans;
};

UENUM(BlueprintType)
enum class FSoundName : uint8
{
	Idle = 0,
	Attack = 1,
	Death = 2,
};


