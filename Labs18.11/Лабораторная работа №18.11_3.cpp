//задача 3
//создаю класс Вектор, который может работать с шаблонами
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
template <class T>
class Vector
{
	vector <T> vec;//последовательный контейнер для хранения элементов вектора 
	int size;
public:
	Vector() {
		size = 0;
	};
	Vector(int n) {
		size = n;
	};
	vector<T>& make_vector(int n) {
		T a = 0;
		for (int i = 0;i < n;i++)
		{
			cout << i + 1 << ") ";
			cin >> a;
			vec.push_back(a);
		}
		return vec;
	}
	void print_vector()
	{
		if (size == 0) {
			cout << "Вектор пуст\n";
			return;
		}
		for (int i = 0;i < size;i++)
			cout << (vec[i]) << endl;
	}
	void push_back_max() {
		T max_value = INT_MIN;
		for (int i = 0; i < size; i++) {
			if (vec[i] > max_value)
				max_value = vec[i];
		}
		vector<T> temp_vec;
		int i;
		for (i = 0; i < size; i++) {
			if (vec[i] != max_value)
				temp_vec.push_back(vec[i]);
			else
				break;
		}
		for (int j = i + 1; j < size; j++)
			temp_vec.push_back(vec[j]);
		temp_vec.push_back(max_value);
		vec.clear();
		for (int j = 0; j < size; j++)
			vec.push_back(temp_vec[j]);
		temp_vec.clear();
	}
	void delete_element(const T element) {
		vector<T> temp_vec;
		for (int i = 0; i < size; i++)
			if (vec[i] != element)
				temp_vec.push_back(vec[i]);
		size = temp_vec.size();
		vec.clear();
		for (int i = 0; i < size; i++)
			vec.push_back(temp_vec[i]);
		temp_vec.clear();
	}
	T increase_values_on_arithmetical_mean() {
		if (size == 0) {
			cout << "Вектор пуст/n";
			return 0;
		}
		T sum = 0;
		for (int i = 0; i < size; i++)
			sum += vec[i];
		T arithmetical_mean = sum / size;
		for (int i = 0; i < size; i++)
			vec[i] += arithmetical_mean;
		return arithmetical_mean;
	}
	~Vector() {
		size = 0;
		vec.clear();
	}
};
void main()	
{
	setlocale(LC_ALL, "");
	srand(time(0));
	/*====================     int     ======================*/
	cout << "Работа с типом int:" << endl;
	cout << "Введите количество элементов в векторе: ";
	int size;
	cin >> size;
	Vector<int> myvector1(size);
	cout << "Введите элементы:" << endl;
	myvector1.make_vector(size);
	cout << "Содержимое вектора:" << endl;
	myvector1.print_vector();
	cout << endl;
	myvector1.push_back_max();
	cout << "Содержимое вектора после вставки в конец максимального элемента:" << endl;
	myvector1.print_vector();
	cout << endl;
	cout << "Введите элемент, который хотите удалить: ";
	int element_del1;
	cin >> element_del1;
	myvector1.delete_element(element_del1);
	cout << "Содержимое вектора после удаления элементов:" << endl;
	myvector1.print_vector();
	cout << endl;
	cout << "Содержимое вектора после увеличения значений на среднее арифметическое всех элементов:" << endl;
	cout << "Сред. арифм. = " << myvector1.increase_values_on_arithmetical_mean() << endl << endl;
	cout << "Содержимое ветора:" << endl;
	myvector1.print_vector();
	/*====================================================*/
	/*====================     double     ======================*/
	cout << "Работа с типом double:" << endl;
	cout << "Введите количество элементов в векторе: ";
	cin >> size;
	Vector<double> myvector2(size);
	cout << "Введите элементы:" << endl;
	myvector2.make_vector(size);
	cout << "Содержимое вектора:" << endl;
	myvector2.print_vector();
	cout << endl;
	myvector2.push_back_max();
	cout << "Содержимое вектора после вставки в конец максимального элемента:" << endl;
	myvector2.print_vector();
	cout << endl;
	cout << "Введите элемент, который хотите удалить: ";
	double element_del2;
	cin >> element_del2;
	myvector2.delete_element(element_del2);
	cout << "Содержимое вектора после удаления элементов:" << endl;
	myvector2.print_vector();
	cout << endl;
	cout << "Содержимое вектора после увеличения значений на среднее арифметическое всех элементов:" << endl;
	cout << "Сред. арифм. = " << myvector2.increase_values_on_arithmetical_mean() << endl << endl;
	cout << "Содержимое ветора:" << endl;
	myvector2.print_vector();
	/*====================================================*/
	return;
}