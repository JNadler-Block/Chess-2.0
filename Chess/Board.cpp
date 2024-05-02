#include "Board.hpp"
#include "Rook.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Piece.hpp"



Board::Board(){

}


void Board::populate(){
    // White Pieces
    board[0][0] = new Rook(true);
    board[1][0] = new Knight(true);
    board[2][0] = new Bishop(true);
    board[3][0] = new King(true);
    board[4][0] = new Queen(true);
    board[5][0] = new Bishop(true);
    board[6][0] = new Knight(true);
    board[7][0] = new Rook(true);

    board[0][1] = new Pawn(true);
    board[1][1] = new Pawn(true);
    board[2][1] = new Pawn(true);
    board[3][1] = new Pawn(true);
    board[4][1] = new Pawn(true);
    board[5][1] = new Pawn(true);
    board[6][1] = new Pawn(true);
    board[7][1] = new Pawn(true);

    // Black Pieces
    board[0][7] = new Rook(false);
    board[1][7] = new Knight(false);
    board[2][7] = new Bishop(false);
    board[3][7] = new King(false);
    board[4][7] = new Queen(false);
    board[5][7] = new Bishop(false);
    board[6][7] = new Knight(false);
    board[7][7] = new Rook(false);

    board[0][6] = new Pawn(false);
    board[1][6] = new Pawn(false);
    board[2][6] = new Pawn(false);
    board[3][6] = new Pawn(false);
    board[4][6] = new Pawn(false);
    board[5][6] = new Pawn(false);
    board[6][6] = new Pawn(false);
    board[7][6] = new Pawn(false);

    for (int r = 0; r < SIZE; r++) {
        for (int c = 2; c < SIZE - 2; c++) {
            board[r][c] = nullptr;
        }
    }
}



// TODO: Make sure Knight's MovePath function is called 
bool Board::move(bool white, int positionX, int positionY, int destinationX, int destinationY) {
    cout << "Trying to move" << endl;
    if (positionX >= SIZE || positionX < 0 || positionY >= SIZE  || positionY < 0) return false;
    if (destinationX >= SIZE || destinationX < 0 || destinationY >= SIZE  || destinationY < 0) return false;
    if (positionX == destinationX && positionY == destinationY) return false;

    Piece* current = board[positionX][positionY];
   
    if (current == nullptr) return false;
    if (current->GetColor() != white) return false;
    Piece* destination = board[destinationX][destinationY];
    if (destination != nullptr && destination->GetColor() == white) return false;
    if (destination == nullptr) { // move: no piece at destination
       //return Move();
        if (!(current->ValidMove(destinationX - positionX, destinationY - positionY))) return false;
        cout << "Finding Path" << endl;
        
        vector<vector<int>> path = current->MovePath(positionX, positionY, destinationX, destinationY);
        cout << "Path Size: " << path.size() <<  endl;

        for (int i = 0; i < path.size(); i++){
            cout << path[i][0] << ", " << path[i][1] << endl;
        }
        
        for(auto i : path)
        {
            if (board[i[0]][i[1]] != nullptr) 
            {
                cout << "Piece in the way" << endl;
                return false;
            }
        }
        
        // check positions along the path to destination to make sure pieces aren't in the way
        // positions 
        // for (i : positions[])
        //     if (position[i] != null)
        //         return false

        board[destinationX][destinationY] = board[positionX][positionY];
        board[positionX][positionY] = nullptr;
    }
    else { // capture: opposing player has piece at destination
        //return Capture();
    }


    return true;
}

void Board::print() {
    cout << " ";
    for (int x = 0; x < SIZE; x++) {
        cout << "   " << x;
    }
    cout << endl << "   ------------------------------" << endl;
    for (int x = 0; x < SIZE; x++) {
        cout << x << " | ";
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y] == nullptr) {
                cout << 'X' << "   ";
            }
            else {
                cout << board[x][y]->GetSymbol() << "   ";
            }
        }
        cout << endl;
    } 
    cout << endl;
}
