#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Muro.h" 
#include "NaveBase.h" // <--- IMPORTANTE: Incluimos la base de las naves

#include "Reto1GameMode.generated.h"

UCLASS()
class RETO1_API AReto1GameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AReto1GameMode();

protected:
    virtual void BeginPlay() override;

    // --- CONFIGURACIÓN DE CANTIDADES ---
    int32 CantidadMovibles = 10;
    int32 CantidadTrampas = 10;
    int32 CantidadSensores = 10;

    // Agregamos contadores para las naves
    int32 CantidadCazas = 5;
    int32 CantidadPesadas = 3;

    // --- LOS CONTENEDORES MAESTROS (TArrays) ---

    // Contenedor de Muros (Polimorfismo de Muros)
    TArray<AMuro*> ContenedorMuros;

    // NUEVO: Contenedor de Naves (Polimorfismo de Naves)
    // Aquí guardaremos tanto ANaveCaza como ANavePesada indistintamente
    TArray<ANaveBase*> ContenedorNaves;

    // --- LÓGICA DE GENERACIÓN ---

    void GenerarLaberinto();

    // Nueva función para spawnear las naves
    void GenerarEscuadrones();

    FVector ObtenerPosicionValida();

    float RadioDeSpawn;
};