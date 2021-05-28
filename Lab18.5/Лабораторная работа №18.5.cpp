#include <iostream>
#include "Object.h"
#include "TRIAD.h"
#include "Vector.h"
using namespace std;
class TIME :public TRIAD {
public:
	TIME() :TRIAD() {}
	TIME(const int& hours, const int& minutes, const int& seconds) {
		set_hours(hours);
		set_minutes(minutes);
		set_seconds(seconds);
	}
	TIME(const TIME& time) :TRIAD(time) {}
	~TIME(){}
	void correct_time_format() {
		int save_seconds = third;
		third %= 60;
		second += (save_seconds / 60);
		int save_minutes = second;
		second %= 60;
		first += (save_minutes / 60);
	}
	void show() {
		cout << first << " ч. " << second << " мин. " << third << " сек. " << endl;
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
		/*bool result = false;
		if (first > time.first)

		return ((first > time.first) || ((first == time.first) && (second > time.second)) ||
			((first == time.first) && (second == time.second) && (third > time.third)));*/
		return (first > time.first || (first == time.first &&
			(second > time.second || (second == time.second && third > time.third))));
	}
	bool operator >= (const TIME& time) {
		bool result = false;
		/*if (first > time.first)
			result = true;
		else if (first == time.first)
			if (second > time.second || (second == time.second && third >= time.third))
				result = true;
		return result;*/
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
void set_TRIAD_object_for_TIME_object(TRIAD& triad) {
	cout << "Изменение количества часов:" << endl;
	triad.set_first(11);
}
TRIAD& get_TIME_object_for_TRIAD_object() {
	TIME* time = new TIME(23, 21, 25);
	return *time;
}
int main()
{
	setlocale(LC_ALL, "");
	Vector v(5);
	TRIAD triad1;
	cout << "Введите триаду:" << endl;
	cin >> triad1;
	TIME time1;
	cout << "Введите время:" << endl;
	cin >> time1;
	time1.correct_time_format();
	TIME time2;
	cout << "Введите время:" << endl;
	cin >> time2;
	time2.correct_time_format();
	cout << "Непосредственная передача объектов классов TRIAD, TIME в вектор с помощью операции &" << endl;
	v.Add(&triad1);
	v.Add(&time1);
	v.Add(&time2);
	cout << "Объекты добавлены в вектор" << endl << endl;
	TRIAD triad2;
	cout << "Введите триаду:" << endl;
	cin >> triad2;
	Object* pointer = &triad2;
	TIME time3;
	cout << "Введите время:" << endl;
	cin >> time3;
	time3.correct_time_format();
	cout << "Передача объектов классов TRIAD, TIME в вектор с помощью переменной-указателя" << endl;
	v.Add(pointer);
	pointer = &time3;
	v.Add(pointer);
	cout << "Объекты добавлены в вектор" << endl << endl;
	cout << "Содержимое вектора:\n";
	cout << v << endl;
	system("pause");
	return 0;
}
