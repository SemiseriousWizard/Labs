#include <iostream>
#include <string>
using namespace std;
struct Patient {
    string Name;
    string Address;
    int MedicalCardNumber;
    int InsurancePolicyNumber;
};
Patient* patients;
const int amountOfExtraPatients = 2;
void provide_correct_input(int& number) {
    do {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Нужно ввести положительное число!\n";
            continue;
        }
        if (number > 0)
            break;
        else
            cout << "Нужно ввести положительное число!\n";

    } while (true);
}
void create(Patient patients_array[], int array_length) {
    cout << "Заполните данные о пациентах:\n";
    for (int i = 0; i < array_length; i++) {
        cout << i + 1 << ")\n";
        cout << "Введите ФИО: ";
        cin.ignore();
        getline(cin, patients_array[i].Name);
        cout << "Введите домашний адрес: ";
        getline(cin, patients_array[i].Address);
        cout << "Введите номер медицинской карты: ";
        provide_correct_input(patients_array[i].MedicalCardNumber);
        cout << "Введите номер страхового полиса: ";
        provide_correct_input(patients_array[i].InsurancePolicyNumber);
        cout << endl;
    }
}
void print(int array_length) {
    if (array_length == 0)
        cout << "Пациентов в базе данных нет.\n";
    else {
        cout << endl;
        cout << "Информация о пациентах:\n";
        for (int i = 0; i < array_length; i++) {
            cout << i + 1 << ")\n";
            cout << "ФИО: " << patients[i].Name << endl;
            cout << "Домашний адрес: " << patients[i].Address << endl;
            cout << "Номер медицинской карты: " << patients[i].MedicalCardNumber << endl;
            cout << "Номер страхового полиса: " << patients[i].InsurancePolicyNumber << endl;
            cout << endl;
        }
    }
}
void add_elements_in_beginning(int& array_length) {
    Patient* array_copy = new Patient[array_length + amountOfExtraPatients];
    create(array_copy, amountOfExtraPatients);
    for (int i = 0; i < array_length; i++)
        array_copy[i + amountOfExtraPatients] = patients[i];
    array_length += amountOfExtraPatients;
    patients = array_copy;
}
void delete_element(int& array_length, unsigned int medCardNumber_for_patient_deleting) {
    int indexOfDeletingElement = -1;
    for (int i = 0; i < array_length; i++)
        if (patients[i].MedicalCardNumber == medCardNumber_for_patient_deleting) {
            indexOfDeletingElement = i;
            break;
        }
    if (indexOfDeletingElement == -1) {
        cout << "Пациент с таким номером мед. карты в базе данных не найден.\n";
        return;
    }
    for (int i = indexOfDeletingElement; i < array_length - 1; i++)
        patients[i] = patients[i + 1];
    array_length--;
    Patient* array_copy = new Patient[array_length];
    for (int i = 0; i < array_length; i++)
        array_copy[i] = patients[i];
    patients = array_copy;
}
int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251>nul");
    cout << "Введите количество пациентов: ";
    int amountOfPatients = 0;
    provide_correct_input(amountOfPatients);
    patients = new Patient[amountOfPatients];
    create(patients, amountOfPatients);
    print(amountOfPatients);
    cout << "Удаление пациента из базы данных:\n";
    cout << "Введите номер медицинской карты: ";
    int medCardNumber_for_patient_deleting;
    provide_correct_input(medCardNumber_for_patient_deleting);
    delete_element(amountOfPatients, medCardNumber_for_patient_deleting);
    print(amountOfPatients);
    cout << "Данные о следующих пациентах будут добавлены в базу данных:\n";
    add_elements_in_beginning(amountOfPatients);
    cout << "Содержимое базы данных после внесенных изменений:\n";
    print(amountOfPatients);
    system("pause");
    return 0;
}