#include "input_function.h"
void enter_str(char* str, int size, FILE* stream)
{
    rewind(stdin);
    fgets(str, size, stream);
    for (int j = 0; j < strlen(str) + 1; j++)
    {
        if (str[j] == '\n') {
            str[j] = '\0';
        }
    }
}
void enter_int(long int* num)
{
    int val;
    while (true) {
        val = scanf_s("%d", num);

        if (val == 1) {
            if (getchar() != '\n') {
                std::cout << "Invalid input." << std::endl;

                while (getchar() != '\n'); // ������� ���������� �������
                continue; // ������������ � ������ �����
            }
            break;
        }
        else {
            std::cout << "Invalid input\n";
            // ������� ����
            while (getchar() != '\n'); // ������� �����, ���� �� ��������� ����� ������
        }
    }

}
void enter_type(int* num)
{
    int val;
    do {
        rewind(stdin);
        val = scanf_s("%d", num);
        if (!val || (*num != 1 && *num != 2 && *num != 3))
            printf("Invail input.\n");
    } while (!val || (*num != 1 && *num != 2 && *num != 3));
}
