#include "MuroTrampa.h"
#include "TimerManager.h" 
#include "Engine/World.h"

AMuroTrampa::AMuroTrampa() : Super()
{
    PrimaryActorTick.bCanEverTick = false;

    TiempoCambio = 5.0f;
    RadioAleatorio = 2000.0f;
}

void AMuroTrampa::BeginPlay()
{
    Super::BeginPlay();
    ConfigurarColorMuro(FLinearColor::Red);
    InicializarMuro();
}

void AMuroTrampa::InicializarMuro()
{
    Super::InicializarMuro();

    GetWorldTimerManager().SetTimer(
        TimerTrampa,
        this,
        &AMuroTrampa::AlternarEstado,
        TiempoCambio,
        true
    );

    UE_LOG(LogTemp, Log, TEXT("Muro Trampa [C++ Puro]: Sistema de teletransporte iniciado con ciclo de %f segundos."), TiempoCambio);
}

void AMuroTrampa::AlternarEstado()
{
    bool bEstaOculto = IsHidden();

    if (!bEstaOculto)
    {
        SetActorHiddenInGame(true);
        SetActorEnableCollision(false);

        UE_LOG(LogTemp, Log, TEXT("Muro Trampa: Entrando en estado OCULTO."));
    }
    else
    {
        TeletransportarMuro();

        SetActorHiddenInGame(false);
        SetActorEnableCollision(true);

        UE_LOG(LogTemp, Log, TEXT("Muro Trampa: Reapareciendo en ubicación validada."));
    }
}

void AMuroTrampa::TeletransportarMuro()
{
    FVector NuevaUbicacion;
    bool bEspacioOcupado = true;
    int32 Intentos = 0;

    while (bEspacioOcupado && Intentos < 15)
    {
        float NuevaX = FMath::RandRange(-RadioAleatorio, RadioAleatorio);
        float NuevaY = FMath::RandRange(-RadioAleatorio, RadioAleatorio);

        NuevaUbicacion = FVector(NuevaX, NuevaY, GetActorLocation().Z);

        FCollisionShape CajaDePrueba = FCollisionShape::MakeBox(FVector(90.f, 90.f, 90.f));

        bEspacioOcupado = GetWorld()->OverlapBlockingTestByChannel(
            NuevaUbicacion,
            FQuat::Identity,
            ECC_WorldStatic, 
            CajaDePrueba
        );

        Intentos++;
    }

    SetActorLocation(NuevaUbicacion);
}