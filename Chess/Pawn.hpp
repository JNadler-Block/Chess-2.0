#include "Piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(bool color) : Piece("Pawn", color, color ? 'P' : 'p'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
};
