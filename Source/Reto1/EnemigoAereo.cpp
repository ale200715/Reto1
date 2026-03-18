
#include "EnemigoAereo.h"

void AEnemigoAereo::MoverEnemigo(float DeltaTime) {
    FVector Loc = GetActorLocation();
    Loc.Z += Velocidad * DeltaTime * Direccion; 

    if (FMath::Abs(Loc.Z - PosicionInicial.Z) >= DistanciaMaxima) {
        Direccion *= -1;
    }
    SetActorLocation(Loc);
}