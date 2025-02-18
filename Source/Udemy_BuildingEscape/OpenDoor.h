// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenDoorRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();
	class AActor* ActorOwner;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	float GetTotalMassOfActorsOnPlate();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float OpenAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ATriggerVolume* PressurePlate;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DoorCloseDelay=1.0f;

	float LastDoorOpenTime;
	UPROPERTY(BlueprintAssignable)
	FOnOpenDoorRequest OnOpenDoorRequest;
};
