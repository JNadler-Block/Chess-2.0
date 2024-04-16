#ifndef Rook_h
#define Rook_h

#include "Piece.hpp"

class Rook : public Piece {
    public:
        Rook(bool color) : Piece("Rook", color, color ? 'R' : 'r'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
        //vector<vector<int>> MovePath(int, int, int, int);
};

#endif