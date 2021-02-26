#include <iostream>
using namespace std;
struct Stack {
    int Number;
    Stack* Next;
};
int amountOfElements;
Stack* StackForIntNumbers = new Stack;
void push(Stack* &top, int element) {
    Stack* ptr_on_new_element = new Stack;
    ptr_on_new_element->Next = NULL;
    ptr_on_new_element->Number = element;
    ptr_on_new_element->Next = top;
    top = ptr_on_new_element;
}
void print(Stack* top) {
    Stack* pointer = top;
    if (top == NULL)
        cout << "Стек пуст\n";
    else
        while (pointer != NULL) {
            cout << pointer->Number << endl;
            pointer = pointer->Next;
        }
}
void pop(Stack*& top) {
    Stack* ptr_on_deleting_element = top;
    top = top->Next;
    delete ptr_on_deleting_element;
}
void delete_even_elements(Stack*& top) {
    Stack* temp_stack = new Stack;
    temp_stack = NULL;
    for (int i = 0; i < amountOfElements; i++) {
        if ((top->Number % 2) == 0)
            pop(top);
        else {
            push(temp_stack, top->Number);
            pop(top);
        }
    }
    while (temp_stack != NULL) {
        push(top, temp_stack->Number);
        pop(temp_stack);
    }
}
void clear(Stack* &top) {
    while (top != NULL)
        pop(top);
}
int main()
{
    setlocale(LC_ALL, "");
    StackForIntNumbers->Next = NULL;
    cout << "Введите количество элементов: ";
    do {
        cin >> amountOfElements;
        if (amountOfElements < 1)
            cout << "Число элементов должно быть больше 0\n";
    } while (amountOfElements < 1);
    int number;
    cout << "Введите элементы:\n";
    if (amountOfElements > 0) {
        cout << "1) ";
        cin >> number;
        StackForIntNumbers->Number = number;
    }
    for (int i = 2; i <= amountOfElements; i++) {
        cout << i << ") ";
        cin >> number;
        push(StackForIntNumbers, number);
    }
    cout << "Содержимое стека:\n";
    print(StackForIntNumbers);
    delete_even_elements(StackForIntNumbers);
    cout << "Содержимое стека после удаления четных элементов:\n";
    print(StackForIntNumbers);
    cout << "Содержимое стека после его опустошения:\n";
    clear(StackForIntNumbers);
    print(StackForIntNumbers);
    system("pause");
    return 0;
}