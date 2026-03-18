
#include "EnemigoTerrestre.h"

void AEnemigoTerrestre::MoverEnemigo(float DeltaTime) {
    FVector Loc = GetActorLocation();
    Loc.Y += Velocidad * DeltaTime * Direccion; 

    if (FMath::Abs(Loc.Y - PosicionInicial.Y) >= DistanciaMaxima) {
        Direccion *= -1;
    }
    SetActorLocation(Loc);
}