#include <iostream>
#include <string>
using namespace std;
class Employee {
    string FullName;
    string Position;
    double Salary;
public:
    Employee() {
        FullName = "";
        Position = "";
        Salary = 0;
        cout << "Вызов конструктора без параметров" << endl;
    }
    Employee(string fullname, string position, double salary) {
        FullName = fullname;
        Position = position;
        Salary = salary;
        cout << "Вызов конструктора с параметрами" << endl;
    }
    Employee(const Employee& employee) {
        FullName = employee.FullName;
        Position = employee.Position;
        Salary = employee.Salary;
        cout << "Вызов конструктора копирования" << endl;
    }
    void Print() {
        cout << "ФИО: " << FullName << endl;
        cout << "Должность: " << Position << endl;
        cout << "Зарплата: " << Salary << endl;
        cout << endl;
    }
    //селекторы
    string get_fullname() { return FullName; }
    string get_position() { return Position; }
    double get_salary() { return Salary; }
    //модификаторы
    void set_fullname(string fullname) { FullName = fullname; }
    void set_position(string position) { Position = position; }
    void set_salary(double salary) { Salary = salary; }
};