#pragma once
#include <iostream>
#include "Object.h"
#include "PRINT.h"
#include "BOOK.h"
using namespace std;
class List {
public:
    List() {};
    List(const int size) {
        begin = new Object * [size];
        current_position = 0;
        list_size = size;
    };
    ~List() {
        if (begin != NULL)
            delete[] begin;
        begin = NULL;
    };
    void Add() {
        Object* ptr_on_object;
        PRINT* PRINT_object;
        BOOK* BOOK_object;
        cout << "Выберите класс для добавления в него объекта:\n";
        cout << "1) Добавить в класс печатных изданий\n";
        cout << "2) Добавить в класс книг\n";
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            PRINT_object = new PRINT;
            PRINT_object->input();
            ptr_on_object = PRINT_object;
            if (list_size < save_list_size)
                list_size++;
            if (current_position < list_size)
                begin[current_position++] = ptr_on_object;
            break;
        case 2:
            BOOK_object = new BOOK;
            BOOK_object->input();
            ptr_on_object = BOOK_object;
            if (list_size < save_list_size)
                list_size++;
            if (current_position < list_size)
                begin[current_position++] = ptr_on_object;
            break;
        }
    };
    void Delete() { //уменьшение размера списка на единицу
        if (current_position == 0)
            return;
        current_position--;
        if (list_size > 0)
            list_size--;
    };
    void Show() {
        if (current_position == 0)
            cout << "Список пустой\n";
        Object** ptr_on_object = begin;
        for (int i = 0; i < list_size; i++) {
            (*ptr_on_object)->show();
            ptr_on_object++;
        }
    };
    void Show_Title(const int& index) {
        if (current_position == 0)
            cout << "Список пустой\n";
        if (index < 1 || index > list_size) {
            cout << "Введен недопустимый номер элемента!" << endl;
            return;
        }
        Object** ptr_on_object = begin;
        for (int i = 0; i < list_size; i++) {
            if ((index - 1) == i) {
                (*ptr_on_object)->show_element_title(index);
                return;
            }
            ptr_on_object++;
        }
    }
    int& size() {
        return list_size;
    };
    void HandleEvent(const TEvent& event)
    {
        if (event.what == evMessage)
        {
            Object** p = begin;
            for (int i = 0;i < current_position;i++)
            {
                (*p)->HandleEvent(event);
                p++;
            }
        }
    }

protected:
    Object** begin;
    int list_size;
    int current_position;
};