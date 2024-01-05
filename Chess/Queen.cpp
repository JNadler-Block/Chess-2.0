#include "Queen.hpp"

bool Queen::ValidMove(int relativeX, int relativeY){
    return ((abs(relativeX) == abs(relativeY)) || (relativeX == 0 || relativeY == 0));
}

bool Queen::ValidCapture(int relativeX, int relativeY){
    return ((abs(relativeX) == abs(relativeY)) || (relativeX == 0 || relativeY == 0));
}