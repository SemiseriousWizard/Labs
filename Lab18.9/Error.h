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
		message_error = "��������� ������� ��������� � �������� � ������������� ��������\n";
	}
	void what() {
		cout << message_error;
	}
};
class IndexErrorMoreMax :public Error {
public:
	IndexErrorMoreMax() {
		message_error = "��������� ������� ��������� � ��������, ������ �������� ������ ������������� �������\n";
	}
	void what() {
		cout << message_error;
	}
};
class SizeErrorLessZero :public Error {
public:
	SizeErrorLessZero() {
		message_error = "��������� ������� ������� ��������� � ������������� ����������� ���������\n";
	}
	void what() {
		cout << message_error;
	}
};
class SizeErrorZero :public Error {
public:
	SizeErrorZero() {
		message_error = "��������� ������� ������� ��������� � ������� ����������� ���������\n";
	}
	void what() {
		cout << message_error;
	}
};