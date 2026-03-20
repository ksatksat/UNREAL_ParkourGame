#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class DE_PHAERQOURE_API AMovingPlatform : public AActor
{
	GENERATED_BODY() // Clean and simple! No extra text here.

public:
	AMovingPlatform();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector MoveVelocity = FVector(0.0f, 200.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Movement")
		float MaxDistance = 500.0f;
	// for making it able to make zigzag movement:
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bStartInverted = false;

private:
	FVector StartLocation;
};