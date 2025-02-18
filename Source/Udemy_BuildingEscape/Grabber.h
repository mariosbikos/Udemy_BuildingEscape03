// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SetupPhysicsHandle();

	void SetupInputComponent();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector GetReachLineEnd();

	FVector GetReachLineStart();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Reach = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPhysicsHandleComponent* PhysicsHandle=nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UInputComponent* InputComponent = nullptr;
private:
	void Grab();
	void Release();
	FHitResult GetFirstPhysicsBodyInReach();
};
