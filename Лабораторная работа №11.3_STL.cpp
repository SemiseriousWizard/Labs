#include <iostream>
#include <stack>
using namespace std;
stack<int> StackForIntNumbers;
int sizeOfStack;
void print(stack<int> &stack_top, int amountOfElements) {
    if (stack_top.empty())
        cout << "Стек пуст\n";
    else {
        stack<int> temp_stack;
        for (int i = 0; i < amountOfElements; i++) {
            cout << stack_top.top() << endl;
            temp_stack.push(stack_top.top());
            stack_top.pop();
        }
        for (int i = 0; i < amountOfElements; i++) {
            stack_top.push(temp_stack.top());
            temp_stack.pop();
        }
    }
}
void delete_even_elements(stack<int> &stack_top, int amountOfElements) {
    stack<int> temp_stack;
    int sizeOfTempStack = amountOfElements;
    for (int i = 0; i < amountOfElements; i++) {
        if ((stack_top.top() % 2) == 0) {
            stack_top.pop();
            sizeOfTempStack--;
        }
        else {
            temp_stack.push(stack_top.top());
            stack_top.pop();
        }
    }
    for (int i = 0; i < sizeOfTempStack; i++) {
        stack_top.push(temp_stack.top());
        temp_stack.pop();
    }
}
void clear(stack<int> &stack_top, int amountOfElements) {
    for (int i = 0; i < amountOfElements; i++)
        stack_top.pop();
}
int main()
{
    setlocale(LC_ALL, "");
    cout << "Введите количество элементов: ";
    do {
        cin >> sizeOfStack;
        if (sizeOfStack < 1)
            cout << "Число элементов должно быть больше 0\n";
    } while (sizeOfStack < 1);
    int number;
    cout << "Введите элементы:\n";
    for (int i = 1; i <= sizeOfStack; i++) {
        cout << i << ") ";
        cin >> number;
        StackForIntNumbers.push(number);
    }
    cout << "Содержимое стека:\n";
    print(StackForIntNumbers, StackForIntNumbers.size());
    delete_even_elements(StackForIntNumbers, StackForIntNumbers.size());
    cout << "Содержимое стека после удаления четных элементов:\n";
    print(StackForIntNumbers, StackForIntNumbers.size());
    cout << "Содержимое стека после его опустошения:\n";
    clear(StackForIntNumbers, StackForIntNumbers.size());
    print(StackForIntNumbers, StackForIntNumbers.size());
    system("pause");
    return 0;
}