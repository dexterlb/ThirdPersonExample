// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChatClient.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReceivedMessageEvent, FString, From, FString, Text);

UCLASS(BlueprintType, Blueprintable)
class THIRDPERSONEXAMPLE_API AChatClient : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChatClient();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Connect();
	
	UFUNCTION(BlueprintCallable)
	void Send(const FString& text);

	
	
	UPROPERTY(BlueprintAssignable, meta = (DisplayName = "Message received"))
	FReceivedMessageEvent OnReceiveMessage;
};