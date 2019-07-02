// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	void FindAimLocation();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float HitScanDistance = 100000.0;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairXPercent = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYPercent = 0.5;

	class ATank* ControlledTank;
};
