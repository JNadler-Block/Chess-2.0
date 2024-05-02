#include "Board.hpp"

using namespace std;

int main(int argc, char* argv[]){
	Board b;
	b.populate();
	b.print();


	b.move(true, 1, 0, 0, 2);
	// b.move(true, 1, 1, 1, 2);
	// b.print();
	// b.move(true, 2, 1, 2, 2);
	// b.print();
	// b.move(true, 2, 0, 0, 2);
	// b.print();
	// cout << endl << b.move(true, 0, 0, 1, 4) << endl;
	// b.print();
	return 0;
}
