// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cellule.generated.h"

UCLASS()
class CURSEDLABYRINTH_API ACellule : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACellule();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	bool ouverte;
	bool murs[4];
	ACellule* cellulesAdjacentes[4];
	int coordX, coordY;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void setOuverte(bool etat);
	bool estOuverte();
	void setMur(int index, bool etat);
	bool getMur(int index);
	void setCellulesAdjacentes(int index, ACellule *cellule);
	ACellule * getCellulesAdjacentes(int index);
	void setCoordonnee(int x, int y);
	int getCoordX();
	int getCoordY();
};
