#pragma once
#include "Iterator.h"
#include <iostream>
using namespace std;
class Set {
private:
    int myarray_size;
    Iterator begin;
    Iterator end;
public:
    int* myarr;
    Set(const int& size) {
        if (size < 0 || size == 0)
            cout << "”казан недопустимый размер множества!" << endl;
        else {
            myarr = new int[size];
            myarray_size = size;
            begin.element = &myarr[0];
            end.element = &myarr[myarray_size];
        }
    }
    Set(const Set& set) {
        myarray_size = set.myarray_size;
        myarr = new int[myarray_size];
        for (int i = 0; i < myarray_size; i++)
            myarr[i] = set.myarr[i];
        begin = set.begin;
        end = set.end;
    }
    ~Set() {
        delete[] myarr;
        myarr = 0;
        myarray_size = 0;
    }
    Set& operator = (const Set& set) {
        if (this == &set)
            return *this;
        if (myarr != 0)
            delete[] myarr;
        myarray_size = set.myarray_size;
        myarr = new int[myarray_size];
        for (int i = 0; i < myarray_size; i++)
            myarr[i] = set.myarr[i];
        begin = set.begin;
        end = set.end;
        return *this;
    }
    int& operator[](const int& index) {
        if (index < 0 || index >= myarray_size)
            cout << "”казан недопустимый индекс дл€ элемента множества!" << endl;
        else
            return myarr[index];
    }
    bool operator!=(const int& right) {
        return !(*myarr == right);
    }
    bool operator < (const int& element) {
        for (int i = 0; i < myarray_size; i++)
            if (element == myarr[i])
                return true;
        return false;
    }
    friend istream& operator >> (istream& in, Set& set) {
        for (int i = 0; i < set.myarray_size; i++)
            in >> set.myarr[i];
        return in;
    }
    friend ostream& operator << (ostream& out, const Set& set) {
        for (int i = 0; i < set.myarray_size; i++)
            out << i + 1 << ") " << set.myarr[i] << endl;
        return out;
    }
    Iterator first() { return begin; }
    Iterator last() { return end; }
};