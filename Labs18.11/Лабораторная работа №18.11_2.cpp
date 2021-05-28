//задача 2
#include <iostream> 
#include <vector> 
#include <ctime>
using namespace std;
class Money {
private:
	long int Rubles;
	int Kopecks;
public:
	Money() {
		Rubles = 0;
		Kopecks = 0;
	}
	Money(const long int& rub, const int& kop) {
		Rubles = rub;
		Kopecks = kop;
	}
	Money(const Money& money) {
		Rubles = money.Rubles;
		Kopecks = money.Kopecks;
	}
	bool operator != (const Money& right) {
		return !((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
	}
	/*void operator = (const double& right) {
		int int_part_of_right_number = right;
		double fractional_part_right_number = right - int_part_of_right_number;
		for (int i = 0; i < Precision; i++)
			fractional_part_right_number *= 10;
		int fract_part_right_number_to_int = round(fractional_part_right_number);
		Rubles = int_part_of_right_number;
		Kopecks = fract_part_right_number_to_int;
	}*/
	bool operator > (const Money& money) {
		if (Rubles > money.Rubles)
			return true;
		if (Rubles >= money.Rubles)
			if (Kopecks > money.Kopecks)
				return true;
		return false;
	}
	friend istream& operator >> (istream& in, Money& money);
	friend ostream& operator << (ostream& out, const Money& money);
	long int get_rubles() {
		return Rubles;
	}
	int get_kopecks() {
		return Kopecks;
	}
	void set_rubles(const long int& rub) {
		Rubles = rub;
	}
	void set_kopecks(const int& kop) {
		Kopecks = kop;
	}
};
//перегрузка операторов ввода-вывода
istream& operator >> (istream& in, Money& money) {
	std::cout << "Введите руб.: ";
	in >> money.Rubles;
	std::cout << "Введите коп.: ";
	in >> money.Kopecks;
	return in;
}
ostream& operator << (ostream& out, const Money& money) {
	double double_Kopecks = money.Kopecks;
	string zero_filler = "";
	if ((double_Kopecks / 10) < 1)
		zero_filler = "0";
	return (out << money.Rubles << ',' << zero_filler << money.Kopecks << " руб.");
}
typedef vector<Money>Vec;//определяем тип для работы с вектором
Vec make_vector(int n) {
	Vec my_vec;
	int a = 0;
	Money money;
	for (int i = 0;i < n;i++)
	{
		a = rand() % 20000;
		money.set_rubles(a);
		a = rand() % 100;
		money.set_kopecks(a);
		my_vec.push_back(money);
	}
	return my_vec;
}
void print_vector(Vec vec)
{
	for (int i = 0;i < vec.size();i++)
		cout << (vec[i]) << endl;
	std::cout << endl;
}
void push_back_max(Vec& vec) {
	Money max_value;
	Money left;
	max_value.set_rubles(INT_MIN);
	max_value.set_kopecks(-99);
	int vec_size = vec.size();
	for (int i = 0; i < vec.size(); i++) {
		left = vec[i];
		if (left > max_value)
			max_value = left;
	}
	Vec temp_vec;
	int i;
	for (i = 0; i < vec_size; i++) {
		if (vec[i] != max_value) 
			temp_vec.push_back(vec[i]);
		else
			break;
	}
	for (int j = i + 1; j < vec_size; j++)
		temp_vec.push_back(vec[j]);
	temp_vec.push_back(max_value);
	vec.clear();
	for (int j = 0; j < vec_size; j++)
		vec.push_back(temp_vec[j]);
	temp_vec.clear();
}
void delete_element(Vec& vec, const Money element) {
	Vec temp_vec;
	int vec_size = vec.size();
	for (int i = 0; i < vec_size; i++)
		if (vec[i] != element)
			temp_vec.push_back(vec[i]);
	vec_size = temp_vec.size();
	vec.clear();
	for (int i = 0; i < vec_size; i++)
		vec.push_back(temp_vec[i]);
	temp_vec.clear();
}
Money increase_values_on_arithmetical_mean(Vec& vec) {
	Money arithmetical_mean;
	int sum_rub = 0, sum_kopecks = 0;
	int vec_size = vec.size();
	for (int i = 0; i < vec_size; i++) {
		sum_rub += vec[i].get_rubles();
		sum_kopecks += vec[i].get_kopecks();
	}
	arithmetical_mean.set_rubles(sum_rub / vec_size);
	arithmetical_mean.set_kopecks(sum_kopecks / vec_size);
	for (int i = 0; i < vec_size; i++) {
		vec[i].set_rubles(vec[i].get_rubles() + arithmetical_mean.get_rubles());
		if (vec[i].get_kopecks() + arithmetical_mean.get_kopecks() >= 100) {
			vec[i].set_rubles(vec[i].get_rubles() + 1);
			vec[i].set_kopecks(vec[i].get_kopecks() + arithmetical_mean.get_kopecks() - 100);
		}
		else
			vec[i].set_kopecks(vec[i].get_kopecks() + arithmetical_mean.get_kopecks());
	}
	return arithmetical_mean;
}
void main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	vector<Money> vecOfMoney;
	int n;
	cout << "Введите количество элементов в векторе: ";
	cin >> n;
	vecOfMoney = make_vector(n);
	cout << "Элементы сформировались случайным образом:\n";
	print_vector(vecOfMoney);
	push_back_max(vecOfMoney);
	cout << "\nМаксимальный элемент помещен в конец вектора:\n";
	print_vector(vecOfMoney);
	Money value_for_deleting;
	cout << "\nВведите элемент, который хотите удалить:\n";
	cin >> value_for_deleting;
	delete_element(vecOfMoney, value_for_deleting);
	cout << "Содержимое вектора после удаления элемента(ов):\n";
	print_vector(vecOfMoney);
	cout << "\nСодержимое вектора после увеличения значений на среднее арифметическое всех элементов:\n";
	Money arithm_mean = increase_values_on_arithmetical_mean(vecOfMoney);
	cout << "Среднее арифметическое = " << arithm_mean << endl;
	print_vector(vecOfMoney);
	return;
}
