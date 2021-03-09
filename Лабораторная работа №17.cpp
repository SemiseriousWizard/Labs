#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;
struct Person {
	string FullName;
	int PhoneNumber;
	string Address;
	Person* Next;
};
struct ArrayOfLists {	//для предотвращения коллизий используется метод цепочек. Поэтому необходимо создать массив списков
	Person* Data;
};
//counters
int index;	//для вывода порядкового номера элемента в таблице
int amountOfCollisionsInHashtableForAddresses;
int amountOfCollisionsInHashtableForPhoneNumbers;
//
ArrayOfLists* hash_table_for_addresses; 
ArrayOfLists* hash_table_for_phonenumbers;
const int p = 2; //коэффициент для умножения кодов символов в хеш - функции,
					//которая принимает адрес
int hash_table_size = 0;
//flags
bool isExit = false;
bool isElementDeleted;
//
int hash_function(string key) {
	int key_length = key.length();
	int hash_code = 0;
	for (int i = 0; i < key_length; i++) {
		hash_code += (int)(key[i]) *(int)(pow(p, i));
	}
	return hash_code % hash_table_size;
}
int hash_function(int key) {	//хеш-функция для преобразования номера телефона
	return key % hash_table_size;
}
void provide_correct_input(int &number) {
	do {
		cin >> number;
		if (number < 1)
			cout << "Число должно быть положительным" << endl;
	} while (number < 1);
}
void clear_hash_table(ArrayOfLists*& hash_table) {
	for (int i = 0; i < hash_table_size; i++) {
		hash_table[i].Data = NULL;
	}
}
void print_list(Person* list) {
	while (list != NULL) {
		cout << index++ << ":" << endl;
		cout << list->FullName << "\t\t";
		cout << list->PhoneNumber << "\t\t\t";
		cout << list->Address << endl;
		cout << endl;
		list = list->Next;
	}
}
void print_hash_table(ArrayOfLists* &hash_table) {
	index = 1;
	cout << "ФИО" << "\t\t\t" << "Номер телефона" << "\t\t" << "Адрес" << endl;
	for (int i = 0; i < hash_table_size; i++) 
		print_list(hash_table[i].Data);
	index = 1;
}
void add_element_in_list(Person* &first, Person* ptr_on_new_person, bool fill_hash_table_addresses) {	
	if (first == NULL) {
		first = new Person;
		first->FullName = ptr_on_new_person->FullName;
		first->PhoneNumber = ptr_on_new_person->PhoneNumber;
		first->Address = ptr_on_new_person->Address;
		first->Next = NULL;
	}
	else {
		Person* save_first = first;
		while (first->Next != NULL)
			first = first->Next;
		if (fill_hash_table_addresses)	//происходит коллизия в хеш-таблице, в которой ключом является строка
			amountOfCollisionsInHashtableForAddresses++;
		else
			amountOfCollisionsInHashtableForPhoneNumbers++; //происходит коллизия в хеш-таблице, в которой ключом является число
		Person* ptr_on_new_element = new Person;
		ptr_on_new_element->FullName = ptr_on_new_person->FullName;
		ptr_on_new_element->PhoneNumber = ptr_on_new_person->PhoneNumber;
		ptr_on_new_element->Address = ptr_on_new_person->Address;
		ptr_on_new_element->Next = NULL;
		first->Next = ptr_on_new_element;
		first = save_first;
	}
}
void add_person_in_hashtables(string fullname, int phonenumber, string address) {
	Person* ptr_on_new_person = new Person;
	ptr_on_new_person->FullName = fullname;
	ptr_on_new_person->PhoneNumber = phonenumber;
	ptr_on_new_person->Address = address;
	int index = hash_function(address);
	add_element_in_list(hash_table_for_addresses[index].Data, ptr_on_new_person, true);
	index = hash_function(phonenumber);
	add_element_in_list(hash_table_for_phonenumbers[index].Data, ptr_on_new_person, false);
}
void input_data_for_hash_table(string& fullname, int& phonenumber, string& address) {
	cout << "Введите ФИО: ";
	cin >> fullname;
	cout << "Введите номер телефона: ";
	cin >> phonenumber;
	cout << "Введите адрес: ";
	cin >> address;
}
string create_random_string() {
	string result = "";
	char random_symbol;
	int random_symbol_code;
	for (int j = 0; j < 10; j++) {
		random_symbol_code = rand() % 26 + 97;
		random_symbol = (char)random_symbol_code;
		result += random_symbol;
	}
	return result;
}
void create_hash_table() {
	string data_fullname, data_address;
	int data_phonenumber = 0;
	for (int i = 0; i < hash_table_size; i++) {
		data_fullname = "";
		data_address = "";
		data_phonenumber = 2000 + rand() % 999;
		data_fullname = create_random_string();
		data_address = create_random_string();
		add_person_in_hashtables(data_fullname, data_phonenumber, data_address);
	}
}
void pop(Person* &first) {
	if (first != NULL) {
		Person* ptr_on_deleted_element = new Person;
		ptr_on_deleted_element = first;
		first = first->Next;
		delete ptr_on_deleted_element;
	}
}
void delete_elements_from_hash_table(string key) {	
	int index_for_string_key = hash_function(key);
	if (hash_table_for_addresses[index_for_string_key].Data == NULL)
		return;
	else {
		bool isContinue = true;
		Person* ptr_on_first_element = new Person;
		ptr_on_first_element = NULL; //если все элементы будут удалены
		while (isContinue && (hash_table_for_addresses[index_for_string_key].Data != NULL))
			if (hash_table_for_addresses[index_for_string_key].Data->Address == key) {
				pop(hash_table_for_addresses[index_for_string_key].Data);
				if (!isElementDeleted)
					isElementDeleted = true;
			}
			else
				isContinue = false;
		if (hash_table_for_addresses[index_for_string_key].Data != NULL) {
			ptr_on_first_element = hash_table_for_addresses[index_for_string_key].Data;
			while (hash_table_for_addresses[index_for_string_key].Data->Next != NULL) {
				if (hash_table_for_addresses[index_for_string_key].Data->Next->Address != key)
					hash_table_for_addresses[index_for_string_key].Data = hash_table_for_addresses[index_for_string_key].Data->Next;
				else {
					Person* save_link = hash_table_for_addresses[index_for_string_key].Data;
					isContinue = true;
					while (isContinue && (hash_table_for_addresses[index_for_string_key].Data->Next != NULL))
						if (hash_table_for_addresses[index_for_string_key].Data->Next->Address == key) {
							pop(hash_table_for_addresses[index_for_string_key].Data->Next);
							if (!isElementDeleted)
								isElementDeleted = true;
						}
						else
							isContinue = false;
					save_link->Next = hash_table_for_addresses[index_for_string_key].Data->Next;
				}
			}
		}
		hash_table_for_addresses[index_for_string_key].Data = ptr_on_first_element;
	}
}
void delete_elements_from_hash_table(int key) {
	int index_for_int_key = hash_function(key);
	if (hash_table_for_phonenumbers[index_for_int_key].Data == NULL)
		return;
	else {
		bool isContinue = true;
		Person* ptr_on_first_element = new Person;
		ptr_on_first_element = NULL; //если все элементы будут удалены
		while (isContinue && (hash_table_for_phonenumbers[index_for_int_key].Data != NULL))
			if (hash_table_for_phonenumbers[index_for_int_key].Data->PhoneNumber == key) {
				pop(hash_table_for_phonenumbers[index_for_int_key].Data);
				if (!isElementDeleted)
					isElementDeleted = true;
			}
			else
				isContinue = false;
		if (hash_table_for_phonenumbers[index_for_int_key].Data != NULL) {
			ptr_on_first_element = hash_table_for_phonenumbers[index_for_int_key].Data;
			while (hash_table_for_phonenumbers[index_for_int_key].Data->Next != NULL) {
				if (hash_table_for_phonenumbers[index_for_int_key].Data->Next->PhoneNumber != key)
					hash_table_for_phonenumbers[index_for_int_key].Data = hash_table_for_phonenumbers[index_for_int_key].Data->Next;
				else {
					Person* save_link = hash_table_for_phonenumbers[index_for_int_key].Data;
					isContinue = true;
					while (isContinue && (hash_table_for_phonenumbers[index_for_int_key].Data->Next != NULL))
						if (hash_table_for_phonenumbers[index_for_int_key].Data->Next->PhoneNumber == key) {
							pop(hash_table_for_phonenumbers[index_for_int_key].Data->Next);
							if (!isElementDeleted)
								isElementDeleted = true;
						}
						else
							isContinue = false;
					save_link->Next = hash_table_for_phonenumbers[index_for_int_key].Data->Next;
				}
			}
		}
		hash_table_for_phonenumbers[index_for_int_key].Data = ptr_on_first_element;
	}
}
void input_key() {
	cout << "Выберите способ поиска:" << endl;
	cout << "1) По адресу\n";
	cout << "2) По номеру телефона\n";
	int searchOption = 0, searchPhoneNumber = 0;
	string searchAddress = "";
	cin >> searchOption;
	switch (searchOption)
	{
	case 1:
		cout << "Введите адрес: ";
		cin >> searchAddress;
		delete_elements_from_hash_table(searchAddress);
		if (isElementDeleted)
			cout << "Элемент найден. Элемент удален" << endl;
		else
			cout << "Искомый элемент отсутствует в хеш-таблице" << endl;
		cout << "Содержимое таблицы:" << endl;
		print_hash_table(hash_table_for_addresses);
		break;
	case 2:
		cout << "Введите номер телефона: ";
		cin >> searchPhoneNumber;
		delete_elements_from_hash_table(searchPhoneNumber);
		if (isElementDeleted)
			cout << "Элемент найден. Элемент удален" << endl;
		else
			cout << "Искомый элемент отсутствует в хеш-таблице" << endl;
		cout << "Содержимое таблицы:" << endl;
		print_hash_table(hash_table_for_phonenumbers);
		break;
	}
}	
void print_both_hash_tables() {
	cout << "Содержимое хеш-таблицы, сформированной по адресам:\n";
	print_hash_table(hash_table_for_addresses);
	cout << "Количество коллизий: " << amountOfCollisionsInHashtableForAddresses << endl;
	cout << endl;
	cout << "Содержимое хеш-таблицы, сформированной по номерам телефонов:\n";
	print_hash_table(hash_table_for_phonenumbers);
	cout << "Количество коллизий: " << amountOfCollisionsInHashtableForPhoneNumbers << endl;
}
void show_menu() {
	system("cls");
	//инициализация переменных, используемых повторно (при продолжении работы с программой)
	amountOfCollisionsInHashtableForAddresses = 0;
	amountOfCollisionsInHashtableForPhoneNumbers = 0;
	isElementDeleted = false;
	//
	string data_fullname, data_address;
	int data_phonenumber;
	int creatingOption = 0;
	int option = 0;
	cout << "Введите дальнейшие действия:\n";
	cout << "0) Выйти" << endl;
	cout << "1) Создать хеш-таблицу" << endl;
	cin >> option;
	switch (option)
	{
	case 0:
		isExit = true;
		break;
	case 1:
		cout << "Введите размер хеш-таблицы: ";
		provide_correct_input(hash_table_size);
		hash_table_for_addresses = new ArrayOfLists[hash_table_size];
		hash_table_for_phonenumbers = new ArrayOfLists[hash_table_size];
		clear_hash_table(hash_table_for_addresses);
		clear_hash_table(hash_table_for_phonenumbers);
		cout << "Введите способ создания хеш-таблицы:\n";
		cout << "1) Вручную\n";
		cout << "2) С помощью генератора случайных чисел\n";
		cout << ">";
		cin >> creatingOption;
		switch (creatingOption)
		{
		case 1:
			for (int i = 0; i < hash_table_size; i++) {
				data_fullname = "";
				data_address = "";
				data_phonenumber = 0;
				cout << i + 1 << ":" << endl;
				input_data_for_hash_table(data_fullname, data_phonenumber, data_address);
				add_person_in_hashtables(data_fullname, data_phonenumber, data_address);
			}
			break;
		case 2:
			create_hash_table();
			break;
		}
		print_both_hash_tables();
		input_key();
		system("pause");
		break;
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(static_cast<int>(time(0)));
	while (!isExit)
		show_menu();
	system("pause");
	return 0;
}