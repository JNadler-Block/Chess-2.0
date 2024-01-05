#include "Piece.hpp"

class King : public Piece {
    public:
        King(bool color) : Piece("King", color, color ? 'K' : 'k'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
};
