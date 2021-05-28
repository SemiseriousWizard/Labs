#include "Point.h"
#include <cmath>
using namespace std;
int sizeOfArray;
Point make_point(Point *point) {
    point->Read();
    if (isExit) {
        cout << "Выполнение программы завершено." << endl;
        return *point;
    }
    else
        return *point;
}
Point* make_point(Point* point, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << "я точка:" << endl;
        point[i].Read();
        if (isExit) {
            cout << "Выполнение программы завершено." << endl;
            return point;
        }
    }
    return point;
}
void provide_correct_input(int &number) {
    do {
        cin >> number;
        if (number < 3)
            cout << "Введите положительное число большее 2" << endl;
    } while (number < 3);
}
void provide_correct_index_input(int& index) {
    do {
        cout << "Введите номер массива (от 1 до " << sizeOfArray << ")" << endl;
        cin >> index;
    } while (index < 1 || index > sizeOfArray);
}
void menu() {
    Point* firstPoint = new Point, * secondPoint = new Point;
    Point* arrayOfPoints;
    int firstPoint_index, secondPoint_index;
    cout << "Выберите дальнейшее действие: " << endl;
    cout << "0) Выйти" << endl;
    cout << "1) Ввести координаты двух точек" << endl;
    cout << "2) Ввести координаты более двух точек" << endl;
    int option = 0;
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case 0:
        cout << "Выполнение программы завершено." << endl;
        return;
        break;
    case 1:
        cout << "Введите координаты точки M:" << endl;
        *firstPoint = make_point(firstPoint);
        if (isExit)
            return;
        cout << "Введите координаты точки N:" << endl;
        *secondPoint = make_point(secondPoint);
        if (isExit)
            return;
        firstPoint->distance(secondPoint->first, secondPoint->second);
        delete firstPoint;
        delete secondPoint;
        break;
    case 2:
        cout << "Введите размер массива: ";
        provide_correct_input(sizeOfArray);
        cin.ignore();
        arrayOfPoints = new Point[sizeOfArray];
        arrayOfPoints = make_point(arrayOfPoints, sizeOfArray);
        cout << "Введите номер точки M: ";
        provide_correct_index_input(firstPoint_index);
        cout << "Введите номер точки N: ";
        provide_correct_index_input(secondPoint_index);
        firstPoint_index--;
        secondPoint_index--;
        arrayOfPoints[firstPoint_index].distance(arrayOfPoints[secondPoint_index].first,
            arrayOfPoints[secondPoint_index].second);
        delete[] arrayOfPoints;
        break;
    }
}
int main()
{
    setlocale(LC_ALL, "");
    menu();
    system("pause");
    return 0;
}