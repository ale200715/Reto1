
#include "EnemigoAcuatico.h"

void AEnemigoAcuatico::MoverEnemigo(float DeltaTime) {
    FVector Loc = GetActorLocation();
    Loc.X += Velocidad * DeltaTime * Direccion; // Movimiento Profundidad (Agua)

    if (FMath::Abs(Loc.X - PosicionInicial.X) >= DistanciaMaxima) {
        Direccion *= -1;
    }
    SetActorLocation(Loc);
}