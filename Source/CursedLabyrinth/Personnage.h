// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Personnage.generated.h"

UCLASS()
class CURSEDLABYRINTH_API APersonnage : public AActor
{
	GENERATED_BODY()

	

	
public:	
	// Sets default values for this actor's properties
	APersonnage();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Energie", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* attrapeur;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int multiplicateurVitesse;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE class USphereComponent* getAttrapeur() const { return this->attrapeur; }

	UFUNCTION(BlueprintCallable, Category = "Prendre")
	void prendre();
	UFUNCTION(BlueprintCallable, Category = "Prendre")
	int getMultiplicateurVitesse();
};
