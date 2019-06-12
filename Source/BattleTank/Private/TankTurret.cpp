// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/TankTurret.h"

void UTankTurret::Rotate(float DeltaTime, float Degrees)
{
	Degrees = FMath::Clamp(Degrees, -MaxDegreesPerSecond, MaxDegreesPerSecond);
	float RotationChange = Degrees * DeltaTime;

	float NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}
