#include "King.hpp"

bool King::ValidMove(int relativeX, int relativeY){
    return (abs(relativeX) <= 1 && abs(relativeY) <= 1);
}

bool King::ValidCapture(int relativeX, int relativeY){
    return ValidMove(relativeX, relativeY);
}
/*
vector<vector<int>> King::MovePath(int positionX, int positionY, int destinationX, int destinationY){
    return vector<vector<int>>{};
} */