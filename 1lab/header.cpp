#include "header.h"
#include <string>


Matrix::Matrix(int m_rows, int m_column) {
    rows = m_rows;
    column = m_column;
    matrix = new long int* [rows];
    space = 0;
    for (int i{}; i < rows; i++) {
        *(matrix + i) = new long int[column];
    }
}

Matrix::Matrix() : Matrix(3, 3) {}

Matrix::Matrix(const Matrix& other) : Matrix(other.rows, other.column) {
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < column; j++)
        {
            *(*(matrix + i) + j) = other.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
		for (int i{}; i < rows; i++)
		{
			delete[] * (matrix + i);
			*(matrix + i) = nullptr;
		}
		delete[] matrix;
		matrix = nullptr;
	}
int Matrix::get_space() {
    return space;
}

void Matrix::input() {
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < column; j++)
        {
            std::cout << "enter a" << i + 1 << j + 1 << "(no more " << int(46340/column) <<"): ";
            enter_int((*(matrix + i) + j));
            if (space < get_num_length(*(*(matrix + i) + j))) {
                space = get_num_length(*(*(matrix + i) + j));
            }
        }
    }
    space += 2;
}

Matrix Matrix::multiply(Matrix* B) {
    if (column != B->rows) {

        throw  "These matrices cannot be multiplied";
    }
    //long int** first_matrix = this-> matrix;
    int column = B->column;
    Matrix mult_result(rows, column);
    for (int i{}; i < rows; i++)
    {
        for (int j=0; j < column; j++)
        {
            long int sum = 0;
            for (int k{}; k < column; k++) {
                //sum += *(*(matrix + i) + k) * *(*(B->matrix + k) + j);
                sum += *(*(this->matrix + i) + k) * *(*(B->matrix + k) + j);
            }
            *(*(mult_result.matrix + i) + j) = sum;
            if (mult_result.space < get_num_length(*(*(mult_result.matrix + i) + j))) {
                mult_result.space = get_num_length(*(*(mult_result.matrix + i) + j));
            }
        }
    }

    return mult_result;

}

void Matrix::output(int space) {
    for (int i{}; i < rows; i++)
    {
        for (int j{}; j < column; j++)
        {
            std::cout << std::setw(space) << std::left << *(*(matrix + i) + j);
        }
        std::cout << std::endl;
    }
}

int get_num_length(int num) {
    std::string str = std::to_string(num);
    return str.length();
}

int get_max_space(int space_a, int space_b) {
    return (space_a > space_b) ? space_a : space_b;
}

