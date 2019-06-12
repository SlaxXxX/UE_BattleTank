// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

#include "Tank.h"
#include "Engine/World.h"
#include "Camera/CameraComponent.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = Cast<ATank>(GetPawn());
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player reporting for dooty, equipped %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player reporting for dooty, where me tank at?"));
	}

}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	FindAimLocation();
}

void ATankPlayerController::FindAimLocation()
{
	if (!ControlledTank) { return; }
	FVector HitLocation = FVector();

	if (GetSightRayHitLocation(HitLocation))
	{
		ControlledTank->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 WidgetLocationX, WidgetLocationY;
	GetViewportSize(WidgetLocationX, WidgetLocationY);

	WidgetLocationX *= CrossHairXPercent;
	WidgetLocationY *= CrossHairYPercent;

	FVector WorldDirection, WorldLocation;

	if (DeprojectScreenPositionToWorld(WidgetLocationX, WidgetLocationY, WorldLocation, WorldDirection))
	{
		FHitResult HitResult;
		FCollisionQueryParams CollisionParameters = FCollisionQueryParams();
		CollisionParameters.AddIgnoredActor(ControlledTank);

		GetWorld()->LineTraceSingleByChannel(HitResult, WorldLocation, WorldLocation + WorldDirection * HitScanDistance, ECollisionChannel::ECC_Visibility, CollisionParameters);

		OutHitLocation = HitResult.Location;
		return HitResult.IsValidBlockingHit();
	}
	return false;
}


