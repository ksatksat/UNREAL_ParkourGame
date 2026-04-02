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
	// 
	void StartCrouch();
	void StopCrouch();

public:
	// 
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		class UCameraComponent* FirstPersonCamera;

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//
	void MoveForward(float Value);
	void MoveRight(float Value);
};