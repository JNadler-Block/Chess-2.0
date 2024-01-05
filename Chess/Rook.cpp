#include "Rook.hpp"

bool Rook::ValidMove(int relativeX, int relativeY){
    return (relativeX == 0 || relativeY == 0);
}

bool Rook::ValidCapture(int relativeX, int relativeY){
    return ValidMove(relativeX, relativeY);
}