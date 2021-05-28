#pragma once
#include "Object.h"
#include "TEvent.h"
#include <iostream>
using namespace std;
int indexOfPrintedElement = 0;
class PRINT :public Object {
public:
    PRINT() {
        Title = "";
        Author = "";
    }
    PRINT(const string title, const string author) {
        Title = title;
        Author = author;
    }
    PRINT(const PRINT& print) {
        Title = print.Title;
        Author = print.Author;
    }
    ~PRINT() {};
    //������������
    void set_title(const string title) {
        Title = title;
    }
    void set_author(const string author) {
        Author = author;
    }
    //���������
    string& get_title() { return Title; }
    string& get_author() { return Author; }

    PRINT& operator = (const PRINT& print) {
        if (&print == this)
            return *this;
        Title = print.Title;
        Author = print.Author;
        return *this;
    }
    virtual void show() {
        cout << ++indexOfPrintedElement << ")" << endl;
        cout << "�������� ��������� �������: " << Title << endl;
        cout << "�����: " << Author << endl << endl;
    }
    virtual void show_element_title(const int& index) {
        cout << index << ")\n";
        cout << "�������� ��������� �������: " << Title << endl << endl;
    }
    virtual void input() {
        cin.ignore();
        cout << "������� �������� ��������� �������: ";
        getline(cin, Title, '\n');
        cout << "������� ������: ";
        getline(cin, Author, '\n');
        cout << endl;
    }
    virtual void HandleEvent(const TEvent& event) {
        if (event.what == evMessage)
            switch (event.command)
            {
            case cmGetElementName:
                cout << "��������: " << get_title() << endl;
                break;
            }
    }
protected:
    string Title;
    string Author;
};