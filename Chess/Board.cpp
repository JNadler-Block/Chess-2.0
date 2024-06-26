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
    board[0][1] = new Knight(true);
    board[0][2] = new Bishop(true);
    board[0][3] = new King(true);
    board[0][4] = new Queen(true);
    board[0][5] = new Bishop(true);
    board[0][6] = new Knight(true);
    board[0][7] = new Rook(true);

    board[1][0] = new Pawn(true);
    board[1][1] = new Pawn(true);
    board[1][2] = new Pawn(true);
    board[1][3] = new Pawn(true);
    board[1][4] = new Pawn(true);
    board[1][5] = new Pawn(true);
    board[1][6] = new Pawn(true);
    board[1][7] = new Pawn(true);

    // Black Pieces
    board[7][0] = new Rook(false);
    board[7][1] = new Knight(false);
    board[7][2] = new Bishop(false);
    board[7][3] = new King(false);
    board[7][4] = new Queen(false);
    board[7][5] = new Bishop(false);
    board[7][6] = new Knight(false);
    board[7][7] = new Rook(false);

    board[6][0] = new Pawn(false);
    board[6][1] = new Pawn(false);
    board[6][2] = new Pawn(false);
    board[6][3] = new Pawn(false);
    board[6][4] = new Pawn(false);
    board[6][5] = new Pawn(false);
    board[6][6] = new Pawn(false);
    board[6][7] = new Pawn(false);

    for (int r = 0; r < SIZE; r++) {
        for (int c = 2; c < SIZE - 2; c++) {
            board[c][r] = nullptr;
        }
    }
}


Piece* Board::getPiece(int x, int y) {
    return board[y][x];
}
 
bool Board::move(bool white, int positionX, int positionY, int destinationX, int destinationY) {
    //cout << "Trying to move" << endl;
    if (positionX >= SIZE || positionX < 0 || positionY >= SIZE  || positionY < 0) return false;
    if (destinationX >= SIZE || destinationX < 0 || destinationY >= SIZE  || destinationY < 0) return false;
    if (positionX == destinationX && positionY == destinationY) return false;

    Piece* current = getPiece(positionX, positionY);
   
    if (current == nullptr) return false;
    if (current->GetColor() != white) return false;
    Piece* destination = getPiece(destinationX, destinationY);
    if (destination != nullptr && destination->GetColor() == white) return false;
    if (destination == nullptr) { // move: no piece at destination
       //return Move();
        if (!(current->ValidMove(destinationX - positionX, destinationY - positionY))) return false;
        //cout << "Finding Path" << endl;
        
        vector<vector<int>> path = current->MovePath(positionX, positionY, destinationX, destinationY);
        //cout << "Path Size: " << path.size() <<  endl;

        // for (int i = 0; i < path.size(); i++){
        //     cout << path[i][0] << ", " << path[i][1] << endl;
        // }
        
        for(auto i : path)
        {
            if (getPiece(i[0], i[1]) != nullptr) 
            {
                cout << "Piece in the way" << endl;
                return false;
            }
        }
        
        board[destinationY][destinationX] = board[positionY][positionX];
        board[positionY][positionX] = nullptr;
    }
    else { // capture: opposing player has piece at destination
        //return Capture();
    }


    return true;
}




void Board::print() {
    cout << "    X  ";
    for (int x = 0; x < SIZE; x++) {
        cout << x << "   ";
    }
    cout << endl << " Y  -----------------------------------" << 
        endl << "   |                                   |"<< endl;
    //cout << " y" << endl;
    for (int x = 0; x < SIZE; x++) {
        cout << " " << x << " |   ";
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y] == nullptr) {
                cout << 'X' << "   ";
            }
            else {
                cout << board[x][y]->GetSymbol() << "   ";
            }
        }
        cout << "|" << endl;
    } 
    cout << "   |                                   |" << 
        endl << "    -----------------------------------" << endl << endl;

    
}

void Board::printTurn(bool white) {
    print();

    cout << (white ? "WHITE'S " : "black's ") << "turn.";
    //cout << 
}
