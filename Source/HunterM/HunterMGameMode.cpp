// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HunterMGameMode.h"
#include "HunterMHUD.h"
#include "HunterMCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHunterMGameMode::AHunterMGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHunterMHUD::StaticClass();
}
