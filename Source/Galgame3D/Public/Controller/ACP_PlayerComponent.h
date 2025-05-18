// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Character.h"
#include "ACP_PlayerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GALGAME3D_API UACP_PlayerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UACP_PlayerComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	ACharacter* PlayerCharacter;

protected:
	// Called when the game starts
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Move(FVector2D value);
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Look(FVector2D value);
};
