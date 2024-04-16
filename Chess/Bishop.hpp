#ifndef Bishop_h
#define Bishop_h

#include "Piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(bool color) : Piece("Bishop", color, color ? 'B' : 'b'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
        //vector<vector<int>> MovePath(int, int, int, int);
};

#endif