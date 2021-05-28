#include "Employee.h"
using namespace std;
int main() {
	setlocale(LC_ALL, "");
	Employee firstEmployee;
	firstEmployee.Print();
	Employee secondEmployee("Елизаров Сергей Викторович", "Финансовый директор", 350000);
	secondEmployee.Print();
	Employee thirdEmployee = secondEmployee;
	thirdEmployee.Print();
	cout << "Демонстрация работы модификаторов и селекторов:" << endl;
	Employee fourthEmployee;
	fourthEmployee.set_fullname("Павликов Антон Степанович");
	fourthEmployee.set_position("Главный бухгалтер");
	fourthEmployee.set_salary(60000);
	cout << "ФИО: " << fourthEmployee.get_fullname() << endl;
	cout << "Должность: " << fourthEmployee.get_position() << endl;
	cout << "Зарплата: " << fourthEmployee.get_salary() << endl;
	system("pause");
	return 0;
}
