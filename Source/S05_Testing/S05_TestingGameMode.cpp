// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_TestingGameMode.h"
#include "S05_TestingHUD.h"
#include "S05_TestingCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TestingGameMode::AS05_TestingGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TestingHUD::StaticClass();
}
