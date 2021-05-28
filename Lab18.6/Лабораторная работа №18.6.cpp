#include <iostream>
#include "Set.h"
#include "Iterator.h"
using namespace std;
int main()
{   //set: конструкторы, ввод-вывод, [], =, !=, <
    //iterator: ++, --, +, -, ==, !=, *
	setlocale(LC_ALL, "");
	int set_size;
	cout << "Демонстрация работы с операторами класса Set:\n";
	cout << "Введите количество элементов во множестве: ";
	cin >> set_size;
	Set set_of_numbers(set_size);
	if (set_size > 0) {
		cout << "Введите элементы множества:" << endl;
		cin >> set_of_numbers;
		cout << "Содержимое множества:" << endl;
		cout << set_of_numbers;
		int set_index1, set_index2;
		/////////////////////////////
		cout << "Введите индекс для левого операнда:" << endl;
		cin >> set_index1;
		if (set_index1 < 0 || set_index1 >= set_size)
			return 0;
		cout << "Содержимое ячейки множества с индексом " << set_index1 << " = " << set_of_numbers[set_index1] << endl;
		cout << "Введите индекс для правого операнда:" << endl;
		cin >> set_index2;
		if (set_index2 < 0 || set_index2 >= set_size)
			return 0;
		cout << "Содержимое ячейки множества с индексом " << set_index2 << " = " << set_of_numbers[set_index2] << endl;
		cout << set_of_numbers[set_index1] << " != " << set_of_numbers[set_index2] << " = "
				<< (set_of_numbers[set_index1] != set_of_numbers[set_index2]) << endl;
		////////////////////////////////
		int number;
		cout << "Введите число: ";
		cin >> number;
		if (set_of_numbers < number)
			cout << number << " содержится во множестве" << endl;
		else
			cout << number << " отсутствует во множестве" << endl;
		/////////////////////////////////
		cout << "Вызов конструктора копирования:" << endl;
		Set set_of_numbers2(set_of_numbers);
		cout << "Содержимое второго множества:\n";
		cout << set_of_numbers2;
		cout << "Использование оператора =" << endl;
		Set set_of_numbers3(1);
		set_of_numbers3 = set_of_numbers;
		cout << "Содержимое третьего множества:\n";
		cout << set_of_numbers3;
		/////////////////////////////////
		cout << "Демонстрация работы с операторами класса Iterator:\n";
		//iterator: ++, --, +, -, ==, !=, *
		Iterator iterator;
		int index = 1;
		cout << "Вывод содержимого множества в прямом порядке: " << endl;
		for (iterator = set_of_numbers.first(); iterator != set_of_numbers.last(); ++iterator) {
			cout << index++ << ") " << *iterator << endl;
		}
		////////////////////////////////////
		cout << "Вывод содержимого множества в обратном порядке: " << endl;
		Iterator last_element_iterator = iterator;
		--last_element_iterator;
		Iterator first_element_iterator = set_of_numbers.first();
		--first_element_iterator;
		for (iterator = last_element_iterator; iterator != first_element_iterator; --iterator) {
			cout << --index << ") " << *iterator << endl;
		}
		//////////////////////////////////////
		Iterator iterator1 = set_of_numbers.first(), iterator2;
		cout << "Демонстрация работы операторов +n, -n" << endl;
		cout << "Текущее значение итератора: " << *iterator1 << endl;
		int offset;
		cout << "Введите количество переходов вправо: ";
		cin >> offset;
		iterator1 + offset;
		cout << "Новое значение итератора: " << *iterator1 << endl;
		iterator1 - offset;
		cout << "Исходное значение итератора: " << *iterator1 << endl;
		////////////////////////////////////////
		cout << "Демонстрация работы операторов != и ==" << endl;
		cout << "Введите индекс левого операнда: ";
		cin >> set_index1;
		cout << "Введите индекс правого операнда: ";
		cin >> set_index2;
		iterator1 = set_of_numbers.first();
		iterator2 = set_of_numbers.first();
		iterator1 + set_index1;
		iterator2 + set_index2;
		cout << *iterator1 << " != " << *iterator2 << " = " << (iterator1 != iterator2) << endl;
		cout << *iterator1 << " == " << *iterator2 << " = " << (iterator1 == iterator2) << endl;
	}
	system("pause");
	return 0;
}
