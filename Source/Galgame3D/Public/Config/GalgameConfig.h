// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GalgameConfig.generated.h"

/**
 * 
 */
UCLASS()
class GALGAME3D_API UGalgameConfig : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Control")
	float CameraMoveSpeed = 1.0f;
};
