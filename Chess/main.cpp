#include "Board.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Board b;
	b.populate();
	b.print();

	cout << endl << b.move(true, 1, 1, 1, 2) << endl;
	b.print();
	cout << endl << b.move(true, 0, 0, 1, 4) << endl;
	b.print();
	return 0;
}
