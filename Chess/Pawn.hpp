#ifndef Pawn_h
#define Pawn_h

#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(bool color) : Piece("Pawn", color, color ? 'P' : 'p'){};
        bool ValidMove(int, int) override;
        bool ValidCapture(int, int) override;
};


#endif