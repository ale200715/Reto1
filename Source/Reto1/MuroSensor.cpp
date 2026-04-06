#include "MuroSensor.h"
#include "Kismet/GameplayStatics.h" 
#include "Engine/World.h"

AMuroSensor::AMuroSensor() : Super()
{
    PrimaryActorTick.bCanEverTick = true;

    DistanciaDeteccion = 500.0f; 
    bEstaActivado = false;
}

void AMuroSensor::BeginPlay()
{
    Super::BeginPlay();
    ConfigurarColorMuro(FLinearColor::Green);
    InicializarMuro();
}

void AMuroSensor::InicializarMuro()
{
    Super::InicializarMuro();

    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);

    UE_LOG(LogTemp, Log, TEXT("Muro Sensor [C++ Puro]: Inicializado en modo oculto."));
}

void AMuroSensor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    APawn* MiJugador = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    if (MiJugador)
    {
        float DistanciaAlJugador = FVector::Dist(GetActorLocation(), MiJugador->GetActorLocation());

        if (DistanciaAlJugador < DistanciaDeteccion && !bEstaActivado)
        {
            SetActorHiddenInGame(false);
            SetActorEnableCollision(true);
            bEstaActivado = true;

            UE_LOG(LogTemp, Warning, TEXT("Muro Sensor: Jugador detectado a %f unidades. Bloqueando paso."), DistanciaAlJugador);
        }
        else if (DistanciaAlJugador >= DistanciaDeteccion && bEstaActivado)
        {
            SetActorHiddenInGame(true);
            SetActorEnableCollision(false);
            bEstaActivado = false;

            UE_LOG(LogTemp, Log, TEXT("Muro Sensor: Jugador fuera de rango. Volviendo a modo oculto."));
        }
    }
}