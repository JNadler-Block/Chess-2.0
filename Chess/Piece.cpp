#include "Piece.hpp"





int Piece::CalculateStep(int position, int destination){
    if (position < destination) return 1;
    if (position > destination) return -1;
    return 0;
}


vector<vector<int> > Piece::MovePath(int positionX, int positionY, int destinationX, int destinationY){
    vector<vector<int> > path;
    int stepX = CalculateStep(positionX, destinationX);
    int stepY = CalculateStep(positionY, destinationY);

    for (int x = positionX + stepX, y = positionY + stepY; x != destinationX && y != destinationY; x += stepX, y += stepY)
    {
        path.push_back({x,y});    
    }
    return path;
}   