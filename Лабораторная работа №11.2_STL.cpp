#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <iterator>
using namespace std;
list<const char*> ListOfSymbols;
vector<string> VectorForElementsOfList;
void assign(vector<string>& target, list<const char*>& source)
{
    using std::begin; using std::end;
    target.assign(begin(source), end(source));
}
void create(int amountOfElements) {
    char* symbols;
    string data;
    cout << "Введите элементы списка:\n";
    for (int i = 0; i < amountOfElements; i++) {
        cout << i + 1 << ") ";
        cin >> data;
        symbols = new char[data.length() + 1];
        strcpy(symbols, data.c_str());
        ListOfSymbols.push_back(symbols);
    }
    assign(VectorForElementsOfList, ListOfSymbols);
}
void add_elements_in_odd_spots() {
    char* symbols;
    string data;
    if (ListOfSymbols.empty()) {
        cout << "Введите элемент: ";
        cin >> data;
        symbols = new char[data.length() + 1];
        strcpy(symbols, data.c_str());
        ListOfSymbols.push_back(symbols);
        assign(VectorForElementsOfList, ListOfSymbols);
    }
    else
    {
        int amountOfOddIndexes = 0;
        for (int i = 1; i <= ListOfSymbols.size(); i++)
            if (i % 2 != 0)
                amountOfOddIndexes++;
        list<const char*>::iterator it = ListOfSymbols.begin();
        for (int i = 1; i <= amountOfOddIndexes; i++) {
            cout << "Введите элемент: ";
            cin >> data;
            symbols = new char[data.length() + 1];
            strcpy(symbols, data.c_str());
            ListOfSymbols.insert(it, symbols);
            it++++;
        }
        assign(VectorForElementsOfList, ListOfSymbols);
    }
}
void print(const vector<string>& c)
{
    for (auto& e : c)
        std::cout << e << '\n';

    std::cout << '\n';
}
int main()
{
    setlocale(LC_ALL, "rus");
    int sizeOfList;
    cout << "Введите количество элементов списка: ";
    do {
        cin >> sizeOfList;
        if (sizeOfList < 0)
            cout << "Количество элементов в списке не может быть меньше 0!\n";
    } while (sizeOfList < 0);
    create(sizeOfList);
    cout << "Исходный список:\n";
    print(VectorForElementsOfList);
    add_elements_in_odd_spots();
    cout << "Список после вставки элементов на нечетные места:\n";
    print(VectorForElementsOfList);
    ListOfSymbols.clear();
    system("pause");
    return 0;
}