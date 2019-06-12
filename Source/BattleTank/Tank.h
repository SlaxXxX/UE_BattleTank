// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Public/TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* AimingComponent = nullptr;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(class UTankBarrel* Barrel)
	{
		AimingComponent->SetBarrelReference(Barrel);
	}

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(class UTankTurret* Turret)
	{
		AimingComponent->SetTurretReference(Turret);
	}

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector Location)
	{
		AimingComponent->AimAt(Location, LaunchSpeed);
	}
};
