#include <iostream>
using namespace std;
struct QueueForSymbols {
	char* String;
	QueueForSymbols* Next;
};
QueueForSymbols* queueOfSymbols;
int sizeOfQueue;
char symbols[256];
void push(QueueForSymbols*& first_element, char element[]) {
	QueueForSymbols* ptr_on_first_element = first_element;
	if (first_element == NULL) {
		first_element = new QueueForSymbols;
		first_element->String = new char[strlen(element)];
		strcpy(first_element->String, element);
		first_element->Next = NULL;
		return;
	}
	while (first_element->Next != NULL)
		first_element = first_element->Next;
	QueueForSymbols* new_string = new QueueForSymbols;
	new_string->String = new char[strlen(symbols)];
	strcpy(new_string->String, element);
	new_string->Next = NULL;
	first_element->Next = new_string;
	first_element = ptr_on_first_element;
}
void pop(QueueForSymbols*& first_element) {
	QueueForSymbols* deleting_element = first_element;
	first_element = first_element->Next;
	delete deleting_element;
}
void print(QueueForSymbols* &first_element) {
	QueueForSymbols* temp_queue = NULL;
	if (first_element == NULL) {
		cout << "В очереди нет элементов\n";
		return;
	}
	cout << "Содержимое очереди:\n";
	while (first_element != NULL) {
		cout << first_element->String << endl;
		push(temp_queue, first_element->String);
		pop(first_element);
	}
	while (temp_queue != NULL) {
		push(first_element, temp_queue->String);
		pop(temp_queue);
	}
}
void add_elements_in_odd_spots(QueueForSymbols*& first_element) {
	int amountOfOddSpots = 0;
	for (int i = 1; i <= sizeOfQueue; i++)
		if (i % 2 != 0)
			amountOfOddSpots++;
	QueueForSymbols* queue_with_extra_elements = NULL;
	for (int i = 0; i < amountOfOddSpots; i++) {
		memset(symbols, 0, sizeof symbols);
		cout << "Введите элемент: ";
		cin >> symbols;
		push(queue_with_extra_elements, symbols);
		push(queue_with_extra_elements, first_element->String);
		pop(first_element);
	}
	while (first_element != NULL) {
		push(queue_with_extra_elements, first_element->String);
		pop(first_element);
	}
	while (queue_with_extra_elements != NULL) {
		push(first_element, queue_with_extra_elements->String);
		pop(queue_with_extra_elements);
	}
}
void clear(QueueForSymbols* &first_element) {
	while (first_element != NULL)
		pop(first_element);
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
		memset(symbols, 0, sizeof symbols);
		cout << i + 1 << ") ";
		cin >> symbols;
		push(queueOfSymbols, symbols);
	}
	print(queueOfSymbols);
	add_elements_in_odd_spots(queueOfSymbols);
	cout << "Содержимое очереди после вставки элементов на нечетные места:\n";
	print(queueOfSymbols);
	clear(queueOfSymbols);
	cout << "Содержимое очереди после удаления всех элементов:\n";
	print(queueOfSymbols);
	system("pause");
	return 0;
}