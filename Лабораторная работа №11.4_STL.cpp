#include <iostream>
#include <queue>
using namespace std;
queue<const char*> queueForSymbols;
queue<const char*> temp_queue;
int sizeOfQueue;
string str_data;
char* symbols;
void print(queue<const char*>& first_element) {
	if (first_element.empty()) {
		cout << "В очереди нет элементов\n";
		return;
	}
	cout << "Содержимое очереди:\n";
	while (!first_element.empty()) {
		cout << first_element.front() << endl;
		temp_queue.push(first_element.front());
		first_element.pop();
		
	}
	while (!temp_queue.empty()) {
		first_element.push(temp_queue.front());
		temp_queue.pop();
	}
}
void add_elements_in_odd_spots(queue<const char*>& first_element) {
	int amountOfOddSpots = 0;
	for (int i = 1; i <= sizeOfQueue; i++)
		if (i % 2 != 0)
			amountOfOddSpots++;
	for (int i = 0; i < amountOfOddSpots; i++) {
		cout << "Введите элемент: ";
		cin >> str_data;
		symbols = new char[str_data.length() + 1];
		strcpy(symbols, str_data.c_str());
		temp_queue.push(symbols);
		temp_queue.push(first_element.front());
		first_element.pop();
	}
	while (!first_element.empty()) {
		temp_queue.push(first_element.front());
		first_element.pop();
	}
	while (!temp_queue.empty()) {
		first_element.push(temp_queue.front());
		temp_queue.pop();
	}
}
void clear(queue<const char*>& first_element) {
	while (!first_element.empty())
		first_element.pop();
}
int main() {
	setlocale(LC_ALL, "");
	cout << "Введите количество элементов в очереди: ";
	do {
		cin >> sizeOfQueue;
		if (sizeOfQueue < 1)
			cout << "Количество элементов должно быть больше 0\n";
	} while (sizeOfQueue < 1);
	cout << "Введите элементы для вставки в очередь:\n";
	for (int i = 0; i < sizeOfQueue; i++) {
		cout << i + 1 << ") ";
		cin >> str_data;
		symbols = new char[str_data.length() + 1];
		strcpy(symbols, str_data.c_str());
		queueForSymbols.push(symbols);
	
	}
	print(queueForSymbols);
	add_elements_in_odd_spots(queueForSymbols);
	cout << "Содержимое очереди после вставки элементов на нечетные места:\n";
	print(queueForSymbols);
	clear(queueForSymbols);
	cout << "Содержимое очереди после удаления всех элементов:\n";
	print(queueForSymbols);
	system("pause");
	return 0;
}