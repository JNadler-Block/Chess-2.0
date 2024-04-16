#ifndef Helper_h
#define Helper_h

#include <vector>



using namespace std;

int CalculateStep(int position, int destination)
{
    if (position < destination)
    {
        return 1;
    }
    if (position > destination)
    {
        return -1;
    }
    return 0;
}

vector<vector<int> > MovePath(int positionX, int positionY, int destinationX, int destinationY)
{
    vector<vector<int> > path;
    int stepX = CalculateStep(positionX, destinationX);
    int stepY = CalculateStep(positionY, destinationY);

    for (int x = positionX + stepX, y = positionY + stepY; x != destinationX && y != destinationY; x += stepX, y += stepY)
    {
    }
    return path;
}


#endif