// Fill out your copyright notice in the Description page of Project Settings.

#include "ChatActor.h"
#include "Engine.h"

// Sets default values
AChatActor::AChatActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	connection.OnReceivedMessage().AddUObject(this, &AChatActor::DispatchReceiveMessage);
}

// Called when the game starts or when spawned
void AChatActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChatActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	connection.Update();
}

void AChatActor::Connect()
{
	connection.Connect(Server, Username, Nick);
	connection.Join("#foo");
}

void AChatActor::Send(const FString & text)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Want to send from plugin: ") + text);
	connection.Send("#foo", text);
}

void AChatActor::DispatchReceiveMessage(const FString& from, const FString& channel, const FString& message) {
	OnReceiveMessage.Broadcast(from, channel, message);
}