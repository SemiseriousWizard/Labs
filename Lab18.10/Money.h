#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
int index = 0;
using namespace std;
fstream negative_zero_index_file;
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
    }
    Money(const long int& rub, const int& kop) {
        Rubles = rub;
        Kopecks = kop;
    }
    Money(const Money& money) {
        Rubles = money.Rubles;
        Kopecks = money.Kopecks;
    }
    bool operator == (const Money& right) {
        return ((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    bool operator != (const Money& right) {
        return !((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    double& operator - (double right) {
        // if (Precision < 2)
          //   Precision = 2;

         /*int int_part_of_right_number = right;
         double fractional_part_right_number = right - int_part_of_right_number;
         for (int i = 0; i < Precision; i++)
             fractional_part_right_number *= 10;
         int fract_part_right_number_to_int = round(fractional_part_right_number);

         if (fract_part_right_number_to_int > Kopecks) {
             //if (Rubles > int_part_of_right_number)
                 Rubles--;
             //else if (Rubles - int_part_of_right_number <= 0 && Rubles - int_part_of_right_number > -1)
                // negative_zero_index_file << index << endl;
             Kopecks = pow(10, Precision) + Kopecks * pow(10, (Precision - 2)) - fract_part_right_number_to_int;
             //Kopecks = fract_part_right_number_to_int - Kopecks;
         }
         else
             Kopecks -= fract_part_right_number_to_int;
         Rubles -= int_part_of_right_number;
         double fractional_part_right_number_result = Kopecks;
         for (int i = 0; i < Precision; i++)
             fractional_part_right_number_result /= 10;
         double double_result = Rubles + fractional_part_right_number_result;
         return double_result;*/
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
    friend fstream& operator>>(fstream& fin, Money& money)
    {
        fin >> money.Rubles;
        fin >> money.Kopecks;
        return fin;
    }

    friend fstream& operator<<(fstream& fout, const Money& money)
    {
        fout << money.Rubles << "\n" << money.Kopecks << "\n";
        return fout;
    }

};
//перегрузка операторов ввода-вывода
istream& operator >> (istream& in, Money& money) {
    cout << "¬ведите руб.: ";
    in >> money.Rubles;
    cout << "¬ведите коп.: ";
    in >> money.Kopecks;
    return in;
}
ostream& operator << (ostream& out, const Money& money) {
    double double_Kopecks = money.Kopecks;
    string zero_filler = "";
    if ((double_Kopecks / 10) < 1)
        zero_filler = "0";
    return (out << money.Rubles << ',' << zero_filler << money.Kopecks << " руб.");
}
