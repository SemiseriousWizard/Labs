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
        cout << "Название книги: " << Title << endl;
        cout << "Автор: " << Author << endl;
        cout << "Количество страниц: " << amountOfPages << endl;
        cout << "Издательство: " << publishingHouse << endl;
        cout << endl;
    }
    void show_element_title(const int& index) {
        cout << index << ")\n";
        cout << "Название книги: " << Title << endl << endl;
    }
    void input() {
        cin.ignore();
        cout << "Введите название книги: ";
        getline(cin, Title, '\n');
        cout << "Введите автора: ";
        getline(cin, Author, '\n');
        cout << "Введите количество страниц: ";
        cin >> amountOfPages;
        cin.ignore();
        cout << "Введите название издательства: ";
        getline(cin, publishingHouse, '\n');
        cout << endl;
    }
protected:
    int amountOfPages;
    string publishingHouse;
};