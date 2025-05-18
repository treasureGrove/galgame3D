// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/ACP_PlayerComponent.h"
#include "Config/GalgameConfig.h"

// Sets default values for this component's properties
UACP_PlayerComponent::UACP_PlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UACP_PlayerComponent::BeginPlay()
{
	InitializeComponent();
	Super::BeginPlay();

	// ...
	
}

void UACP_PlayerComponent::InitializeComponent()
{
	AActor* Owner = GetOwner();
	if (Owner)
	{
		PlayerCharacter = Cast<ACharacter>(Owner);
	}
}


// Called every frame
void UACP_PlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UACP_PlayerComponent::Move(FVector2D value)
{
	FVector forward = PlayerCharacter->GetActorForwardVector();
	FVector right = PlayerCharacter->GetActorRightVector();
	FVector move = forward * value.Y + right * value.X;
	PlayerCharacter->AddMovementInput(move);
}

void UACP_PlayerComponent::Look(FVector2D value)
{
	if (PlayerCharacter && PlayerCharacter->GetController())
	{
		PlayerCharacter->AddControllerYawInput(value.X*GetDefault<UGalgameConfig>()->CameraMoveSpeed);
		PlayerCharacter->AddControllerPitchInput(-value.Y * GetDefault<UGalgameConfig>()->CameraMoveSpeed);
	}
}