#ifndef Knight_h
#define Knight_h

#include "Piece.hpp"

class Knight : public Piece {
    public:
        Knight(bool color) : Piece("Knight", color, color ? 'N' : 'n'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
        vector<vector<int> > MovePath(int, int, int, int) override;
};

#endif