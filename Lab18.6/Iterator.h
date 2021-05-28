#pragma once
#include "Set.h"
class Iterator {
    friend class Set;
    int* element;
public:
    Iterator() { element = 0; }
    Iterator(const Iterator& iterator) {
        element = iterator.element;
    }
    bool operator == (const Iterator& iterator) {
        return (*element == *iterator.element);
    }
    bool operator != (const Iterator& iterator) {
        return !(*element == *iterator.element);
    }
    void operator ++ () { ++element; }
    void operator -- () { --element; }
    void operator + (const int& n) {
        for (int i = 0; i < n; i++)
            ++element;
    }
    void operator - (const int& n) {
        for (int i = 0; i < n; i++)
            --element;
    }
    int& operator *() { return *element; }
};