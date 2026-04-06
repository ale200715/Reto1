#include "MuroMovible.h"

AMuroMovible::AMuroMovible()
{
    PrimaryActorTick.bCanEverTick = true;

    Velocidad = 2.0f;
    Amplitud = 300.0f;
    Direccion = FVector(0.0f, 1.0f, 0.0f);
}

void AMuroMovible::BeginPlay()
{
    Super::BeginPlay();
    ConfigurarColorMuro(FLinearColor::Blue);

    InicializarMuro();
}

void AMuroMovible::InicializarMuro()
{
    Super::InicializarMuro();

    PosicionInicial = GetActorLocation();

    Velocidad = FMath::RandRange(1.5f, 3.5f);
    Amplitud = FMath::RandRange(200.0f, 500.0f);

    UE_LOG(LogTemp, Log, TEXT("Muro Movible [C++ Puro]: PosicionInicial capturada en %s"), *PosicionInicial.ToString());
}

void AMuroMovible::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime); 
    float TiempoActual = GetWorld()->GetTimeSeconds();
    float Desplazamiento = FMath::Sin(TiempoActual * Velocidad) * Amplitud;

    FVector NuevaPosicion = PosicionInicial + (Direccion * Desplazamiento);

    SetActorLocation(NuevaPosicion);
}