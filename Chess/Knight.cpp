#include "Knight.hpp"

bool Knight::ValidMove(int relativeX, int relativeY){
    return ((abs(relativeX) == 1 && abs(relativeY) == 2) || (abs(relativeX) == 2 && abs(relativeY) == 1));
}

bool Knight::ValidCapture(int relativeX, int relativeY){
    return ValidMove(relativeX, relativeY);
}

vector<vector<int> > Knight::MovePath(int positionX, int positionY, int destinationX, int destinationY) {
    cout << "Knight Move Path" << endl;
    return vector<vector<int> >{};
} 