#include <iostream>
#include "TRIAD.h"
using namespace std;
class TIME:public TRIAD {
public:
	TIME():TRIAD(){}
	TIME(const int& hours, const int& minutes, const int& seconds) {
		set_hours(hours);
		set_minutes(minutes);
		set_seconds(seconds);
	}
	TIME(const TIME& time):TRIAD(time){}
	void correct_time_format() {
		int save_seconds = third;
		third %= 60;
		second += (save_seconds / 60);
		int save_minutes = second;
		second %= 60;
		first += (save_minutes / 60);
	}
	//модификаторы
	void set_hours(const int& hours) { first = hours; }
	void set_minutes(const int& minutes) { second = minutes; }
	void set_seconds(const int& seconds) { 
		third = seconds;
		correct_time_format();
	}
	//селекторы
	int& get_hours() { return first; }
	int& get_minutes() { return second; }
	int& get_seconds() { return third; }
	TIME& operator = (const TIME& time) {
		cout << "Вызов оператора присваивания" << endl;
		if (&time == this)
			return *this;
		first = time.first;
		second = time.second;
		third = time.third;
		return *this;
	}
	friend ostream& operator << (ostream& out, const TIME& time) {
		return (out << time.first << " ч. " << time.second << " мин. " << time.third << " сек. ");
	}
	friend istream& operator >> (istream& in, TIME& time) {
		cout << "Кол-во часов: ";
		in >> time.first;
		cout << "Кол-во минут: ";
		in >> time.second;
		cout << "Кол-во секунд: ";
		in >> time.third;
		return in;
	}
	//операторы сравнения ==, !=, >, >=, <, <=
	bool operator == (const TIME& time) {
		return ((first == time.first) && (second == time.second) && (third == time.third));
	}
	bool operator != (const TIME& time) {
		return !((first == time.first) && (second == time.second) && (third == time.third));
	}
	bool operator > (const TIME& time) {
		return (first > time.first || (first == time.first && 
			(second > time.second || (second == time.second && third > time.third))));
	}
	bool operator >= (const TIME& time) {
		bool result = false;
		return (first > time.first || (first == time.first && 
			(second > time.second || (second == time.second && third >= time.third))));
	}
	bool operator < (const TIME& time) {
		return (first < time.first || (first == time.first && 
			(second < time.second || (second == time.second && third < time.third))));
	}
	bool operator <= (const TIME& time) {
		return (first < time.first || (first == time.first && 
			(second < time.second || (second == time.second && third <= time.third))));
	}
};
void set_TRIAD_object_for_TIME_object (TRIAD& triad) {
	cout << "Изменение количества часов:" << endl;
	triad.set_first(11);
}
TRIAD& get_TIME_object_for_TRIAD_object() {
	TIME *time = new TIME(23, 21, 25);
	return *time;
}
int main()
{
	setlocale(LC_ALL, "");
	cout << "================Класс TRIAD=====================" << endl;
	TRIAD tr1;
	cout << "Вызов конструктора без параметров:" << endl;
	cout << tr1 << endl;
	cout << "Вызов конструктора с параметрами:" << endl;
	TRIAD tr2(121, 16, 218);
	cout << tr2 << endl;
	cout << "Вызов конструктора копирования:" << endl;
	TRIAD tr3(tr2);
	cout << tr3 << endl;
	cout << "Демонстрация работы модификаторов и селекторов:" << endl;
	TRIAD tr4;
	tr4.set_first(178);
	tr4.set_second(333);
	tr4.set_third(777);
	cout << tr4.get_first() << endl;
	cout << tr4.get_second() << endl;
	cout << tr4.get_third() << endl;
	cout << "Демонстрация работы операторов ввода-вывода:" << endl;
	TRIAD tr5;
	cin >> tr5;
	cout << "Содержимое объекта:" << endl;
	cout << tr5 << endl;
	cout << "Демонстрация работы операторов сравнения:" << endl;
	TRIAD tr6, tr7;
	cout << "Введите первую триаду:" << endl;
	cin >> tr6;
	cout << "Введите вторую триаду:" << endl;
	cin >> tr7;
	cout << '(' << tr6 << ") == (" << tr7 << ") = ";
	cout << (tr6 == tr7) << endl;
	cout << '(' << tr6 << ") != (" << tr7 << ") = ";
	cout << (tr6 != tr7) << endl;
	cout << '(' << tr6 << ") > (" << tr7 << ") = ";
	cout << (tr6 > tr7) << endl;
	cout << '(' << tr6 << ") >= (" << tr7 << ") = ";
	cout << (tr6 >= tr7) << endl;
	cout << '(' << tr6 << ") < (" << tr7 << ") = ";
	cout << (tr6 < tr7) << endl;
	cout << '(' << tr6 << ") <= (" << tr7 << ") = ";
	cout << (tr6 <= tr7) << endl;
	cout << "================Класс TIME=====================" << endl;
	TIME time1;
	cout << "Вызов конструктора без параметров:" << endl;
	cout << time1 << endl;
	cout << "Вызов конструктора с параметрами:" << endl;
	TIME time2(121, 16, 218);
	cout << time2 << endl;
	cout << "Вызов конструктора копирования:" << endl;
	TIME time3(time2);
	cout << time3 << endl;
	cout << "Демонстрация работы модификаторов и селекторов:" << endl;
	TIME time4;
	time4.set_hours(178);
	time4.set_minutes(333);
	time4.set_seconds(777);
	cout << time4.get_hours() << " ч." << endl;
	cout << time4.get_minutes() << " мин." << endl;
	cout << time4.get_seconds() << " сек." << endl;
	cout << "Демонстрация работы операторов ввода-вывода:" << endl;
	TIME time5;
	cin >> time5;
	time5.correct_time_format();
	cout << "Содержимое объекта:" << endl;
	cout << time5 << endl;
	cout << "Демонстрация работы операторов сравнения:" << endl;
	TIME time6, time7;
	cout << "Введите время:" << endl;
	cin >> time6;
	cout << "Введите время:" << endl;
	cin >> time7;
	time6.correct_time_format();
	time7.correct_time_format();
	cout << '(' << time6 << ") == (" << time7 << ") = ";
	cout << (time6 == time7) << endl;
	cout << '(' << time6 << ") != (" << time7 << ") = ";
	cout << (time6 != time7) << endl;
	cout << '(' << time6 << ") > (" << time7 << ") = ";
	cout << (time6 > time7) << endl;
	cout << '(' << time6 << ") >= (" << time7 << ") = ";
	cout << (time6 >= time7) << endl;
	cout << '(' << time6 << ") < (" << time7 << ") = ";
	cout << (time6 < time7) << endl;
	cout << '(' << time6 << ") <= (" << time7 << ") = ";
	cout << (time6 <= time7) << endl;
	cout << endl;
	//принцип подстановки
	cout << "Принцип подстановки:" << endl;
	TIME t8;
	cout << t8 << " - до вызова функции" << endl;
	set_TRIAD_object_for_TIME_object(t8);
	cout << t8 << " - после вызова функции" << endl;
	TRIAD baseClassObject;
	cout << endl;
	cout << "Содержимое базового класса до вызова функции:" << endl;
	cout << baseClassObject << endl;
	baseClassObject = get_TIME_object_for_TRIAD_object();
	cout << "Содержимое класса после вызова функции:" << endl;
	cout << baseClassObject << endl;
	system("pause");
	return 0;
}
