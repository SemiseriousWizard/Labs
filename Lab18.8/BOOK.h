#pragma once
#include "PRINT.h"
#include <string>
#include <iostream>
using namespace std;
class BOOK :public PRINT {
public:
    BOOK() :PRINT() {
        amountOfPages = 0;
        publishingHouse = "";
    }
    BOOK(const string title, const string author, const int& amount_of_pages, const string publishing_house)
        :PRINT(title, author) {
        amountOfPages = amount_of_pages;
        publishingHouse = publishing_house;
    }
    BOOK(const BOOK& book) :PRINT(book) {
        amountOfPages = book.amountOfPages;
        publishingHouse = book.publishingHouse;
    }
    ~BOOK() {};
    BOOK& operator = (const BOOK& book) {
        if (&book == this)
            return *this;
        Title = book.Title;
        Author = book.Author;
        amountOfPages = book.amountOfPages;
        publishingHouse = book.publishingHouse;
        return *this;
    }
    void show() {
        cout << ++indexOfPrintedElement << ")" << endl;
        cout << "�������� �����: " << Title << endl;
        cout << "�����: " << Author << endl;
        cout << "���������� �������: " << amountOfPages << endl;
        cout << "������������: " << publishingHouse << endl;
        cout << endl;
    }
    void show_element_title(const int& index) {
        cout << index << ")\n";
        cout << "�������� �����: " << Title << endl << endl;
    }
    void input() {
        cin.ignore();
        cout << "������� �������� �����: ";
        getline(cin, Title, '\n');
        cout << "������� ������: ";
        getline(cin, Author, '\n');
        cout << "������� ���������� �������: ";
        cin >> amountOfPages;
        cin.ignore();
        cout << "������� �������� ������������: ";
        getline(cin, publishingHouse, '\n');
        cout << endl;
    }
protected:
    int amountOfPages;
    string publishingHouse;
};