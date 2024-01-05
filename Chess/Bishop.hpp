#include "Piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(bool color) : Piece("Bishop", color, color ? 'B' : 'b'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
};
