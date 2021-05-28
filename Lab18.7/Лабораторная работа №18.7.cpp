#include <iostream>
using namespace std;
//#pragma once
//#include <iostream>
//using namespace std;
bool isContinue = true;
template <class T>
class Set {
private:
    int myarray_size;
public:
    T* myarr;
    Set(const int& size) {
        if (size < 0 || size == 0) {
            cout << "Указан недопустимый размер множества!" << endl;
            isContinue = false;
        }
        else {
            myarr = new T[size];
            myarray_size = size;
        }
    }
    Set(const Set<T>& set) {
        myarray_size = set.myarray_size;
        myarr = new T[myarray_size];
        for (int i = 0; i < myarray_size; i++)
            myarr[i] = set.myarr[i];
    }
    ~Set() {
        delete[] myarr;
        myarr = 0;
        myarray_size = 0;
    }
    Set<T>& operator = (const Set<T>& set) {
        if (this == &set)
            return *this;
        if (myarr != 0)
            delete[] myarr;
        myarray_size = set.myarray_size;
        myarr = new T[myarray_size];
        for (int i = 0; i < myarray_size; i++)
            myarr[i] = set.myarr[i];
        return *this;
    }
    T& operator[](const int& index) {
        if (index < 0 || index >= myarray_size) {
            cout << "Указан недопустимый индекс для элемента множества!" << endl;
            isContinue = false;
        }
        else
            return myarr[index];
    }
    bool operator!=(const T& right) {
        return !(*myarr == right);
    }
    bool operator < (const T& element) {
        for (int i = 0; i < myarray_size; i++)
            if (myarr[i] == element)
                return true;
        return false;
    }
    friend istream& operator >> (istream& in, Set<T>& set) {
        for (int i = 0; i < set.myarray_size; i++)
            in >> set.myarr[i];
        return in;
    }
    friend ostream& operator << (ostream& out, const Set<T>& set) {
        for (int i = 0; i < set.myarray_size; i++)
            out << i + 1 << ") " << set.myarr[i] << endl;
        return out;
    }
};
class Money {
private:
    long int Rubles;
    int Kopecks;
    int Precision;
public:
    Money() {
        Rubles = 0;
        Kopecks = 0;
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
        if (Precision < 2)
            Precision = 2;
        int int_part_of_right_number = right;
        double fractional_part_right_number = right - int_part_of_right_number;
        for (int i = 0; i < Precision; i++)
            fractional_part_right_number *= 10;
        int fract_part_right_number_to_int = round(fractional_part_right_number);

        if (fract_part_right_number_to_int > Kopecks) {
            Rubles--;
            Kopecks = pow(10, Precision) + Kopecks * pow(10, (Precision - 2)) - fract_part_right_number_to_int;
        }
        else
            Kopecks -= fract_part_right_number_to_int;
        Rubles -= int_part_of_right_number;
        double fractional_part_right_number_result = Kopecks;
        for (int i = 0; i < Precision; i++)
            fractional_part_right_number_result /= 10;
        double double_result = Rubles + fractional_part_right_number_result;
        return double_result;
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
    friend istream& operator >> (istream& in, Money& money) {
        cout << "Введите руб.: ";
        in >> money.Rubles;
        cout << "Введите коп.: ";
        in >> money.Kopecks;
        return in;
    }
    friend ostream& operator << (ostream& out, const Money& money) {
        double double_Kopecks = money.Kopecks;
        string zero_filler = "";
        if ((double_Kopecks / 10) < 1)
            zero_filler = "0";
        return (out << money.Rubles << ',' << zero_filler << money.Kopecks << " руб.");
    }
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
    //=, [], !=, <, >>, <<, constr.
    int size, index_left, index_right, number_int;
    cout << "Введите количество элементов во множестве: ";
    cin >> size;
    Set<int> set_int(size);
    if (isContinue) {
        cout << "Введите целые числа:" << endl;
        cin >> set_int;
        cout << "Содержимое множества:" << endl;
        cout << set_int << endl;
        cout << "Введите индекс левого операнда: ";
        cin >> index_left;
        cout << "Введите индекс правого операнда: ";
        cin >> index_right;
        cout << set_int[index_left] << " != " << set_int[index_right] << " = "
                << (set_int[index_left] != set_int[index_right]) << endl;
        cout << "Введите число: ";
        cin >> number_int;
        if (set_int < number_int)
            cout << number_int << " содержится во множестве" << endl;
        else
            cout << number_int << " отсутствует во множестве" << endl;
    }
    isContinue = true;
    cout << "Введите количество элементов во множестве: ";
    cin >> size;
    Set<float> set_float(size);
    float number_float;
    if (isContinue) {
        cout << "Введите вещественные числа (тип float):" << endl;
        cin >> set_float;
        cout << "Содержимое множества:" << endl;
        cout << set_float << endl;
        cout << "Введите индекс левого операнда: ";
        cin >> index_left;
        cout << "Введите индекс правого операнда: ";
        cin >> index_right;
        cout << set_float[index_left] << " != " << set_float[index_right] << " = "
            << (set_float[index_left] != set_float[index_right]) << endl;
        cout << "Введите число: ";
        cin >> number_float;
        if (set_float < number_float)
            cout << number_float << " содержится во множестве" << endl;
        else
            cout << number_float << " отсутствует во множестве" << endl;
    }
    isContinue = true;
    cout << "Введите количество элементов во множестве: ";
    cin >> size;
    Set<double> set_double(size);
    double number_double;
    if (isContinue) {
        cout << "Введите вещественные числа (тип double):" << endl;
        cin >> set_double;
        cout << "Содержимое множества:" << endl;
        cout << set_double << endl;
        cout << "Введите индекс левого операнда: ";
        cin >> index_left;
        cout << "Введите индекс правого операнда: ";
        cin >> index_right;
        cout << set_double[index_left] << " != " << set_double[index_right] << " = "
            << (set_double[index_left] != set_double[index_right]) << endl;
        cout << "Введите число: ";
        cin >> number_double;
        if (set_double < number_double)
            cout << number_double << " содержится во множестве" << endl;
        else
            cout << number_double << " отсутствует во множестве" << endl;
    }
    isContinue = true;
    cout << "Вызов конструктора копирования:" << endl;
    Set<float> set_float2(set_float);
    cout << "Содержимое множества:" << endl;
    cout << set_float2 << endl;

    cout << "Создание копии множества с помощью оператора =" << endl;
    Set<double> set_double2(1);
    set_double2 = set_double;
    cout << "Содержимое множества:" << endl;
    cout << set_double2 << endl;

    cout << "Использование типа Money в шаблоне-контейнере Set:" << endl;
    cout << "Введите размер множества: ";
    cin >> size;
    Set<Money> set_money(size);
    if (isContinue) {
        //==, !=, -
        cout << "Введите элементы множества:" << endl;
        cin >> set_money;
        cout << "Содержимое множества:" << endl;
        cout << set_money << endl;
        cout << "Введите индекс левого операнда: ";
        cin >> index_left;
        cout << "Введите индекс правого операнда: ";
        cin >> index_right;
        cout << set_money[index_left] << " == " << set_money[index_right] << " = "
            << (set_money[index_left] == set_money[index_right]) << endl;
        cout << set_money[index_left] << " != " << set_money[index_right] << " = "
            << (set_money[index_left] != set_money[index_right]) << endl;
        Money money;
        cin >> money;
        if (set_money < money)
            cout <<"Элемент " << money << " содержится во множестве" << endl;
        else
            cout << "Элемент " << money << " отсутствует во множестве" << endl;

        char* number_str = new char[30];
        cout << "Введите вещественное число: ";
        cin.ignore();
        cin.getline(number_str, '\n');
        double number = strtod(number_str, NULL);
        cout << "Введите индекс элемента, из которого хотите вычесть " << number << ": ";
        cin >> index_left;
        set_money[index_left].SetPrecision(get_precision(number_str));
        cout << set_money[index_left] << " - " << number << " = ";
        cout << (set_money[index_left] - number) << endl;
    }
	system("pause");
	return 0;
}
