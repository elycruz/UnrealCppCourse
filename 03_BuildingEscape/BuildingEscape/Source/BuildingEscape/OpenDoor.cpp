// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"
#include "Gameframework/PlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Core/Public/Math/Rotator.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Get `DoorOpener`
	UWorld* World = GetWorld();
	PlayerPawn = World->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	// Get Rotator
	AActor* Owner = GetOwner();
	FRotator Rotator = FRotator(0.0f, 90.0f, 0.0f);

	// Update Rotator on owner
	Owner->SetActorRotation(Rotator);
}

void UOpenDoor::CloseDoor()
{
	// Get Rotator
	AActor* Owner = GetOwner();
	FRotator Rotator = FRotator(0.0f, 0.0f, 0.0f);

	// Update Rotator on owner
	Owner->SetActorRotation(Rotator);
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float currTime = GetWorld()->TimeSeconds;
	bool onPressurePlate = PressurePlate->IsOverlappingActor(PlayerPawn);
	bool passedDoorCloseDelay = currTime + DoorCloseDelay > LastOpenTime;

	// If door closed and 'on pressure plate'
	if (!doorOpened && onPressurePlate) {
		OpenDoor();
		LastOpenTime = currTime;
		doorOpened = true;
	}  

	// Else if close door condition
	else if (doorOpened && !onPressurePlate && passedDoorCloseDelay) {
		CloseDoor();
		doorOpened = false;
	}

}

