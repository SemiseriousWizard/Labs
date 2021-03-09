#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
struct Person {
    string FullName;
    int PhoneNumber;
    string Address;
};
struct ListPerson : public Person {
    ListPerson* Next;
};
const string DataBasePath = "DataBase.txt";
Person* DynamicArrayForPersons;
ListPerson* ListForPersons;
ListPerson* ListForDeletedPersons;
//ListPerson* ListForMarklessPersons;
ListPerson* ptr_on_new_element;
int indexOfLastDeletedElement; //если элементов, помеченных на удаление, в структуре станет слишком много, 
                                //то все они (кроме последнего помеченного) удалятся
int saveAmountOfElementsInDataBase; //чтобы обеспечить удаление ненужных элементов в списке
int amountOfRecordsInDataBase = 0, amountOfDeletedElements = 0;
//search options
int searchPhoneNumber = 0;  //поле для интерполяционного поиска
string searchAddress = "";  //поле для линейного поиска
int indexOfFoundElementInList = -1;
//
//flags
bool isExit = false;
bool showRestoreElementsOption = false;
bool showSaveChangesOption = false;
//
void get_data_from_database() {
    string str_for_data;
    fstream InputFile;
    InputFile.open(DataBasePath, fstream::in);
    if (InputFile.is_open() && (amountOfRecordsInDataBase == 0))
        while (!InputFile.eof()) {
            getline(InputFile, str_for_data);
            amountOfRecordsInDataBase++;
        }
    InputFile.close();
    amountOfRecordsInDataBase /= 3;
    saveAmountOfElementsInDataBase = amountOfRecordsInDataBase; //сохраняем начальное кол-во элементов до удаления
    InputFile.open(DataBasePath, fstream::in);
    DynamicArrayForPersons = new Person[amountOfRecordsInDataBase];
    if (InputFile.is_open()) {
        for (int i = 0; i < amountOfRecordsInDataBase; i++) {
            str_for_data = "";
            getline(InputFile, DynamicArrayForPersons[i].FullName);
            getline(InputFile, str_for_data);
            DynamicArrayForPersons[i].PhoneNumber = stoll(str_for_data, 0, 10);
            getline(InputFile, DynamicArrayForPersons[i].Address);
        }
    }
    InputFile.close();
}
void create_list(ListPerson*& first_element) {
    if (DynamicArrayForPersons != NULL) {
        first_element = new ListPerson;
        first_element->FullName = DynamicArrayForPersons[0].FullName;
        first_element->PhoneNumber = DynamicArrayForPersons[0].PhoneNumber;
        first_element->Address = DynamicArrayForPersons[0].Address;
        first_element->Next = NULL;
        ListPerson* ptr_on_first_element = first_element;  //сохранить указатель на 1й элемент
        for (int i = 1; i < amountOfRecordsInDataBase; i++) {
            ListPerson* ptr_on_new_element = new ListPerson;
            ptr_on_new_element->FullName = DynamicArrayForPersons[i].FullName;
            ptr_on_new_element->PhoneNumber = DynamicArrayForPersons[i].PhoneNumber;
            ptr_on_new_element->Address = DynamicArrayForPersons[i].Address;
            ptr_on_new_element->Next = NULL;
            first_element->Next = ptr_on_new_element;
            first_element = first_element->Next;
        }
        first_element = ptr_on_first_element;
    }
}
void create_dynamic_array(ListPerson* first, Person*& array) {
    delete[] array;
    array = new Person[amountOfRecordsInDataBase];
    int i = 0;
    while (first != NULL) {
        array[i].FullName = first->FullName;
        array[i].PhoneNumber = first->PhoneNumber;
        array[i].Address = first->Address;
        i++;
        first = first->Next;
    }
}
void sort_array(Person*& array) {   //метод вставки
    for (int i = 1; i < amountOfRecordsInDataBase; i++)
        for (int j = i - 1; j >= 0; j--)
            if (array[j + 1].PhoneNumber <= array[j].PhoneNumber)
                swap(array[j + 1], array[j]);
}
void add_element_in_list(ListPerson*& first, ListPerson* new_element, int index) {
    ListPerson* ptr_on_first_element = first;
    new_element->Next = NULL;
    if (first == NULL) {
        first = new ListPerson;
        first->FullName = new_element->FullName;
        first->PhoneNumber = new_element->PhoneNumber;
        first->Address = new_element->Address;
        first->Next = NULL;
        return;
    }
    if (index == 1) {
        ListPerson* new_first_element = new ListPerson;
        new_first_element->FullName = new_element->FullName;
        new_first_element->PhoneNumber = new_element->PhoneNumber;
        new_first_element->Address = new_element->Address;
        new_first_element->Next = first;
        first = new_first_element;
    }
    else if (index == amountOfRecordsInDataBase) {
        while (first->Next != NULL)
            first = first->Next;
        first->Next = new_element;
        first = ptr_on_first_element;
    }
    else {
        for (int i = 2; i < index; i++)
            first = first->Next;
        new_element->Next = first->Next;
        first->Next = new_element;
        first = ptr_on_first_element;
    }
}
void print_list(ListPerson* first) {
    int i = 1;
    cout << "   Имя человека     " << '\t' << "   Номер телефона   " << "\t" << "   Домашний адрес   " << endl;
    while (first != NULL) {
        cout << i << ":\n";
        cout << first->FullName << "\t\t" << first->PhoneNumber << "\t\t" << first->Address << endl;
        cout << endl;
        i++;
        first = first->Next;
    }
}
void print_dynamic_array() {
    cout << "   Имя человека     " << '\t' << "   Номер телефона   " << "\t" << "   Домашний адрес   " << endl;
    for (int i = 0; i < amountOfRecordsInDataBase; i++) {
        cout << i + 1 << ":\n";
        cout << DynamicArrayForPersons[i].FullName << "\t\t" << DynamicArrayForPersons[i].PhoneNumber << "\t\t" << DynamicArrayForPersons[i].Address << endl;
        cout << endl;
    }
}
void clear_list(ListPerson*& first) {
    ListPerson* ptr_on_deleting_element;
    while (first != NULL) {
        ptr_on_deleting_element = first;
        first = first->Next;
        delete ptr_on_deleting_element;
    }
}
void delete_element_from_list(ListPerson*& first, int index_of_deleting_element) {
    ListPerson* ptr_on_deleting_element = new ListPerson;
    int current_index = 1;
    if (index_of_deleting_element == 1) {
        ptr_on_deleting_element = first;
        first = first->Next;
        add_element_in_list(ListForDeletedPersons, ptr_on_deleting_element, 1);
        delete ptr_on_deleting_element;
    }
    else if (index_of_deleting_element == amountOfRecordsInDataBase) {
        ListPerson* ptr_on_current_element = first;
        if (amountOfRecordsInDataBase == 1) {
            add_element_in_list(ListForDeletedPersons, first, 1);
            ptr_on_deleting_element = first;
            first = first->Next;
            delete ptr_on_deleting_element;
        }
        else {
            ListPerson* ptr_on_penultimate_element = new ListPerson;
            ptr_on_deleting_element = first;
            while (ptr_on_deleting_element->Next != NULL) {
                ptr_on_penultimate_element = ptr_on_deleting_element;
                ptr_on_deleting_element = ptr_on_deleting_element->Next;
            }
            ptr_on_penultimate_element->Next = NULL;
            add_element_in_list(ListForDeletedPersons, ptr_on_deleting_element, 1);
            delete ptr_on_deleting_element;
        }
    }
    else {
        ListPerson* ptr_on_current_element = first;
        while (ptr_on_current_element->Next != NULL) {
            current_index++;
            if (current_index == index_of_deleting_element) {
                ptr_on_deleting_element = ptr_on_current_element->Next;
                ptr_on_current_element->Next = ptr_on_current_element->Next->Next;
                add_element_in_list(ListForDeletedPersons, ptr_on_deleting_element, 1);
                delete ptr_on_deleting_element;
            }
            else
                ptr_on_current_element = ptr_on_current_element->Next;
        }
    }
    amountOfRecordsInDataBase--;
}
void save_data_in_database(Person* array) {
    fstream OutputFile;
    OutputFile.open(DataBasePath, fstream::out);
    int i;
    for (i = 0; i < amountOfRecordsInDataBase - 1; i++)
        OutputFile << array[i].FullName << "\n" << array[i].PhoneNumber << "\n" << array[i].Address << '\n';
    OutputFile << array[i].FullName << "\n" << array[i].PhoneNumber << "\n" << array[i].Address;
    OutputFile.close();
}
string concat_string_addresses(ListPerson*& first) {  //для осуществления прямого поиска подстроки в строке
    ListPerson* ptr_on_first_element = first;
    string result_str = "";
    while (first != NULL) {
        result_str += first->Address;
        first = first->Next;
    }
    first = ptr_on_first_element;
    return result_str;
}
int substr_in_string_search(string substring) {
    int indexOfLastSymbolInString = -1;
    string string_addresses = concat_string_addresses(ListForPersons);
    int string_addresses_length = string_addresses.length();
    int substring_length = substring.length();
    for (int i = 0; i < string_addresses_length - substring_length + 1; i++)
        for (int j = 0; j < substring_length; j++)
            if (substring[j] != string_addresses[i + j])
                j = substring_length;
            else if (j == (substring_length - 1)) {
                indexOfLastSymbolInString = i / 20 + 1;
                return indexOfLastSymbolInString;
            }
    return -1;
}

