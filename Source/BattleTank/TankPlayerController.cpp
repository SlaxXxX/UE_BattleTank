// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	const auto Tank = Cast<ATank>(GetPawn());
	if (Tank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player reporting for dooty, equipped %s"), *Tank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player reporting for dooty, where me tank at?"));
	}
	return Tank;
}