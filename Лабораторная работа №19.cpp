#include <iostream>
using namespace std;

class Stack {
private:
    struct MyStack {
        int Number;
        MyStack* Next;
    };
    int amountOfElements;
    MyStack* StackForIntNumbers;
public:
    Stack() {
        amountOfElements = 0;
    }
    Stack(const int size) {
        amountOfElements = size;
    }
    void make_stack(const int size) {
        int number;
        amountOfElements = size;
        StackForIntNumbers = new MyStack;
        StackForIntNumbers->Next = NULL;
        cout << "Введите элементы:\n";
        if (amountOfElements > 0) {
            cout << "1) ";
            cin >> number;
            StackForIntNumbers->Number = number;
        }
        for (int i = 2; i <= amountOfElements; i++) {
            cout << i << ") ";
            cin >> number;
            push(number);
        }
    }
    void push(int element) {
        MyStack* ptr_on_new_element = new MyStack;
        ptr_on_new_element->Next = NULL;
        ptr_on_new_element->Number = element;
        ptr_on_new_element->Next = StackForIntNumbers;
        StackForIntNumbers = ptr_on_new_element;
    }
    void print_stack() {
        MyStack* pointer = StackForIntNumbers;
        if (StackForIntNumbers == NULL)
            cout << "Стек пуст\n";
        else
            while (pointer != NULL) {
                cout << pointer->Number << endl;
                pointer = pointer->Next;
            }
    }
    void pop() {
        MyStack* ptr_on_deleting_element = StackForIntNumbers;
        StackForIntNumbers = StackForIntNumbers->Next;
        delete ptr_on_deleting_element;
    }
    void clear() {
        while (StackForIntNumbers != NULL)
            pop();
    }
    void delete_even_elements() {
        Stack temp_stack;
        for (int i = 0; i < amountOfElements; i++) {
            if ((StackForIntNumbers->Number % 2) == 0)
                pop();
            else {
                temp_stack.push(StackForIntNumbers->Number);
                pop();
            }
        }
        while (!temp_stack.isEmpty()) {
            push(temp_stack.top());
            temp_stack.pop();
        }
    }
    bool isEmpty() {
        return (StackForIntNumbers == NULL);
    }
    int top() {
        return (StackForIntNumbers->Number);
    }
    ~Stack() {
        clear();
    }
};
int main()
{
    setlocale(LC_ALL, "");
    int size;
    cout << "Введите количество элементов: ";
    do {
        cin >> size;
        if (size < 1)
            cout << "Число элементов должно быть больше 0\n";
    } while (size < 1);
    Stack my_stack;
    my_stack.make_stack(size);
    cout << "Содержимое стека:\n";
    my_stack.print_stack();
    my_stack.delete_even_elements();
    cout << "Содержимое стека после удаления четных элементов:\n";
    my_stack.print_stack();
    cout << "Содержимое стека после его опустошения:\n";
    my_stack.clear();
    my_stack.print_stack();
    system("pause");
    return 0;
}