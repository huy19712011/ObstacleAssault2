// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("1 => Display"));
	UE_LOG(LogTemp, Warning, TEXT("2 => Warning"));
	UE_LOG(LogTemp, Error, TEXT("5 => Error"));

	// MemberFloat = 10.0f;
	UE_LOG(LogTemp, Warning, TEXT("MemberFloat = %f"), MemberFloat);
	UE_LOG(LogTemp, Warning, TEXT("MemberInt = %d"), MemberInt);

	//FVector TestVector = FVector(730.0f, 230.0f, 420.0f);
	//SetActorLocation(TestVector);

	StartLocation = GetActorLocation();

	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// UE_LOG(LogTemp, Display, TEXT("Tick is called"));

	// MyVector.X = MyVector.X + 1;

	// SetActorLocation(MyVector);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance)
	{

		float Overshoot = DistanceMoved - MoveDistance;
		FString PlatformName = GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s overshoot by %f"), *PlatformName, Overshoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal(); // normal vector
		FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(NewStartLocation);
		StartLocation = NewStartLocation;

		PlatformVelocity = - PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);		
	}
}

// ReSharper disable once CppMemberFunctionMayBeConst
void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	//Rotate the platform
	FRotator RotationToAdd = RotationVelocity * DeltaTime;
	AddActorLocalRotation(RotationToAdd);
}

// ReSharper disable once CppFunctionDoesntReturnValue
// ReSharper disable once CppMemberFunctionMayBeConst
float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

