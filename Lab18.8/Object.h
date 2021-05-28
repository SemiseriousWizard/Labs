#pragma once
#include "TEvent.h"
class Object {
public:
    Object(void) {};
    ~Object(void) {};
    virtual void show() = 0;
    virtual void show_element_title(const int& index) = 0;
    virtual void input() = 0;
    virtual void HandleEvent(const TEvent& event) = 0;
};