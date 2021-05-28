#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;
const int number_size = 30;
class Money {
private:
    long int Rubles;
    int Kopecks;
    int Precision;
public:
    Money() {
        Rubles = 0;
        Kopecks = 0;
        Precision = 0;
        cout << "Вызов конструктора без параметров\n";
    }
    Money(const long int& rub, const int& kop) {
        Rubles = rub;
        Kopecks = kop;
        cout << "Вызов конструктора с параметрами\n";
    }
    Money(const Money& money) {
        Rubles = money.Rubles;
        Kopecks = money.Kopecks;
        cout << "Вызов конструктора копирования\n";
    }
    void SetPrecision(const int& prec) { Precision = prec; }
    bool operator == (const Money& right) {
        return ((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    bool operator != (const Money& right) {
        return !((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    double& operator - (double right) {
        double left = Rubles + (double)Kopecks / 100;
        double substract_result = left - right;
        Rubles = (int)substract_result;
        Kopecks = abs((round)((substract_result - Rubles) * 100));
        return substract_result;
    }
    void operator = (const double& right) {
        int int_part_of_right_number = right;
        double fractional_part_right_number = right - int_part_of_right_number;
        for (int i = 0; i < Precision; i++)
            fractional_part_right_number *= 10;
        int fract_part_right_number_to_int = round(fractional_part_right_number);
        Rubles = int_part_of_right_number;
        Kopecks = fract_part_right_number_to_int;
    }
    friend istream& operator >> (istream& in, Money& money);
    friend ostream& operator << (ostream& out, const Money& money);
    long int get_rubles() {
        return Rubles;
    }
    int get_kopecks() {
        return Kopecks;
    }
    void set_rubles(const long int& rub) {
        Rubles = rub;
    }
    void set_kopecks(const int& kop) {
        Kopecks = kop;
    }
};
//перегрузка операторов ввода-вывода
istream& operator >> (istream& in, Money& money) {
    cout << "Введите руб.: ";
    in >> money.Rubles;
    cout << "Введите коп.: ";
    in >> money.Kopecks;
    return in;
}
ostream& operator << (ostream& out, const Money& money) {
    double double_Kopecks = money.Kopecks;
    string zero_filler = "";
    if ((double_Kopecks / 10) < 1)
        zero_filler = "0";
    return (out << money.Rubles << ',' << zero_filler << money.Kopecks);
}
//найти количество цифр в числе после запятой
int get_precision(char* number_str) {
    int index = 0, count_precision = 0;
    while ((number_str[index] != ',') && (number_str[index] != NULL)) index++;
    if (number_str[index] == ',')
        index++;
    while (number_str[index] != NULL) {
        index++;
        count_precision++;
    }
    return count_precision;
}
int main()
{
    setlocale(LC_ALL, "");
    Money money1(33, 16);
    cout << money1 << " руб." << endl;
    cout << endl;
    Money money2(money1);
    cout << money2 << " руб." << endl;
    cout << endl;
    Money money3;
    cout << money3 << " руб." << endl;
    cout << endl;
    cout << "Демонстрация работы модификаторов и селекторов:" << endl;
    money3.set_rubles(120000);
    money3.set_kopecks(98);
    cout << money3.get_rubles() << " руб." << endl;
    cout << money3.get_kopecks() << " коп." << endl;
    cout << endl;
    cout << "Демонстрация работы оператора присваивания:" << endl;
    char* number_str = new char[number_size];
    cout << "Введите вещественное число: ";
    cin.getline(number_str, '\n');
    double number = strtod(number_str, NULL);
    Money money4;
    money4.SetPrecision(get_precision(number_str));
    money4 = number;
    cout << money4 << " руб." << endl;
    cout << endl;
    cout << "Демонстрация работы операторов сравнения:" << endl;
    cout << money3 << " == " << money4 << " = " << (money3 == money4) << endl;
    cout << money3 << " != " << money4 << " = " << (money3 != money4) << endl;
    cout << endl;
    cout << "Демонстрация работы оператора вычитания:" << endl;
    Money money5;
    cout << "Ввод левого операнда:" << endl;
    cin >> money5;
    cout << "Ввод правого операнда:" << endl;
    cin.ignore();
    cin.getline(number_str, '\n');
    number = strtod(number_str, NULL);
    int precision_in_number = get_precision(number_str);
    money5.SetPrecision(precision_in_number);
    cout << fixed;
    if (precision_in_number < 2)
        precision_in_number = 2;
    cout<<setprecision(precision_in_number);
    cout << money5 << " - " << number << " = ";
    cout << ((money5 - number)) << " руб." << endl;
    system("pause");
    return 0;
}
