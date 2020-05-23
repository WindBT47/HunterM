// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HunterMGameMode.h"
#include "HunterMHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHunterMGameMode::AHunterMGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behaviour/GuardActor"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHunterMHUD::StaticClass();
}
