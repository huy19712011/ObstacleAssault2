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

	SetActorLocation(MyVector);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

