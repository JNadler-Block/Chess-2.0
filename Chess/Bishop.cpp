#include "Bishop.hpp"


bool Bishop::ValidMove(int relativeX, int relativeY){
    return abs(relativeX) == abs(relativeY);
}

bool Bishop::ValidCapture(int relativeX, int relativeY){
    return ValidMove(relativeX, relativeY);
}