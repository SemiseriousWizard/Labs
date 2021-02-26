#include <iostream>
using namespace std;
struct IntNumber {
    int Number;
    IntNumber* Next;
};
IntNumber* ListOfIntNumbers;
void create (IntNumber* &first, int amountOfElements) {
    IntNumber* ptr_on_number;       
    first = NULL;                 
    cout << "Введите элементы списка:\n";
    cout << "1) ";
    ptr_on_number = new IntNumber; 
    cin >> ptr_on_number->Number;  
    ptr_on_number->Next = NULL;    
    first = ptr_on_number;         
    for (int i = 1; i < amountOfElements; i++) {
        IntNumber* ptr_on_next_element = new IntNumber; 
        ptr_on_number->Next = ptr_on_next_element;      
        ptr_on_number = ptr_on_number->Next;           
        cout << i + 1 << ") ";
        cin >> ptr_on_number->Number;            
        ptr_on_number->Next = NULL;               
    }
}
void print(IntNumber* first) {
    if (first != NULL) {
        IntNumber* ptr_on_number = first;
        while (ptr_on_number != NULL) {
            cout << ptr_on_number->Number << endl;
            ptr_on_number = ptr_on_number->Next;
        }
    }
    else
        cout << "В списке нет элементов";
}
void delete_even_elements(IntNumber* &first) {
    IntNumber* ptr_on_number = first;
        while (((ptr_on_number->Number) % 2) == 0) {
            IntNumber* ptr_on_deleting_number = first;
            first = ptr_on_number->Next;
            delete ptr_on_deleting_number;
            ptr_on_number = first;
            if (ptr_on_number == NULL)
                return;
        }
    while (ptr_on_number->Next != NULL) {
        if (ptr_on_number->Next->Number % 2 == 0) {
            IntNumber* ptr_on_deleting_number = ptr_on_number->Next;
            ptr_on_number->Next = ptr_on_number->Next->Next;
            delete ptr_on_deleting_number;
        }
        else
            ptr_on_number = ptr_on_number->Next;
    }
}
void delete_list(IntNumber* &list) {
    while (list != NULL) {
        IntNumber* pointer = list;
        list = list->Next;
        delete pointer;
    }
}
bool has_even_elements(IntNumber* first) {
    while (first != NULL) {
        if (first->Number % 2 == 0)
            return true;
        first = first->Next;
    }
    return false;
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите количество элементов списка: ";
    int sizeOfList;
    do {
        cin >> sizeOfList;
        if (sizeOfList < 1)
            cout << "Введите положительное количество элементов!";
    } while (sizeOfList < 1);
    create(ListOfIntNumbers, sizeOfList);
    cout << "Исходный список:\n";
    print(ListOfIntNumbers);
    cout << endl;
    if (has_even_elements(ListOfIntNumbers)) {
        delete_even_elements(ListOfIntNumbers);
        cout << "Преобразованный список:\n";
    }
    else
        cout<<"Список остался без изменений:\n";
    print(ListOfIntNumbers);
    cout << endl;
    delete_list(ListOfIntNumbers);
    cout << "Содержимое списка после его удаления:\n";
    print(ListOfIntNumbers);
    cout << endl;
    return 0;
}