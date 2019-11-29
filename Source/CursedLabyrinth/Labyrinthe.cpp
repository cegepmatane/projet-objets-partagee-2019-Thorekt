// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Labyrinthe.h"

// Sets default values
ALabyrinthe::ALabyrinthe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ALabyrinthe::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ALabyrinthe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALabyrinthe::genererLabyrinthe() {
	UWorld* monde = GetWorld();

	FRotator rotation;
	rotation.Yaw = 0;
	rotation.Pitch = 0;
	rotation.Roll = 0;

	ACellule** listeCellules[10];
	/* generattion des cellules*/
	for (int x = 0; x < 10; x++)
	{
		ACellule* colloneCellules[10];
		for (int y = 0; y < 10; y++)
		{
			/*ACellule cellule = new ACellule();
			cellule.setCoordonnee(x, y);
			FVector const& point = FVector((x - 5) * 10, (y - 5) * 10, 0);*/

			FActorSpawnParameters parametresApparition;
			parametresApparition.Owner = this;
			parametresApparition.Instigator = Instigator;

			colloneCellules[y] = monde->SpawnActor<ACellule>(this->objetApparition, FVector((x - 4.5f) * 1000, (y - 4.5f) * 1000, 0), rotation, parametresApparition);
			
		}
		listeCellules[x] = colloneCellules;
	}

	/*atribution des cellules adjacentes*/
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (x != 0) {

				listeCellules[x - 1][y]->setCellulesAdjacentes(0, listeCellules[x][y]);
				listeCellules[x][y]->setCellulesAdjacentes(2, listeCellules[x - 1][y]);

			}

			if (y != 0) {
				listeCellules[x][y - 1]->setCellulesAdjacentes(1, listeCellules[x][y]);
				listeCellules[x][y]->setCellulesAdjacentes(3, listeCellules[x][y - 1]);
			}

		}
	}



}

