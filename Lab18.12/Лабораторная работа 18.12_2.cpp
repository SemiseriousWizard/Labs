#include <iostream>
#include <vector>
#include <set>
using namespace std;
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
    void SetPrecision(const int& prec) { Precision = prec; }
    bool operator == (const Money& right) {
        return ((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    bool operator != (const Money& right) {
        return !((Rubles == right.Rubles) && (Kopecks == right.Kopecks));
    }
    /*double& operator - (double right) {
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
    }*/
    void operator = (const double& right) {
        int int_part_of_right_number = right;
        double fractional_part_right_number = right - int_part_of_right_number;
        for (int i = 0; i < Precision; i++)
            fractional_part_right_number *= 10;
        int fract_part_right_number_to_int = round(fractional_part_right_number);
        Rubles = int_part_of_right_number;
        Kopecks = fract_part_right_number_to_int;
    }
    
    bool operator < (const Money money) const {
        if (Rubles < money.Rubles)
            return true;
        else if (Rubles <= money.Rubles)
            if (Kopecks < money.Kopecks)
                return true;
            else
                return false;
        return false;
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
    return (out << money.Rubles << ',' << zero_filler << money.Kopecks << " руб.");
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
typedef set<Money, less<Money>>tset;
void make_set(tset& my_set) {
    cout << "Введите количество элементов: ";
    int size;
    cin >> size;
    Money money;
    cout << "Введите элементы:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cin >> money;
        my_set.insert(money);
    }
}
void print_set(tset my_set) {
    tset::iterator i;
    for (i = my_set.begin(); i != my_set.end(); i++)
        cout << *i << endl;
}
void delete_element(tset& my_set, const Money element) {
    my_set.erase(element);
}
Money add_arithmetical_mean(tset& my_set) {
    if (my_set.size() == 0) {
        cout << "Множество пустое" << endl;
        return Money(0,0);
    }
    int sum_rub = 0, sum_kop = 0;
    tset::iterator i;
    vector<Money> temp_vector;
    for (i = my_set.begin(); i != my_set.end(); i++) 
        temp_vector.push_back(*i);
    for (int j = 0; j < temp_vector.size(); j++)
    {
        sum_rub += temp_vector[j].get_rubles();
        sum_kop += temp_vector[j].get_kopecks();
    }
    Money arithmetical_mean;
    arithmetical_mean.set_rubles(sum_rub / temp_vector.size());
    arithmetical_mean.set_kopecks(sum_kop / temp_vector.size());
    for (int j = 0; j < temp_vector.size(); j++) {
        temp_vector[j].set_rubles(temp_vector[j].get_rubles() + arithmetical_mean.get_rubles());
        if (temp_vector[j].get_kopecks() + arithmetical_mean.get_kopecks() >= 100) {
            temp_vector[j].set_rubles(temp_vector[j].get_rubles() + 1);
            temp_vector[j].set_kopecks(temp_vector[j].get_kopecks() + arithmetical_mean.get_kopecks() - 100);
        }
        else
            temp_vector[j].set_kopecks(temp_vector[j].get_kopecks() + arithmetical_mean.get_kopecks());
    }
    my_set.clear();
    for (int j = 0; j < temp_vector.size(); j++)
        my_set.insert(temp_vector[j]);
    temp_vector.clear();
    return arithmetical_mean;
}
int main()
{
    setlocale(LC_ALL, "");
    tset mySet;
    make_set(mySet);
    cout << "Максимальный элемент добавлен в конец:\n";
    cout << "Содержимое множества:" << endl;
    print_set(mySet);
    cout << "Введите элемент, который хотите удалить:\n";
    Money element_for_deleting;
    cin >> element_for_deleting;
    delete_element(mySet, element_for_deleting);
    cout << "Содержимое множества после удаления элемента:" << endl;
    print_set(mySet);
    cout << "Содержимое множества после добавления к элементам среднего арифметического значения:" << endl;
    cout << "Среднее арифметическое = " << add_arithmetical_mean(mySet) << endl;
    print_set(mySet);
    return 0;
}