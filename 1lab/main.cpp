#include "header.h"
//программа перемножения матриц
int main() {

	do {
		system("cls");
		Matrix* A = nullptr;
		Matrix* B = nullptr;
		Matrix* result = nullptr;
		int marker;
		std::cout << "You can choose one of theese options:\n1. Create identical matrices.\n2. Create arbitrary matrices.\n3. Create default matrices.(3 * 3)\n";
		enter_type(&marker);
		system("cls");
		if (marker == 1) {
			int rows, column;
			std::cout << "Enter amount of rows and columns in the matrix.\n";
			std::cin >> rows >> column;
			std::cout << std::endl;
			A = new Matrix{ rows, column };
			A->input();
			system("cls");
			B = new Matrix{ *A };
		}
		else if (marker == 2)
		{
			int rows, column;
			std::cout << "Enter amount of rows and columns in the first matrix.\n";
			std::cin >> rows >> column;
			std::cout << std::endl;
			A = new Matrix{ rows, column };
			A->input();
			system("cls");
			std::cout << "Enter amount of rows and columns in the second matrix.\n";
			std::cin >> rows >> column;
			std::cout << std::endl;
			B = new Matrix{ rows, column };
			B->input();
			system("cls");
		}
		else
		{
			A = new Matrix;
			B = new Matrix;
			std::cout << "First matrix:" << std::endl;
			A->input();
			system("cls");
			std::cout << "Second matrix:" << std::endl;
			B->input();
			system("cls");

		}

		std::cout << "Your matrix:" << std::endl << std::endl;
		std::cout << "\tA" << std::endl;
		A->output(get_max_space(A->get_space(), B->get_space()));
		std::cout << std::endl << "\tB" << std::endl;
		B->output(get_max_space(A->get_space(), B->get_space()));
		try
		{
			result = new Matrix(A->multiply(B));
			std::cout << std::endl << "\tResult of multiply A*B:" << std::endl;
			result->output(result->get_space() + 2);
		}
		catch (const char* error_message)
		{
			std::cout << error_message << std::endl;
		}
		std::cout << std::endl << "If u want to continue, press 'y'" << std::endl;
	} while (getchar() == 'y');
	return 0;
};
