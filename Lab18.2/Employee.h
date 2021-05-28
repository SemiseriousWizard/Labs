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
        cout << "����� ������������ ��� ����������" << endl;
    }
    Employee(string fullname, string position, double salary) {
        FullName = fullname;
        Position = position;
        Salary = salary;
        cout << "����� ������������ � �����������" << endl;
    }
    Employee(const Employee& employee) {
        FullName = employee.FullName;
        Position = employee.Position;
        Salary = employee.Salary;
        cout << "����� ������������ �����������" << endl;
    }
    void Print() {
        cout << "���: " << FullName << endl;
        cout << "���������: " << Position << endl;
        cout << "��������: " << Salary << endl;
        cout << endl;
    }
    //���������
    string get_fullname() { return FullName; }
    string get_position() { return Position; }
    double get_salary() { return Salary; }
    //������������
    void set_fullname(string fullname) { FullName = fullname; }
    void set_position(string position) { Position = position; }
    void set_salary(double salary) { Salary = salary; }
};