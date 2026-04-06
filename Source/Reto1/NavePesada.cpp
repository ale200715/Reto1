#include "NavePesada.h"
#include "GameFramework/Actor.h"

ANavePesada::ANavePesada()
{
    PrimaryActorTick.bCanEverTick = true;    
    Velocidad = 200.0f; 

    AmplitudLenta = 50.0f; 
    AmplitudAvance = 200.0f;
    FrecuenciaLenta = 1.0f; 
}

void ANavePesada::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation();
}

void ANavePesada::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}

void ANavePesada::Mover(float DeltaTime)
{
    float Oscilacion = FMath::Sin(GetWorld()->GetTimeSeconds() * FrecuenciaLenta) * AmplitudLenta;

    float AvanceRetroceso = FMath::Cos(GetWorld()->GetTimeSeconds() * FrecuenciaLenta) * AmplitudAvance;


    FVector NuevaPosicion = PosicionInicial +
        (GetActorRightVector() * Oscilacion) +
        (GetActorForwardVector() * AvanceRetroceso);

    SetActorLocation(NuevaPosicion);
}