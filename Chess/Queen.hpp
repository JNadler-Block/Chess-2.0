#include "Piece.hpp"

class Queen : public Piece {
    public:
        Queen(bool color) : Piece("Queen", color, color ? 'Q' : 'q'){};
        bool ValidMove(int, int);
        bool ValidCapture(int, int);
};
