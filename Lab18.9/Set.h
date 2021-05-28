#pragma once
#include "Error.h"
class Set {
private:
    int myarray_size;
public:
    int* myarr;
    int indexleft;
    Set(const int& size) {
        if (size < 0)
            throw SizeErrorLessZero();
        if (size == 0)
            throw SizeErrorZero();
        myarr = new int[size];
        myarray_size = size;
    }
    void Add(const int& element, const int& index) {
        if (index < 0)
            throw IndexErrorLessZero();
        if (index >= myarray_size)
            throw IndexErrorMoreMax();
        myarr[index] = element;
    }
    int& operator[](const int& index) {
        if (index < 0)
            throw IndexErrorLessZero();
        if (index >= myarray_size)
            throw IndexErrorMoreMax();
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
    int& operator + (const int& index) {
        if (index < 0)
            throw IndexErrorLessZero();
        if (index >= myarray_size)
            throw IndexErrorMoreMax();
        if (indexleft < 0)
            throw IndexErrorLessZero();
        if (indexleft >= myarray_size)
            throw IndexErrorMoreMax();
        for (int i = 1; i < indexleft; i++)
            myarr++;
        return *myarr = myarr[index];
    }
};