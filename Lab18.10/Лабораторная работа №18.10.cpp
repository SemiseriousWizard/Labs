#include "Money.h"
int create_DB(const char* file_name)
{
    fstream stream(file_name, ios::out | ios::trunc);
    if (!stream)
        return -1;
    int amountOfObjects;
    Money money;
    cout << "Введите количество элементов: "; 
    cin >> amountOfObjects; 
    for (int i = 0; i < amountOfObjects; i++)
    {
        cin >> money;
        stream<<money<<"\n";
    }
    stream.close();
    return amountOfObjects;
}
int output_DB(const char* file_name)
{
    fstream stream(file_name, ios::in);
    if(!stream)
        return -1;//ошибка открытия файла
    Money money;
    negative_zero_index_file.open("negative_zero.txt", ios::in);
    int i = 0, indexFromFile = -1;  
    if (negative_zero_index_file.is_open())
        negative_zero_index_file >> indexFromFile;
    while (stream >> money)
    {
        i++; 
        if (i == indexFromFile) {
            cout << '-';
            if (negative_zero_index_file.is_open())
                negative_zero_index_file >> indexFromFile;
        }
        cout << money << "\n";
    }
    stream.close(); 
    negative_zero_index_file.close();
    return i;
}
int delete_element(const char* file_name, Money& element) {
    Money money;
    fstream stream(file_name,ios::in);
    fstream temp("temp.tmp", ios::out);
    if(!stream)
        return -1;//ошибка открытия файла
    int i = 0;
    while (stream >> money)
    {
        if (stream.eof())
            break;
        i++;
        if(money != element)
            temp<<money;
    }
    stream.close();
    temp.close();
    remove(file_name);
    rename("temp.tmp", file_name);
    return i;

}
bool isElementInFile(const char* file_name, Money& element, int& indexOfElementInFile) {
    fstream stream(file_name, ios::in);
    indexOfElementInFile = -1;
    int index = 1;
    Money money;
    while (stream >> money) {
        if (stream.eof())
            break;
        if (money == element) {
            indexOfElementInFile = index;
            stream.close();
            return true;
        }
        index++;
    }
    stream.close();
    return false;
}
void add_elements(const char* file_name, Money* money_array, const int money_array_size, const int index) {
    fstream temp("temp.tmp", ios::out);
    fstream stream(file_name, ios::in);
    Money money;
    for (int i = 0; i < index; i++) {
        stream >> money;
        temp << money;
    }
    for (int i = 0; i < money_array_size; i++)
        temp << money_array[i];
    while (stream >> money) {
        if (stream.eof())
            break;
        temp << money;
    }
    stream.close();
    temp.close();
    remove(file_name);
    rename("temp.tmp", file_name);
}
void substract_element(const char* file_name, Money& found_money) {
    fstream temp("temp.tmp", ios::out);
    fstream stream(file_name, ios::in);
    negative_zero_index_file.open("negative_zero.txt", ios::out);
    //fstream nn("nn.txt", ios::out);
    Money money;
    while (stream >> money) {
        index++;
        if (stream.eof())
            break;
        if (money != found_money)
            temp << money;
        else {
            //Money bb(money);
            //double dd = (money - 1.5);
            //bb - 1.5;
            double sub_result = money - 1.5;
            if (sub_result < 0 && sub_result > -1)
                negative_zero_index_file << index << endl;
            temp << money;
        }
    }
    stream.close();
    temp.close();
    negative_zero_index_file.close();
    index = 0;
    remove(file_name);
    rename("temp.tmp", file_name);
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Money* money_new = NULL;
    Money delete_m;
    Money p; int k,option;
    Money money;
    int indexInFile;
    char file_name[30];
    do
    {	//Меню
        cout << "\nВведите действие:\n";
        cout<<"0) Выйти из программы\n";
        cout << "1) Создать файл\n";
        cout << "2) Вывести содержимое файла\n";
        cout << "3) Удалить запись из файла\n";
        cout << "4) Добавить записи после элемента с заданным значением\n";
        cout << "5) Уменьшить все записи с заданным значением на 1 рубль 50 копеек\n";
        cin>>option; 
        switch(option)
        {
        case 1: 
            remove("negative_zero.txt");
            cout<<"Введите название файла: "; 
            cin>>file_name; 
            create_DB(file_name);
            break;
        case 2: 
            cout<<"Введите название файла: "; 
            cin>>file_name;
            output_DB(file_name);
            break;
        case 3:
            cout << "Введите название файла: "; 
            cin >> file_name; 
            cout << "Введите значение, которое хотите удалить: \n"; 
            cin >> delete_m;
            delete_element(file_name, delete_m);
            break;
        case 4:
            cout << "Введите название файла: ";
            cin >> file_name;
            cin >> money;
            if (isElementInFile(file_name, money, indexInFile)) {
                cout << "Введите количество новых записей: ";
                int size;
                cin >> size;
                money_new = new Money[size];
                for (int i = 0; i < size; i++)
                    cin >> money_new[i];
                add_elements(file_name, money_new, size, indexInFile);
            }
            break;
        case 5:
            cout << "Введите название файла: ";
            cin >> file_name;
            cin >> money;
            if (isElementInFile(file_name, money, indexInFile))
                substract_element(file_name, money);
            break;
        }
    } while(option!=0);
    system("pause");
    delete[] money_new;
    return 0;
}
