// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//get player view at this tick point
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	FVector LineTraceDirection = PlayerViewPointRotation.Vector();
	FVector LineTraceEnd = PlayerViewPointLocation + Reach * LineTraceDirection;
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor::Red,false,false,0,2.0f);


	//raycast to reach distance
	FHitResult Hit;
	FCollisionQueryParams QueryParams(FName(TEXT("")), false, GetOwner());
	FCollisionObjectQueryParams ObjectQueryParams(ECollisionChannel::ECC_PhysicsBody);
	GetWorld()->LineTraceSingleByObjectType(Hit, PlayerViewPointLocation, LineTraceEnd, ObjectQueryParams);
	AActor* HitActor = Hit.GetActor();
	if(HitActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *HitActor->GetName());
	}
	
	

	//see what we hit


	// ...
}

