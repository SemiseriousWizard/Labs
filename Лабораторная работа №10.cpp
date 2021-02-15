#include <iostream>
using namespace std;
int amountOfRows, amountOfCols;
int** matrix;
void init_column(int** &array, int index_column) {
    for (int i = 0; i < amountOfRows; i++)
        array[i][index_column] = rand() % 20;
}
void create_and_init_row(int** &array, int index_row) {
    array[index_row] = new int[amountOfCols];
    for (int j = 0; j < amountOfCols; j++)
        array[index_row][j] = rand() % 20;
}
void print_array(int** array) {
    for (int i = 0; i< amountOfRows; i++)
    {
        for (int j = 0; j < amountOfCols; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}
void delete_matrix(int** &array, int rows) {
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}
void insert_new_column(int** &array, int index_column) {
    int** matrix_copy = new int* [amountOfRows];
    for (int i = 0; i < amountOfRows; i++)
        matrix_copy[i] = new int[amountOfCols + 1];
    for (int i = 0; i < amountOfRows; i++)
        for (int j = 0; j < index_column; j++)
            matrix_copy[i][j] = array[i][j];
    init_column(matrix_copy, index_column);
    for (int i = 0; i < amountOfRows; i++)
        for (int j = index_column; j < amountOfCols; j++)
            matrix_copy[i][j + 1] = array[i][j];
    amountOfCols++;
    delete_matrix(array, amountOfRows);
    array = new int* [amountOfRows];
    for (int i = 0; i < amountOfRows; i++)
        array[i] = new int[amountOfCols];
    for (int i = 0; i < amountOfRows; i++)
        for (int j = 0; j < amountOfCols; j++)
            array[i][j] = matrix_copy[i][j];
    delete_matrix(matrix_copy, amountOfRows);
}
void provide_input_positive_number(int& number) {
    do {
        cin >> number;
        if (number < 1)
            cout << "Введите положительное число!\n";
    } while (number < 1);
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите размер массива\n";
    cout << "Введите количество строк: ";
    provide_input_positive_number(amountOfRows);
    matrix = new int* [amountOfRows];
    cout << "Введите количество столбцов: ";  
    provide_input_positive_number(amountOfCols);
    for (int i = 0; i < amountOfRows; i++)
        create_and_init_row(matrix, i);
    cout << "Исходный массив:\n";
    print_array(matrix);
    int new_column_index;
    do {
        cout << "Введите индекс для вставки нового столбца (от 0 до " << amountOfCols << "): ";
        cin >> new_column_index;
    } while ((new_column_index < 0) || (new_column_index > amountOfCols));
    insert_new_column(matrix, new_column_index);
    cout << "Массив после вставки нового столбца:\n";
    print_array(matrix);
    delete_matrix(matrix, amountOfRows);
    system("pause");
    return 0;
}