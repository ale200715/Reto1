#include "CuadrillaManager.h"
#include "Kismet/GameplayStatics.h" 
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

ACuadrillaManager::ACuadrillaManager() {
    PrimaryActorTick.bCanEverTick = false;
}

void ACuadrillaManager::BeginPlay() {
    Super::BeginPlay();

    AparecerPrimeraCuadrilla();

    float TiempoDeEspera = 10.0f;
    GetWorldTimerManager().SetTimer(TimerHandle_CambioCuadrilla, this, &ACuadrillaManager::SwitchACuadrillaDos, TiempoDeEspera, false);
}
void ACuadrillaManager::AparecerPrimeraCuadrilla() {
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC || !PC->GetPawn()) return;

    FVector Loc = PC->GetPawn()->GetActorLocation();
    FVector Fwd = PC->GetPawn()->GetActorForwardVector();
    FVector Right = PC->GetPawn()->GetActorRightVector();
    FActorSpawnParameters Params;

    if (GetLocalRole() == ROLE_Authority) {

        // Aéreos de la 1ra Cuadrilla
        PrimeraCuadrilla.Add(GetWorld()->SpawnActor<AEAAvion>(AEAAvion::StaticClass(), Loc + (Fwd * 1200.0f) + FVector(0, 0, 600), FRotator::ZeroRotator, Params));
        PrimeraCuadrilla.Add(GetWorld()->SpawnActor<AEAHelicoptero>(AEAHelicoptero::StaticClass(), Loc + (Fwd * 1000.0f) + (Right * 300.f) + FVector(0, 0, 400), FRotator::ZeroRotator, Params));

        // Terrestres de la 1ra Cuadrilla
        PrimeraCuadrilla.Add(GetWorld()->SpawnActor<AETTanque>(AETTanque::StaticClass(), Loc + (Fwd * 800.0f) + (Right * -200.f), FRotator::ZeroRotator, Params));
        PrimeraCuadrilla.Add(GetWorld()->SpawnActor<AETSoldado>(AETSoldado::StaticClass(), Loc + (Fwd * 600.0f) + (Right * 200.f), FRotator::ZeroRotator, Params));

        // Acuáticos de la 1ra Cuadrilla
        PrimeraCuadrilla.Add(GetWorld()->SpawnActor<AEABarco>(AEABarco::StaticClass(), Loc + (Fwd * 1500.0f) - FVector(0, 0, 400), FRotator::ZeroRotator, Params));
    }
}

void ACuadrillaManager::SwitchACuadrillaDos() {
    if (GetLocalRole() == ROLE_Authority) {
        for (AActor* Miembro : PrimeraCuadrilla) {
            if (Miembro) Miembro->Destroy();
        }
    }
    PrimeraCuadrilla.Empty();

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC || !PC->GetPawn()) return;

    FVector Loc = PC->GetPawn()->GetActorLocation();
    FVector Fwd = PC->GetPawn()->GetActorForwardVector();
    FVector Right = PC->GetPawn()->GetActorRightVector();
    FActorSpawnParameters Params;

    if (GetLocalRole() == ROLE_Authority) {

        SegundaCuadrilla.Add(GetWorld()->SpawnActor<AEADron>(AEADron::StaticClass(), Loc + (Fwd * 500.0f) + FVector(0, 0, 300), FRotator::ZeroRotator, Params));

        SegundaCuadrilla.Add(GetWorld()->SpawnActor<AETBlindado>(AETBlindado::StaticClass(), Loc + (Fwd * 700.0f) + (Right * 400.f), FRotator::ZeroRotator, Params));
        SegundaCuadrilla.Add(GetWorld()->SpawnActor<AETCamion>(AETCamion::StaticClass(), Loc + (Fwd * 700.0f) + (Right * -400.f), FRotator::ZeroRotator, Params));

        
        SegundaCuadrilla.Add(GetWorld()->SpawnActor<AEALancha>(AEALancha::StaticClass(), Loc + (Fwd * 1200.0f) - FVector(0, 0, 200), FRotator::ZeroRotator, Params));
        SegundaCuadrilla.Add(GetWorld()->SpawnActor<AEAMotoAcuatica>(AEAMotoAcuatica::StaticClass(), Loc + (Fwd * 1000.0f) - FVector(0, 0, 150), FRotator::ZeroRotator, Params));
    }

    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("¡SEGUNDA CUADRILLA DESPLEGADA CON ÉXITO!"));
}