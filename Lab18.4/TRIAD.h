#pragma once
#include <iostream>
using namespace std;
class TRIAD {
protected:
	int first;
	int second;
	int third;
public:
	TRIAD() {
		first = 0;
		second = 0;
		third = 0;
	}
	TRIAD(const int& first, const int& second, const int& third) {
		this->first = first;
		this->second = second;
		this->third = third;
	}
	TRIAD(const TRIAD& triad) {
		first = triad.first;
		second = triad.second;
		third = triad.third;
	}
	//������������
	void set_first(const int& first) {
		this->first = first;
	}
	void set_second(const int& second) {
		this->second = second;
	}
	void set_third(const int& third) {
		this->third = third;
	}
	//���������
	int& get_first() { return first; }
	int& get_second() { return second; }
	int& get_third() { return third; }
	TRIAD& operator = (const TRIAD& triad) {
		cout << "����� ��������� ������������" << endl;
		if (&triad == this)
			return *this;
		first = triad.first;
		second = triad.second;
		third = triad.third;
		return *this;
	}
	friend ostream& operator << (ostream& out, const TRIAD& triad) {
		return (out << triad.first << ' ' << triad.second << ' ' << triad.third);
	}
	friend istream& operator >> (istream& in, TRIAD& triad) {
		cout << "1� �����: ";
		in >> triad.first;
		cout << "2� �����: ";
		in >> triad.second;
		cout << "3� �����: ";
		in >> triad.third;
		return in;
	}
	//��������� ��������� ==, !=, >, >=, <, <=
	bool operator == (const TRIAD& triad) {
		return ((first == triad.first) && (second == triad.second) && (third == triad.third));
	}
	bool operator != (const TRIAD& triad) {
		return !((first == triad.first) && (second == triad.second) && (third == triad.third));
	}
	bool operator > (const TRIAD& triad) {
		return (first > triad.first || (first == triad.first && (second > triad.second || (second == triad.second && third > triad.third))));
	}
	bool operator >= (const TRIAD& triad) {
		return (first > triad.first || (first == triad.first && (second > triad.second || (second == triad.second && third >= triad.third))));
	}

	bool operator < (const TRIAD& triad) {
		return (first < triad.first || (first == triad.first && (second < triad.second || (second == triad.second && third < triad.third))));
	}
	bool operator <= (const TRIAD& triad) {
		return (first < triad.first || (first == triad.first && (second < triad.second || (second == triad.second && third <= triad.third))));
	}
};