// Copyright Epic Games, Inc. All Rights Reserved.

#include "MutiplayerGameMode.h"
#include "MutiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMutiplayerGameMode::AMutiplayerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
