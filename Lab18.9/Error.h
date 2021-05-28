#pragma once
#include <iostream>
#include <string>
using namespace std;
class Error {
protected:
	string message_error;
public:
	virtual void what() {};
};
class IndexErrorLessZero :public Error {
public:
	IndexErrorLessZero() {
		message_error = "ѕроизошла попытка обращени€ к элементу с отрицательным индексом\n";
	}
	void what() {
		cout << message_error;
	}
};
class IndexErrorMoreMax :public Error {
public:
	IndexErrorMoreMax() {
		message_error = "ѕроизошла попытка обращени€ к элементу, индекс которого больше максимального индекса\n";
	}
	void what() {
		cout << message_error;
	}
};
class SizeErrorLessZero :public Error {
public:
	SizeErrorLessZero() {
		message_error = "ѕроизошла попытка создать множество с отрицательным количеством элементов\n";
	}
	void what() {
		cout << message_error;
	}
};
class SizeErrorZero :public Error {
public:
	SizeErrorZero() {
		message_error = "ѕроизошла попытка создать множество с нулевым количеством элементов\n";
	}
	void what() {
		cout << message_error;
	}
};