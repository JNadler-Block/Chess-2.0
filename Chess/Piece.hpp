#ifndef Piece_h
#define Piece_h

#include <vector>
#include <iostream>

using namespace std;


class Piece {
    public:
        Piece(string n, bool c, char s) { name = n; white = c; symbol = s;};
        bool GetColor() { return white;};
        string GetName() { return name;};
        char GetSymbol() { return symbol;};
        virtual bool ValidMove(int, int) = 0;
        virtual bool ValidCapture(int, int) = 0;
        int CalculateStep(int, int);
        virtual vector<vector<int> > MovePath (int, int, int, int);
    private:
        string name = "";
        bool white;
        char symbol;
};

#endif
