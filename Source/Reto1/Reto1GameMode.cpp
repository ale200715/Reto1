#include "Reto1GameMode.h"
#include "MuroMovible.h"
#include "MuroTrampa.h"
#include "MuroSensor.h"
#include "NaveCaza.h"   
#include "NavePesada.h"
#include "Engine/World.h"

AReto1GameMode::AReto1GameMode()
{
    RadioDeSpawn = 2000.0f;
}

void AReto1GameMode::BeginPlay()
{
    Super::BeginPlay();
    GenerarLaberinto();
    GenerarEscuadrones();
}

void AReto1GameMode::GenerarLaberinto()
{
    if (!GetWorld()) return;

    // --- 1. SPWAN MUROS MOVIBLES ---
    for (int32 i = 0; i < CantidadMovibles; i++)
    {
        FVector Pos = ObtenerPosicionValida();
        float Grados = (FMath::RandBool()) ? 0.0f : 90.0f;
        FRotator Rot = FRotator(0.0f, Grados, 0.0f);

        AMuroMovible* Nuevo = GetWorld()->SpawnActor<AMuroMovible>(AMuroMovible::StaticClass(), Pos, Rot);
        if (Nuevo) ContenedorMuros.Add(Nuevo);
    }

    // --- 2. SPAWN MUROS TRAMPA (Faltaba este bloque) ---
    for (int32 i = 0; i < CantidadTrampas; i++)
    {
        FVector Pos = ObtenerPosicionValida();
        float Grados = (FMath::RandBool()) ? 0.0f : 90.0f;
        FRotator Rot = FRotator(0.0f, Grados, 0.0f);

        AMuroTrampa* Nuevo = GetWorld()->SpawnActor<AMuroTrampa>(AMuroTrampa::StaticClass(), Pos, Rot);
        if (Nuevo) ContenedorMuros.Add(Nuevo);
    }

    // --- 3. SPAWN MUROS SENSOR (Faltaba este bloque) ---
    for (int32 i = 0; i < CantidadSensores; i++)
    {
        FVector Pos = ObtenerPosicionValida();
        float Grados = (FMath::RandBool()) ? 0.0f : 90.0f;
        FRotator Rot = FRotator(0.0f, Grados, 0.0f);

        AMuroSensor* Nuevo = GetWorld()->SpawnActor<AMuroSensor>(AMuroSensor::StaticClass(), Pos, Rot);
        if (Nuevo) ContenedorMuros.Add(Nuevo);
    }

    UE_LOG(LogTemp, Warning, TEXT("Laberinto completo: %d muros creados."), ContenedorMuros.Num());
}

FVector AReto1GameMode::ObtenerPosicionValida()
{
    FVector Candidata;
    bool bEsValida = false;
    int32 Intentos = 0;

    while (!bEsValida && Intentos < 100) // 100 intentos para encontrar hueco
    {
        float RandX = FMath::RandRange(-RadioDeSpawn, RadioDeSpawn);
        float RandY = FMath::RandRange(-RadioDeSpawn, RadioDeSpawn);
        Candidata = FVector(RandX, RandY, 100.0f);

        // USAMOS ESFERA: Es mÃ¡s segura para muros que rotan.
        // Un radio de 300 unidades es suficiente para cubrir el largo del muro (400)
        // permitiendo que se acerquen pero no se toquen.
        FCollisionShape EsferaCheck = FCollisionShape::MakeSphere(300.0f);

        bool bHayObstaculo = GetWorld()->OverlapBlockingTestByChannel(
            Candidata,
            FQuat::Identity,
            ECC_WorldStatic,
            EsferaCheck
        );

        if (!bHayObstaculo) bEsValida = true;
        Intentos++;
    }
    return Candidata;
}

void AReto1GameMode::GenerarEscuadrones()
{
    if (!GetWorld()) return;

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    // --- SPAWN NAVES CAZA ---
    for (int32 i = 0; i < CantidadCazas; i++)
    {
        FVector Pos = ObtenerPosicionValida();
        Pos.Z = 400.0f; // Altura de vuelo

        ANaveCaza* NuevaCaza = GetWorld()->SpawnActor<ANaveCaza>(ANaveCaza::StaticClass(), Pos, FRotator::ZeroRotator, SpawnParams);
        if (NuevaCaza)
        {
            ContenedorNaves.Add(NuevaCaza);
        }
    }

    // --- SPAWN NAVES PESADAS ---
    for (int32 i = 0; i < CantidadPesadas; i++)
    {
        FVector Pos = ObtenerPosicionValida();
        Pos.Z = 600.0f; // Un poco más alto para no chocar con las Cazas

        ANavePesada* NuevaPesada = GetWorld()->SpawnActor<ANavePesada>(ANavePesada::StaticClass(), Pos, FRotator::ZeroRotator, SpawnParams);
        if (NuevaPesada)
        {
            ContenedorNaves.Add(NuevaPesada);
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("Escuadrones listos: %d naves en el aire."), ContenedorNaves.Num());
}