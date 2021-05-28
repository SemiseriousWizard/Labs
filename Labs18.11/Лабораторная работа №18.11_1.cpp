//задача 1
#include <iostream> 
#include <deque> 
#include <cstdlib> 
#include <ctime>
using namespace std;
typedef deque<int>Deq;//определяем тип для работы с деком
Deq make_deque(int n) { 
	Deq my_deque;
	int a = 0;
	for(int i=0;i<n;i++)
	{
		a = rand() % 100 - 50; 
		my_deque.push_back(a);
	}
	return my_deque;
} 
void print_deque(Deq deq)
{
	for (int i = 0;i < deq.size();i++) 
		cout << deq[i] << " ";
	cout << endl;
}
void push_back_max(Deq& deq) {
	int max_value = INT_MIN;
	for (int i = 0; i < deq.size(); i++)
		if (deq[i] > max_value)
			max_value = deq[i];
	Deq temp_deq;
	int i, deq_size = deq.size();
	for (i = 0; i < deq_size; i++) {
		if (deq[0] != max_value) {
			temp_deq.push_back(deq[0])
				;
			deq.pop_front();
		}
		else
			break;
	}
	deq.pop_front();
	deq_size = deq.size();
	for (int j = 0; j < deq_size; j++) {
		temp_deq.push_back(deq[0]);
		deq.pop_front();
	}
	temp_deq.push_back(max_value);
	deq_size = temp_deq.size();
	for (int j = 0; j < deq_size; j++) {
		deq.push_back(temp_deq[0]);
		temp_deq.pop_front();
	}
}
void delete_element(Deq& deq, const int element) {
	Deq temp_deq;
	int deq_size = deq.size();
	for (int i = 0; i < deq_size; i++)
		if (deq[i] != element)
			temp_deq.push_back(deq[i]);
	for (int i = 0; i < deq_size; i++)
		deq.pop_front();
	deq_size = temp_deq.size();
	for (int i = 0; i < deq_size; i++) {
		deq.push_back(temp_deq[0]);
		temp_deq.pop_front();
	}
}
int increase_values_on_arithmetical_mean(Deq& deq) {
	int arithmetical_mean = 0, sum = 0;
	int deq_size = deq.size();
	for (int i = 0; i < deq_size; i++)
		sum += deq[i];
	arithmetical_mean = sum / deq_size;
	for (int i = 0; i < deq_size; i++)
		deq[i] += arithmetical_mean;
	return arithmetical_mean;
}
void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	deque<int> dequeOfIntNumbers;
	int n;
	cout << "Введите количество элементов в двунаправленной очереди: ";
	cin >> n;
	dequeOfIntNumbers = make_deque(n);
	cout << "Элементы сформировались случайным образом:\n";
	print_deque(dequeOfIntNumbers);
	push_back_max(dequeOfIntNumbers);
	cout << "\nМаксимальный элемент помещен в конец двунаправленной очереди:\n";
	print_deque(dequeOfIntNumbers);
	int value_for_deleting;
	cout << "\nВведите элемент, который хотите удалить: ";
	cin >> value_for_deleting;
	delete_element(dequeOfIntNumbers, value_for_deleting);
	cout << "Содержимое двунаправленной очереди после удаления элемента(ов):\n";
	print_deque(dequeOfIntNumbers);
	cout << "\nСодержимое двунаправленной очереди после увеличения значений на среднее арифметическое всех элементов:\n";
	int arithm_mean = increase_values_on_arithmetical_mean(dequeOfIntNumbers);
	cout << "Среднее арифметическое = " << arithm_mean << endl;
	print_deque(dequeOfIntNumbers);
	return;
}
