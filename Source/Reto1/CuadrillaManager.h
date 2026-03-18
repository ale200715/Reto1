#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "EAHelicoptero.h"
#include "EAAvion.h"
#include "EADron.h"
#include "ETSoldado.h"
#include "ETTanque.h"
#include "ETCamion.h"
#include "ETBlindado.h"
#include "EABarco.h"
#include "EALancha.h"
#include "EAMotoAcuatica.h"

#include "CuadrillaManager.generated.h"

UCLASS()
class RETO1_API ACuadrillaManager : public AActor {
    GENERATED_BODY()

public:
    ACuadrillaManager();

protected:
    virtual void BeginPlay() override;

    TArray<AActor*> PrimeraCuadrilla;
    TArray<AActor*> SegundaCuadrilla;

    FTimerHandle TimerHandle_CambioCuadrilla;

    void AparecerPrimeraCuadrilla();
    void SwitchACuadrillaDos(); 
};