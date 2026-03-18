#include "Enemigo.h"

AEnemigo::AEnemigo() {
    PrimaryActorTick.bCanEverTick = true;

    
    MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
    RootComponent = MallaEnemigo;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (MeshAsset.Succeeded()) {
        MallaEnemigo->SetStaticMesh(MeshAsset.Object);
    }
}

void AEnemigo::BeginPlay() {
    Super::BeginPlay();
    PosicionInicial = GetActorLocation();
}

void AEnemigo::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    MoverEnemigo(DeltaTime);
}

void AEnemigo::MoverEnemigo(float DeltaTime) {

}