// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vitesse.generated.h"

UCLASS()
class CURSEDLABYRINTH_API AVitesse : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVitesse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void estAttrape();
};
