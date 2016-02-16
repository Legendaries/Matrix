#include <iostream>
#include <cstdlib>
#include "Matrix.h"
#include "Matrix.cpp"
#include <string>

using namespace std;

void pause() {
	int x = 0;
	cin >> x;
}

int main() {
	float test[]{ 1, 2, 3, 4,
				5, 6, 7, 8,
				9, 1, 2, 3 };
	Matrix<float, 3, 4> matTest (test);
	matTest.print();
	//matTest.rref().print();
	matTest.getEliminationMatrix().print();
	matTest.rref().print();
	pause();

	return 0;
}