// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float DeltaTime, float Degrees)
{
	Degrees = FMath::Clamp(Degrees, -MaxDegreesPerSecond, MaxDegreesPerSecond);
	float ElevationChange = Degrees * DeltaTime;

	UE_LOG(LogTemp, Warning, TEXT("Clamped Degrees: %f, FrameSmooth: %f"), Degrees, ElevationChange)

	float NewElevation = RelativeRotation.Pitch + ElevationChange;
	NewElevation = FMath::Clamp(NewElevation, MinElevationDegree, MaxElevationDegree);

	UE_LOG(LogTemp, Warning, TEXT("Old Elevation: %f, New Elevation: %f"), RelativeRotation.Pitch, NewElevation)

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
	UE_LOG(LogTemp, Warning, TEXT("Real Rotation: %f"), RelativeRotation.Pitch)
}
