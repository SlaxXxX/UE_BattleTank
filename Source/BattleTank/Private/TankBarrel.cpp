// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankBarrel.h"

void UTankBarrel::Elevate(float DeltaTime, float Degrees)
{
	Degrees = FMath::Clamp(Degrees, -MaxDegreesPerSecond, MaxDegreesPerSecond);
	float ElevationChange = Degrees * DeltaTime;

	float NewElevation = RelativeRotation.Pitch + ElevationChange;
	NewElevation = FMath::Clamp(NewElevation, MinElevationDegree, MaxElevationDegree);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}
