#include "Piece.hpp"

const int SIZE = 8;

class Board {
    public:
        Board();
		// sets up initial board configuration
		void populate();
		// check if a piece can be moved from the first coordinate to the second
		// coordinate and return successful
		bool move(bool, int, int, int, int);
		// displays current board
		void print();
		// displays information for a turn
		void printTurn(bool);
		//
		Piece* getPiece(int, int);
    private:
		// board[x][y] 
		// x refers to columm, y refers to row
        Piece* board[SIZE][SIZE];
};
