#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyFPSCharacter.generated.h"

UCLASS()
class DE_PHAERQOURE_API AMyFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMyFPSCharacter();
	// Wrapper functions for crouching
	void StartCrouch();
	void StopCrouch();

public:
	// This is the "Camera" our player will look through
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class UCameraComponent* FirstPersonCamera;

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- ADD THESE TWO LINES BELOW ---
	void MoveForward(float Value);
	void MoveRight(float Value);
};