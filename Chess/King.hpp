#ifndef King_h
#define King_h

#include "Piece.hpp"

class King : public Piece {
    public:
        King(bool color) : Piece("King", color, color ? 'K' : 'k'){};
        bool ValidMove(int, int) override;
        bool ValidCapture(int, int) override;
};


#endif