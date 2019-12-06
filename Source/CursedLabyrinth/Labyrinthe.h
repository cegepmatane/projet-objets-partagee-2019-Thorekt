// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Cellule.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Labyrinthe.generated.h"


UCLASS()
class CURSEDLABYRINTH_API ALabyrinthe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALabyrinthe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Apparition")
	TSubclassOf<class ACellule> objetApparition;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION(BlueprintCallable, Category = MultiThreading)
	void genererLabyrinthe();

};
