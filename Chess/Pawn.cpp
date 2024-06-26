#include "Pawn.hpp"


bool Pawn::ValidMove(int relativeX, int relativeY){
    if (relativeX != 0) return false;
    int validY = GetColor() ? 1 : -1;
    return relativeY == validY;
}

bool Pawn::ValidCapture(int relativeX, int relativeY){
    if (abs(relativeY) != 1) return false;
    int validX = GetColor() ? 1 : -1;
    return relativeX == validX;
}