// Copyright Epic Games, Inc. All Rights Reserved.

#include "Traces2GameMode.h"
#include "Traces2Character.h"
#include "UObject/ConstructorHelpers.h"

ATraces2GameMode::ATraces2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
