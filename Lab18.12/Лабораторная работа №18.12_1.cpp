#include <iostream>
#include <set>
#include <vector>
using namespace std;
template <class T>
class Vector
{
	typedef set<T, less<T>> tset;
	tset Set;
	int size;
public:
	Vector() {
		size = 0;
	};
	Vector(int n) {
		size = n;
	};
	tset& make_set(int n) {
		T a = 0;
		for (int i = 0;i < n;i++)
		{
			cout << i + 1 << ") ";
			cin >> a;
			Set.insert(a);
		}
		return Set;
	}
	void print_set()
	{
		if (Set.size() == 0) {
			cout << "Множество пустое\n";
			return;
		}
		typename tset::iterator i;
		for (i = Set.begin(); i != Set.end(); i++)
			cout << *i << endl;
	}
	void delete_element(const T element) {
		Set.erase(element);
	}
	T increase_values_on_arithmetical_mean() {
		if (Set.size() == 0) {
			cout << "Множество пустое" << endl;
			return 0;
		}
		T sum = 0;
		typename tset::iterator i;
		vector<T> temp_vector;
		for (i = Set.begin(); i != Set.end(); i++) {
			temp_vector.push_back(*i);
			sum += (*i);
		}
		T arithmetical_mean = sum / Set.size();
		for (int j = 0; j < temp_vector.size(); j++)
			temp_vector[j] += arithmetical_mean;
		Set.clear();
		for (int j = 0; j < temp_vector.size(); j++)
			Set.insert(temp_vector[j]);
		temp_vector.clear();
		return arithmetical_mean;
	}
	~Vector() {
		size = 0;
		Set.clear();
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
	myvector1.make_set(size);
	cout << "Максимальный элемент добавлен в конец вектора:" << endl;
	cout << "Содержимое вектора:" << endl;
	myvector1.print_set();
	cout << endl;
	cout << "Введите элемент, который хотите удалить: ";
	int element_del1;
	cin >> element_del1;
	myvector1.delete_element(element_del1);
	cout << "Содержимое вектора после удаления элементов:" << endl;
	myvector1.print_set();
	cout << endl;
	cout << "Содержимое вектора после увеличения значений на среднее арифметическое всех элементов:" << endl;
	cout << "Сред. арифм. = " << myvector1.increase_values_on_arithmetical_mean() << endl << endl;
	cout << "Содержимое вектора:" << endl;
	myvector1.print_set();
	/*====================================================*/
	/*====================     double     ======================*/
	cout << "Работа с типом double:" << endl;
	cout << "Введите количество элементов в векторе: ";
	cin >> size;
	Vector<double> myvector2(size);
	cout << "Введите элементы:" << endl;
	myvector2.make_set(size);
	cout << "Максимальный элемент добавлен в конец вектора:" << endl;
	cout << "Содержимое вектора:" << endl;
	myvector2.print_set();
	cout << endl;
	cout << "Введите элемент, который хотите удалить: ";
	double element_del2;
	cin >> element_del2;
	myvector2.delete_element(element_del2);
	cout << "Содержимое вектора после удаления элементов:" << endl;
	myvector2.print_set();
	cout << endl;
	cout << "Содержимое вектора после увеличения значений на среднее арифметическое всех элементов:" << endl;
	cout << "Сред. арифм. = " << myvector2.increase_values_on_arithmetical_mean() << endl << endl;
	cout << "Содержимое вектора:" << endl;
	myvector2.print_set();
	/*====================================================*/
	return;
}
