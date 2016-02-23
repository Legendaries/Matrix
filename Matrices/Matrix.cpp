#include "Matrix.h"
#include <string>

#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns>::Matrix() {

}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns>::Matrix(T r[rows*columns]) {
	for (int j = 0; j < columns; j++)
		for (int i = 0; i < rows; i++)
			data[i][j] = r[i*(columns) + j];
}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns>::Matrix(T r[rows][columns]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			data[i][j] = r[i][j];
}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns>::~Matrix() {

}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns> Matrix<T, rows, columns>::identity() {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			data[i][j] = (i == j) ? T(1) : T(0);
	return *this;
}

template<typename T, unsigned int rows, unsigned int columns>
std::string Matrix<T, rows, columns>::toString() {
	string out = "";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			out.append(std::to_string(data[i][j]) + "\t");
		out.append("\n");
	}
	return out;
}

template<typename T, unsigned int rows, unsigned int columns>
void Matrix<T, rows, columns>::print() {
	cout << toString() << endl << endl;
}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns> Matrix<T, rows, columns>::getEliminationMatrix() {
	Matrix<T, rows, columns> result;
	result.identity();

	Matrix<T, rows, columns> tempMat (data);

	//ERO
	for (int j = 0; j < columns; j++)
		for (int i = j + 1; i < rows; i++) {
			T multiplier = tempMat.data[i][j] / tempMat.data[j][j];
			result.data[i][j] = -multiplier;
			for (int k = 0; k < columns; k++)
				tempMat.data[i][k] -= multiplier*tempMat.data[j][k];
		}

	//ERO pt 2
	for (int j = columns - 2; j > 0; j--)
		for (int i = j - 1; i >= 0; i--) {
			T multiplier = tempMat.data[i][j] / tempMat.data[j][j];
			result.data[i][j] = -multiplier;
			for (int k = 0; k < columns; k++)
				tempMat.data[i][k] -= multiplier*tempMat.data[j][k];
		}

	for (int i = 0; i < columns; i++)
		cout << "-------";

	cout << endl << endl;

	//Scale
	
		for (int i = 0; i < rows; i++) {
			T temp = tempMat.data[i][i];
				tempMat.data[i][i] = 1/temp;
		}
	return result;
}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns> Matrix<T, rows, columns>::rref() {
	//ERO
	for (int j = 0; j < columns; j++)
		for (int i = j + 1; i < rows; i++) {
			T multiplier = data[i][j] / data[j][j];
			cout << "Multiplier_(" << i + 1 << "," << j + 1 << "): " << multiplier << endl << endl;/////////shows steps
			for (int k = 0; k < columns; k++)
				data[i][k] -= multiplier*data[j][k];
			print(); ///// shows steps
		}

	//ERO pt 2
	for (int j = columns - 2; j > 0; j--)
		for (int i = j - 1; i >= 0; i--) {
			T multiplier = data[i][j] / data[j][j];
			cout << "Multiplier_(" << i + 1 << "," << j + 1 << "): " << multiplier << endl << endl;/////////shows steps
			for (int k = 0; k < columns; k++)
				data[i][k] -= multiplier*data[j][k];
			print(); ///// shows steps
		}

	for (int i = 0; i < columns; i++)
		cout << "-------";

	cout << endl << endl;
	
	//Scale for readability
	for (int j = 0; j < columns; j++)
		for (int i = j; i < rows; i++) {
			T temp = data[j][j];
			for (int k = 0; k < columns; k++)
				data[i][k] /= temp;
		}
	return *this;
}

template<typename T, unsigned int rows, unsigned int columns>
Matrix<T, rows, columns> Matrix<T, rows, columns>::rref(Matrix<T, rows, columns> m) {
	return m.rref();
}