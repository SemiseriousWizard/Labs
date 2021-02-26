#include <iostream>
#include <string>
using namespace std;
struct Symbol {
    char* String;
    Symbol* Next;
    Symbol* Previous;
};
void create(Symbol*& first, int amountOfElements) {
    char data_str[256];
    Symbol* ptr_on_letter;
    first = NULL;                   
    cout << "Введите элементы списка:\n";
    cout << "1) ";
    ptr_on_letter = new Symbol; 
    memset(data_str, 0, sizeof data_str);
    cin>>data_str;
    ptr_on_letter->String = new char[strlen(data_str)];
    strcpy(ptr_on_letter->String, data_str);
    ptr_on_letter->Next = NULL;    
    ptr_on_letter->Previous = NULL;
    first = ptr_on_letter;      
    for (int i = 1; i < amountOfElements; i++) {
        Symbol* ptr_on_next_element = new Symbol; 
        ptr_on_letter->Next = ptr_on_next_element;      
        ptr_on_next_element->Previous = ptr_on_letter;
        ptr_on_letter = ptr_on_letter->Next;            
        cout << i + 1 << ") ";
        memset(data_str, 0, sizeof data_str);
        cin >> data_str;
        ptr_on_letter->String = new char[strlen(data_str)];
        strcpy(ptr_on_letter->String, data_str);
        ptr_on_letter->Next = NULL;                                                            
    }
}
void print(Symbol* first) {
    if (first != NULL) {
        Symbol* ptr_on_letter = first;
        while (ptr_on_letter != NULL) {
            cout << ptr_on_letter->String << endl;
            ptr_on_letter = ptr_on_letter->Next;
        }
    }
    else
        cout << "В списке нет элементов\n";
}
void add_elements_in_odd_spots(Symbol* &list) {
    char data_str[256];
    if (list == NULL) {
        Symbol* ptr_on_letter = new Symbol;
        memset(data_str, 0, sizeof data_str);
        cout << "Введите элемент: ";
        cin >> data_str;
        ptr_on_letter->String = new char[strlen(data_str)];
        strcpy(ptr_on_letter->String, data_str);
        ptr_on_letter->Next = NULL;
        ptr_on_letter->Previous = NULL;
        list = ptr_on_letter;
    }
    else
    {
        int amountOfOddSpots = 0, amountOfElements = 0;
        Symbol* ptr_on_letter = list;
        while (ptr_on_letter != NULL) {
            amountOfElements++;
            if (amountOfElements % 2 != 0)
                amountOfOddSpots++;
            ptr_on_letter = ptr_on_letter->Next;
        }
        ptr_on_letter = list;
        Symbol* ptr_new_element = new Symbol;
        cout << "Введите элемент: ";
        memset(data_str, 0, sizeof data_str);
        cin >> data_str;
        ptr_new_element->String = new char[strlen(data_str)];
        strcpy(ptr_new_element->String, data_str);
        ptr_new_element->Next = list;
        ptr_new_element->Previous = NULL;
        list->Previous = ptr_new_element;
        list = ptr_new_element;
        for (int i = 1; i < amountOfOddSpots; i++) {
            Symbol* ptr_on_new_middle_element = new Symbol;
            cout << "Введите элемент: ";
            memset(data_str, 0, sizeof data_str);
            cin >> data_str;
            ptr_on_new_middle_element->String = new char[strlen(data_str)];
            strcpy(ptr_on_new_middle_element->String, data_str);
            ptr_on_new_middle_element->Next = NULL;
            ptr_on_new_middle_element->Previous = NULL;
            Symbol* ptr_on_right_element = ptr_new_element->Next->Next;
            Symbol* ptr_on_left_element = ptr_new_element->Next;
            ptr_new_element->Next->Next = ptr_on_new_middle_element;
            ptr_on_new_middle_element->Next = ptr_on_right_element;
            ptr_on_right_element->Previous = ptr_on_new_middle_element;
            ptr_on_new_middle_element->Previous = ptr_on_left_element;
            ptr_new_element = ptr_on_new_middle_element;
        }
    }
}
void delete_list(Symbol*& list) {
    while (list != NULL) {
        Symbol* pointer = list;
        list = list->Next;
        delete pointer;
    }
}
void check_my_list(Symbol* list) {
    Symbol*pointer = list, *pp = NULL;

    if (list != NULL) {
        while (pointer != NULL) {
            cout << pointer->String << endl;
            pp = pointer;
            pointer = pointer->Next;
        }
    }
    pointer = pp;
    while (pointer != NULL) {
        cout << pointer->String << endl;
        pointer = pointer->Previous;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    Symbol* ListOfSymbols;
    int sizeOfList;
    cout << "Введите количество элементов списка: ";
    do {
        cin >> sizeOfList;
        if (sizeOfList < 0)
            cout << "Количество элементов в списке не может быть меньше 0!\n";
    } while (sizeOfList < 0);
    create(ListOfSymbols, sizeOfList);
    cout << "Исходный список:\n";
  //  check_my_list(ListOfSymbols);
    print(ListOfSymbols);
    add_elements_in_odd_spots(ListOfSymbols);
    cout << "Список после вставки элементов на нечетные места:\n";
    print(ListOfSymbols);
  //// // check_my_list(ListOfSymbols);
    delete_list(ListOfSymbols);
    system("pause");
    return 0;
}