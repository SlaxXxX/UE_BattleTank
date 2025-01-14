// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

protected:
	void Tick(float DeltaSeconds) override;

private:
	void FindMyTanks();
	class ATank* ControlledTank;
	ATank* PlayerControlledTank;
};
