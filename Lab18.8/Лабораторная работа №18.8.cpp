#include <iostream>
#include <string>
#include <Windows.h>
#include "Object.h"
#include "TEvent.h"
#include "PRINT.h"
#include "BOOK.h"
#include "List.h"
#include "Dialog.h"
using namespace std;
void show_menu() {
    cout << "Список команд:\n";
    cout << "m<количество_элементов> - Создать группу" << endl;
    cout << "+                       - Добавить элемент в группу" << endl;
    cout << "-                       - Удалить последний элемент из группы" << endl;
    cout << "s                       - Вывести информацию об элементах группы" << endl;
    cout << "z<k>                    - Вывести информацию о названии элемента группы с номером k" << endl;
    cout << "                           (нумерация элементов начинается с единицы)" << endl;
    cout << "q                       - Конец работы" << endl << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Ввод информации о двух элементах с последующим выводом:\n";
    PRINT* my_print = new PRINT;
    my_print->input();
    my_print->show();

    BOOK* my_book = new BOOK;
    my_book->input();
    my_book->show();
    indexOfPrintedElement = 0;
    
    cout << endl;
    show_menu();
    Dialog D;
    D.Execute();
    system("pause");
    return 0;
}