void prefix_function(int prefix_array[], string substring) {
    int left_index = 0, right_index;
    prefix_array[0] = 0;
    for (right_index = 1; right_index < 19; right_index++) {
        if (substring[left_index] == substring[right_index]) {
            prefix_array[right_index] = left_index + 1;
            left_index++; //сдвигаем левую границу вправо, правая граница тоже сдвинется
        }
        else {
            if (left_index == 0)
                prefix_array[right_index] = 0;
            else {
                left_index = prefix_array[left_index - 1]; //смещаем левую границу левее, чтобы расширить зону поиска макс. длины суфф и преф
                right_index--;
            }
        }
    }
}
int kmp_algorithm(string substring) {  //Алгоритм Кнута-Морриса-Пратта
    int index_in_str, index_in_substr = 0;
    string string_addresses = concat_string_addresses(ListForPersons);
    int string_addresses_length = string_addresses.length();
    int prefix_array[20];
    for (int i = 0; i < 20; i++)
        prefix_array[i] = 0;
    prefix_function(prefix_array, substring);
    for (index_in_str = 0; index_in_str < string_addresses_length; index_in_str++) {
        if (string_addresses[index_in_str] == substring[index_in_substr])
            if (index_in_substr == 19)
                return (index_in_str - index_in_substr) / 20 + 1; //+1, т.к. удаление происходит в списке
            else
                index_in_substr++;
        else if (index_in_substr != 0) {
            index_in_substr = prefix_array[index_in_substr - 1];
            index_in_str--;
        }
    }
    return -1;
}
int boyer_moore(string substring) { //сравнение с конца образа, сдвиги больше 1 символа (зачастую) при несовпадении
    string string_addresses = concat_string_addresses(ListForPersons);
    int string_addresses_length = string_addresses.length();
    int substring_length = substring.length();
    if ((string_addresses_length > 0) && (substring_length > 0) && (string_addresses_length >= substring_length)) {
        int i, last_element_position;
        int offset_array[256];
        for (i = 0; i < 256; i++)   //сдвиг всех символов равен длине образа, затем сдвиг для элементов образа изменится
            offset_array[i] = substring_length;
        for (i = substring_length - 2; i >= 0; i--)
            if (offset_array[int(unsigned char(substring[i]))] == substring_length)
                offset_array[int(unsigned char(substring[i]))] = substring_length - i - 1;  //ставим сдвиги, просматривая строку, а не образ
        last_element_position = substring_length - 1;
        while (last_element_position < string_addresses_length) {
            if (substring[substring_length - 1] != string_addresses[last_element_position])
                last_element_position += offset_array[int(unsigned char(string_addresses[last_element_position]))];
            else {
                for (i = substring_length - 1; i >= 0; i--)
                    if (substring[i] != string_addresses[last_element_position - substring_length + i + 1]) { //новый сдвиг, если символы не равны
                        last_element_position += offset_array[int(unsigned char(string_addresses[last_element_position - substring_length + i + 1]))];
                        i = -1; //вместо break
                    }
                    else if (i == 0)
                        return (last_element_position - substring_length + 1) / 20 + 1; //+1, т.к. удаление происходит в списке
            }
        }
    }
    return -1;
}
void delete_first_element_in_list(ListPerson*& first) {
    if (first != NULL) {
        ListPerson* ptr_on_deleting_element = first;
        first = first->Next;
        delete ptr_on_deleting_element;
    }
}
void restore_elements() {
    while (ListForDeletedPersons != NULL) {
        ListPerson* ptr_on_last_deleted_element = new ListPerson;
        ptr_on_last_deleted_element->FullName = ListForDeletedPersons->FullName;
        ptr_on_last_deleted_element->PhoneNumber = ListForDeletedPersons->PhoneNumber;
        ptr_on_last_deleted_element->Address = ListForDeletedPersons->Address;
        ptr_on_last_deleted_element->Next = NULL;
        add_element_in_list(ListForPersons, ptr_on_last_deleted_element, 1);
        amountOfRecordsInDataBase++;
        delete_first_element_in_list(ListForDeletedPersons);
    }
}
void provide_correct_address_input(string& address) {
    int length_address;
    do {
        cin.ignore();
        getline(cin, address);
        length_address = address.length();
        if (length_address != 20)
            cout << "Длина адреса должна составлять 20 символов\n";
    } while (length_address != 20);
}
void show_menu() {
    system("cls");
    if (amountOfDeletedElements > (saveAmountOfElementsInDataBase / 2)) {//очищаем список "удаленных" элементов за исключением последнего элемента
        amountOfDeletedElements = 1;
        saveAmountOfElementsInDataBase = amountOfRecordsInDataBase + 1;
        ListPerson* ptr_on_second_element_in_listOfDeletedPersons = new ListPerson;
        ptr_on_second_element_in_listOfDeletedPersons = ListForDeletedPersons->Next;
        ListForDeletedPersons->Next = NULL;
        clear_list(ptr_on_second_element_in_listOfDeletedPersons);
    }
    int option, furtherOption;
    int indexOfNewElement = 0;
    int indexOfExtraOption = 4;
    int indexOfRestoreElementsOption = indexOfExtraOption, indexOfSaveChangesOption;    //индексы доступных опций 
                                                    //меняются в ходе выполнения программы в зависимости от действий пользователя
    cout << "МЕНЮ\n";
    cout << "0) Завершить выполнение программы\n";
    cout << "1) Вывести информацию из базы данных\n";
    cout << "2) Добавить информацию в базу данных\n";
    cout << "3) Удалить найденную информацию\n";
    if (showRestoreElementsOption)
        cout << indexOfExtraOption++ << ") Отменить удаление элементов" << endl;
    indexOfSaveChangesOption = indexOfExtraOption;
    if (showSaveChangesOption)
        cout << indexOfExtraOption << ") Сохранить изменения\n";
    cout << "Выберите действие: ";
    cin >> option;
    switch (option)
    {
    case 0:
        isExit = true;
        break;
    case 1:
        print_dynamic_array();
        system("pause");
        break;
    case 2:
        cout << "Выберите место для вставки:\n";
        cout << "1) В начало\n";
        cout << "2) В конец\n";
        if (amountOfRecordsInDataBase > 2)
            cout << "3) В произвольное место\n";
        cout << ">";
        cin >> furtherOption;
        switch (furtherOption)
        {
        case 1:
            indexOfNewElement = 1;
            break;
        case 2:
            indexOfNewElement = amountOfRecordsInDataBase;
            break;
        case 3:
            if (amountOfRecordsInDataBase > 2) {
                cout << "Введите индекс для добавления элемента (от 2 до " << amountOfRecordsInDataBase - 1 << "): ";
                do {
                    cin >> indexOfNewElement;
                    if (indexOfNewElement < 2 || indexOfNewElement > amountOfRecordsInDataBase - 1)
                        cout << "Можно вводить число от 2 до " << amountOfRecordsInDataBase - 1 << "\n";
                } while (indexOfNewElement < 2 || indexOfNewElement > amountOfRecordsInDataBase - 1);
            }
            break;
        }
        //Ввод данных
        ptr_on_new_element = new ListPerson;
        cout << "Введите данные:\n";
        cout << "ФИО: ";
        cin.ignore();
        getline(cin, ptr_on_new_element->FullName);
        cout << "Номер телефона: ";
        cin >> ptr_on_new_element->PhoneNumber;
        cout << "Адрес: ";
        provide_correct_address_input(ptr_on_new_element->Address);
        //
        add_element_in_list(ListForPersons, ptr_on_new_element, indexOfNewElement);
        print_list(ListForPersons);
        amountOfRecordsInDataBase++;
        saveAmountOfElementsInDataBase++;
        system("pause");
        create_dynamic_array(ListForPersons, DynamicArrayForPersons);
        sort_array(DynamicArrayForPersons);
        create_list(ListForPersons);
        showSaveChangesOption = true;
        break;
    case 3:
        if (amountOfRecordsInDataBase == 1) {
            cout << "Вы не можете удалить единственный элемент в базе данных\n";
            system("pause");
            return;
        }
        cout << "Выберите метод поиска:\n";
        cout << "1) Бойера - Мура\n";
        cout << "2) Кнута - Морриса - Пратта\n";
        cout << "3) Прямой\n";
        cout << ">";
        cin >> furtherOption;
        switch (furtherOption)
        {
        case 1:
            cout << "Введите адрес: ";
            searchAddress = "";
            provide_correct_address_input(searchAddress);
            indexOfFoundElementInList = boyer_moore(searchAddress);
            break;
        case 2:
            cout << "Введите адрес: ";
            searchAddress = "";
            provide_correct_address_input(searchAddress);
            indexOfFoundElementInList = kmp_algorithm(searchAddress);
            break;
        case 3:
            cout << "Введите адрес: ";
            searchAddress = "";
            provide_correct_address_input(searchAddress);
            indexOfFoundElementInList = substr_in_string_search(searchAddress);
            break;
        }
        if (indexOfFoundElementInList == -1)
            cout << "Такого элемента в базе данных нет\n";
        else {
            delete_element_from_list(ListForPersons, indexOfFoundElementInList);
            cout << "Элемент удален из базы данных\n";
            amountOfDeletedElements++;
            print_list(ListForPersons);
            create_dynamic_array(ListForPersons, DynamicArrayForPersons);
            showRestoreElementsOption = true;
            showSaveChangesOption = true;
        }
        system("pause");
        break;
    }
    if (showRestoreElementsOption) {
        if (option == indexOfRestoreElementsOption) {
            restore_elements();
            amountOfDeletedElements = 0;
            create_dynamic_array(ListForPersons, DynamicArrayForPersons);
            sort_array(DynamicArrayForPersons);
            print_dynamic_array();
            system("pause");
            showRestoreElementsOption = false;
            showSaveChangesOption = true;
        }
    }
    if (showSaveChangesOption) {
        if (option == indexOfSaveChangesOption) {
            clear_list(ListForDeletedPersons);
            save_data_in_database(DynamicArrayForPersons);
            showRestoreElementsOption = false;
            showSaveChangesOption = false;
        }
    }
}
string create_random_string() {
    string result = "";
    char random_symbol;
    int random_symbol_code;
    for (int j = 0; j < 20; j++) {
        random_symbol_code = rand() % 26 + 97;
        random_symbol = (char)random_symbol_code;
        result += random_symbol;
    }
    return result;
}
void create_database(int size) {

    string random_string;
    fstream OutputFile;
    OutputFile.open(DataBasePath, fstream::out);
    for (int i = 1; i < size; i++) {
        random_string = "";
        random_string = create_random_string();
        OutputFile << random_string << endl;
        random_string = "";
        OutputFile << (rand() % 999 + 20000) << endl;
        random_string = create_random_string();
        OutputFile << random_string << endl;
    }
    random_string = "";
    random_string = create_random_string();
    OutputFile << random_string << endl;
    random_string = "";
    OutputFile << (rand() % 999 + 20000) << endl;
    random_string = create_random_string();
    OutputFile << random_string;
    OutputFile.close();
}
int main()
{
    int sizeOfDataBase = 0;
    srand(static_cast<int>(time(0)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Введите количество записей в базе данных: ";
    do {
        cin >> sizeOfDataBase;
        if (sizeOfDataBase < 1)
            cout << "Число должно быть положительным\n";
    } while (sizeOfDataBase < 1);
    create_database(sizeOfDataBase);
    get_data_from_database();
    sort_array(DynamicArrayForPersons);
    create_list(ListForPersons);
    while (!isExit)
        show_menu();
    delete[] DynamicArrayForPersons;
    clear_list(ListForPersons);
    clear_list(ListForDeletedPersons);
    return 0;
}