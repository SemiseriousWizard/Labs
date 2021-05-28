#include <iostream>
#include "Set.h"
#include "Error.h"
using namespace std;
void check_int_var(int number) {
	if (cin.fail())
		throw "incorrect_int_input";
}
int main()
{
    setlocale(LC_ALL, "");
    try {
		cout << "Введите количество элементов во множестве: ";
		int sizeOfSet, number;
		cin >> sizeOfSet;
		check_int_var(sizeOfSet);
		Set myset1(sizeOfSet);
		cout << "Введите числа" << endl;
		for (int i = 0; i < sizeOfSet; i++) {
			cout << i + 1 << ") ";
			cin >> number;
			check_int_var(sizeOfSet);
			myset1.Add(number, i);
		}
		//демонстрация работы оператора []
		cout << "Проверка оператора []" << endl;
		cout << "Содержимое множества:" << endl;
		for (int i = 0; i < sizeOfSet; i++)
			cout << i + 1 << ") " << myset1[i] << endl;
		//демонстрация работы оператора <
		cout << endl;
		cout << "Проверка оператора <" << endl;
		cout << "Введите число: ";
		cin >> number;
		check_int_var(sizeOfSet);
		if (myset1 < number)
			cout << number << " содержится во множестве" << endl;
		else
			cout << number << " нет во множестве" << endl;
		//демонстрация работы оператора !=
		int index1, index2;
		cout << endl;
		cout << "Проверка оператора !=" << endl;
		cout << "Введите индекс первого элемента: ";
		cin >> index1;
		check_int_var(sizeOfSet);
		cout << "Содержимое ячейки: " << myset1[index1] << endl;
		cout << "Введите индекс второго элемента: ";
		cin >> index2;
		check_int_var(sizeOfSet);
		cout << "Содержимое ячейки: " << myset1[index2] << endl;
		cout << myset1[index1] << " != " << myset1[index2] <<
			" = " << (myset1[index1] != myset1[index2]) << endl;
		//демонстрация работы оператора +n
		cout << endl;
		cout << "Проверка оператора +n" << endl;
		myset1.indexleft = 0;
		cout << "Содержимое нулевой ячейки множества: " << myset1[0] << endl;
		cout << "Введите индекс элемента множества: ";
		cin >> index1;
		check_int_var(sizeOfSet);
		cout << "Содержимое ячейки множества с номером " << index1 << " равно " << myset1[index1] << endl;
		myset1 + index1;
		cout << "Содержимое нулевой ячейки множества: " << myset1[0] << endl;
    }
    catch (Error &error) {
        error.what();
    }
	catch (const char*) {
		cout << "Произошла попытка ввода символа(ов) вместо числа" << endl;
	}
    return 0;
}
