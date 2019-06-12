// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	FindMyTanks();
	if (ControlledTank && PlayerControlledTank)
	{
		ControlledTank->AimAt(PlayerControlledTank->GetActorLocation());
	}
}

void ATankAIController::FindMyTanks()
{
	ControlledTank = Cast<ATank>(GetPawn());
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI reporting for dooty, equipped %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI reporting for dooty, lost my tank tho.."));
	}

	PlayerControlledTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI now aiming on %s"), *PlayerControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI lost the Player in the fog"));
	}
}
