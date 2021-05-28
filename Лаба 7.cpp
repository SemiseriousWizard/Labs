#include <iostream>
using namespace std;
void findGreatestCommonFactor(unsigned int &a, unsigned int &b);
int main() 
{
	setlocale (LC_ALL, "");
	unsigned int num1, num2;
	do {
		cout<<"Введите первое натуральное число: ";
		cin>>num1;
	} while (num1 < 1);
	do {
		cout<<"Введите второе натуральное число: ";
		cin>>num2;
	} while (num2 < 1);
	findGreatestCommonFactor(num1, num2);
	cout<<"Наибольший общий делитель: "<<num1;
	return 0;
}
void findGreatestCommonFactor(unsigned int &a, unsigned int &b)
{
	if (a != b) {
		if (a > b) {
			a -= b;
			findGreatestCommonFactor(a, b);
		} else {
			b -= a;
			findGreatestCommonFactor(a, b);
		}
	}
}
