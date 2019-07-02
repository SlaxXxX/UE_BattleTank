// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	void Elevate(float DeltaTime, float Degrees);

private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 5.0;
	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegree = 40.0;
	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegree = 0.0;

};
