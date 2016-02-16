#pragma once

#include <string>

template<typename T, unsigned int rows, unsigned int columns>
class Matrix {
private:
public:
	T data[rows][columns];
	Matrix();
	Matrix(T r[rows][columns]);
	Matrix(T r[rows*columns]);
	~Matrix();
	Matrix<T, rows, columns> identity();
	std::string toString();
	void print();
	static Matrix<T, rows, columns> rref(Matrix<T, rows, columns> m);
	Matrix<T, rows, columns> rref();
	Matrix<T, rows, columns> getEliminationMatrix();
};

