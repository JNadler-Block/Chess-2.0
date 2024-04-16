#ifndef Piece_h
#define Piece_h

#include <vector>
#include <iostream>

using namespace std;


class Piece {
    public:
        Piece(string n, bool c, char s) { name = n; white = c; symbol = s;};
        bool GetColor() { return white;};
        string GetName() { return name;};
        char GetSymbol() { return symbol;};
        virtual bool ValidMove(int, int) = 0;
        virtual bool ValidCapture(int, int) = 0;
        int CalculateStep(int position, int destination){
            if (position < destination) return 1;
            if (position > destination) return -1;
            return 0;
        }

        vector<vector<int> > MovePath(int positionX, int positionY, int destinationX, int destinationY){
            vector<vector<int> > path;
            int stepX = CalculateStep(positionX, destinationX);
            int stepY = CalculateStep(positionY, destinationY);

            //for (int x = positionX + stepX, y = positionY + stepY; x != destinationX && y != destinationY; x += stepX, y += stepY)
            //{
            //}
            return path;
        }   

    private:
        string name = "";
        bool white;
        char symbol;
};

#endif
