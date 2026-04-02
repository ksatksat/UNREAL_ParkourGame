#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingPlatform.generated.h"

UCLASS()
class DE_PHAERQOURE_API ARotatingPlatform : public AActor
{
	GENERATED_BODY()

public:
	ARotatingPlatform();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* PlatformMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* WallMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FRotator RotationVelocity = FRotator(0.0f, 90.0f, 0.0f);

	// This checkbox will control the direction
	UPROPERTY(EditAnywhere, Category = "Movement")
		bool bIsClockwise = true;
};