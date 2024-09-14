#pragma once
#include "input_function.h"


class Matrix {
	int space;
	int rows;
	int column;
	long int** matrix;

public:
	Matrix();
	Matrix(int rows, int column);
	Matrix(const Matrix& other);

	void input();
	//Matrix multiply(Matrix* B);
	Matrix multiply(Matrix& B); 
	Matrix multiply(Matrix B);
	void output(int space);
	int get_space();

	~Matrix();
};

int get_num_length(int num);
int get_max_space(int space_a, int space_b);
