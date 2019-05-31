// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();
	GetPlayerControlledTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	auto Tank = Cast<ATank>(GetPawn());
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI reporting for dooty, equipped %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI reporting for dooty, lost my tank tho.."));
	}
	return Tank;
}

ATank* ATankAIController::GetPlayerControlledTank() const
{
	const auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI now aiming on %s"), *PlayerPawn->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI lost the Player in the fog"));
	}
	return PlayerPawn;
}
