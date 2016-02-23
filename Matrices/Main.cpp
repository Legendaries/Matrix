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

	float mat1[]{
		0, 0, 0, 
		0, 0, 0,
		0, 0, 0
	};

	Matrix<float, 3, 3> mat1T(mat1);

	float mat2[]{
		1, 2, 3,
		4, 5, 6,
		7, 8, 9
	};

	Matrix<float, 3, 3> mat2T(mat2);

	Matrix<float, 3, 3> mat3 = mat1T*mat2T;

	mat3.print();

	int x = 1;
	string y = "2";

	cout << x + y. << endl;

	pause();

	return 0;
}