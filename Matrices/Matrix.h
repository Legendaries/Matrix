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
	inline Matrix<T, rows, columns> operator*(Matrix<T, rows, columns> &m) {
		Matrix<T, rows, columns> out;
		if (sizeof(data) == sizeof(m.data)) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns; j++) {
					T sum = 0;
					for (int k = 0; k < columns; k++)
						sum += data[i][k] * m.data[k][j];
					out.data[i][j] = sum;
				}
			}
		} else {
			//throw exception;
		}
		return out;
	}
};

