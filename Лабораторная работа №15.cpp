#include <iostream>
#include <ctime>
using namespace std;
int* firstArray, * secondArray;
int sizeOf_firstArray, sizeOf_secondArray;
void quick_sort(int* &array, int left, int right) {
    int middle_element = array[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        if (array[i] < middle_element)
            i++;
        else if (array[j] > middle_element)
            j--;
        else {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quick_sort(array, left, j);
    if (i < right)
        quick_sort(array, i, right);
}
void shell_sort(int*& array, int amountOfElements) {
    int temp_element, j;
    bool counterRestoringFlag = false; //флажок для восстановления значения счетчика 
    for (int distance = amountOfElements / 2; distance > 0; distance /= 2) {
        for (int i = distance; i < amountOfElements; i++) {
            temp_element = array[i];
            for (j = i; j >= distance; j -= distance)
                if (temp_element < array[j - distance]) {
                    array[j] = array[j - distance];
                }
                else {
                    counterRestoringFlag = true;    //истина в флажке говорит о том, что значение счетчика нужно будет восстановить
                    j = j - distance * i;           //значение счетчика должно гарантированно выйти за граничное значение, которое указано в условии
                }
            if (counterRestoringFlag) {        
                j = j + (distance * (i + 1));   //после возвращения в условие цикла мы еще один раз вычитаем расстояние,
                                                    //поэтому умножаем на i+1
                counterRestoringFlag = false;   //ложь говорит о том, что значение счетчика восстановлено
            }
            array[j] = temp_element;
        }
    }
}
void provide_correct_input(int &size) {
    do {
        cin >> size;
        if (size < 1)
            cout << "Нужно ввести положительное число\n";
    } while (size < 1);
}
void put_random_elements(int*& array, int size) {
    for (int i = 0; i < size; i++)
        array[i] = rand() % 500;
}
void input_elements(int*& array, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cin >> array[i];
    }
}
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ") ";
        cout << array[i] << endl;
    }
}
void find_intsersections_of_sets(int* first_array, int* second_array, int* &result_array, int &size_of_result_array) {
    int min_size = sizeOf_firstArray;
    int max_size = sizeOf_secondArray;
    if (max_size < min_size) {
        swap(max_size, min_size);
        swap(first_array, second_array);
    }
    int* temp_array = new int[min_size];
    int current_index_in_temp_array = 0;
    for (int i = 0; i < min_size; i++)
        for (int j = 0; j < max_size; j++)
            if (first_array[i] == second_array[j]) {
                temp_array[current_index_in_temp_array] = second_array[j];
                current_index_in_temp_array++;
                j = max_size;
            }
    size_of_result_array = current_index_in_temp_array;
    result_array = new int[size_of_result_array];
    for (int i = 0; i < current_index_in_temp_array; i++)
        result_array[i] = temp_array[i];
    delete[] temp_array;
}
void show_menu() {
    system("cls");
    int* array_for_common_elements;
    int sizeOf_array_for_common_elements;
    cout << "Введите размер первого множества: ";
    provide_correct_input(sizeOf_firstArray);
    firstArray = new int [sizeOf_firstArray];
    cout << "Введите размер второго множества: ";
    provide_correct_input(sizeOf_secondArray);
    secondArray = new int[sizeOf_secondArray];
    int optionForCreating = 0;
    int optionForSorting = 0;
    cout << "Введите способ заполнения множеств:\n";
    cout << "1) Генерация случайных чисел\n";
    cout << "2) Ручной ввод\n";
    cout << ">";
    cin >> optionForCreating;
    switch (optionForCreating) {
    case 1:
        put_random_elements(firstArray, sizeOf_firstArray);
        put_random_elements(secondArray, sizeOf_secondArray);
        cout << "Содержимое первого множества:\n";
        print_array(firstArray, sizeOf_firstArray);
        cout << "Содержимое второго множества:\n";
        print_array(secondArray, sizeOf_secondArray);
        break;
    case 2:
        cout << "Введите элементы первого множества:\n";
        input_elements(firstArray, sizeOf_firstArray);
        cout << "Введите элементы второго множества:\n";
        input_elements(secondArray, sizeOf_secondArray);
        break;
    }
    cout << "Выберите метод сортировки:\n";
    cout << "1) Сортировка Хоара\n";
    cout << "2) Сортировка Шелла\n";
    cin >> optionForSorting;
    switch (optionForSorting) {
    case 1:
        quick_sort(firstArray, 0, sizeOf_firstArray - 1);
        quick_sort(secondArray, 0, sizeOf_secondArray - 1);
        break;
    case 2:
        shell_sort(firstArray, sizeOf_firstArray);
        shell_sort(secondArray, sizeOf_secondArray);
        break;
    }
    cout << "Содержимое первого множества после сортировки:\n";
    print_array(firstArray, sizeOf_firstArray);
    cout << "Содержимое второго множества после сортировки:\n";
    print_array(secondArray, sizeOf_secondArray);
    cout << "Пересечение множеств:\n";
    find_intsersections_of_sets(firstArray, secondArray, array_for_common_elements, sizeOf_array_for_common_elements);
    if (sizeOf_array_for_common_elements == 0)
        cout << "В пересечении множеств элементы отсутствуют\n";
    else
        print_array(array_for_common_elements, sizeOf_array_for_common_elements);
}
int main()
{
    srand(static_cast<int>(time(0)));
    setlocale(LC_ALL, "");
    show_menu();
    system("pause");
    return 0;
}