#include "NaveCaza.h"
#include "GameFramework/Actor.h"

ANaveCaza::ANaveCaza()
{
    PrimaryActorTick.bCanEverTick = true;

    Velocidad = 500.0f;

    AmplitudAvance = 200.0f;
    Amplitud = 200.0f;  
    Frecuencia = 4.0f;
}

void ANaveCaza::BeginPlay()
{
    Super::BeginPlay();
    PosicionInicial = GetActorLocation();
}


void ANaveCaza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANaveCaza::Mover(float DeltaTime)
{
    float Oscilacion = FMath::Sin(GetWorld()->GetTimeSeconds() * Frecuencia) * Amplitud;

    float AvanceRetroceso = FMath::Cos(GetWorld()->GetTimeSeconds() * Frecuencia) * AmplitudAvance;

    FVector NuevaPosicion = PosicionInicial +
        (GetActorRightVector() * Oscilacion) +
        (GetActorForwardVector() * AvanceRetroceso);

    SetActorLocation(NuevaPosicion);
}