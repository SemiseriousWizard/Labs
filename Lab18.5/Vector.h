#pragma once
#include "Object.h"
#include <iostream>
using namespace std;
class Vector {
private:
	Object** begin;
	int size;
	int current_position;
public:
	Vector() {
		begin = 0;
		size = 0;
		current_position = 0;
	}
	Vector(int size){
		begin = new Object * [size];
		this->size = size;
		current_position = 0;
	}
	~Vector() {
		if (begin != 0) {
			delete[] begin;
			begin = 0;
		}
	}
	void Add(Object* object) {
		if (current_position < size) {
			begin[current_position] = object;
			current_position++;
		}
	}
	friend ostream& operator << (ostream& out, const Vector& vector) {
		if (vector.size == 0)
			out << "Вектор пустой" << endl;
		Object** ptr_on_object = vector.begin;
		for (int i = 0; i < vector.current_position; i++) {
			(*ptr_on_object)->show();
			ptr_on_object++;
		}
		return out;
	}
};