#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;
float sumFractions (float num1, float num2);
string sumFractions (string num1, string num2);
void divideToNumeratorAndDenominator(string fraction, int &numerator, int &denominator);
int main()
{
	setlocale(LC_ALL, "Russian");
	float fNum1, fNum2;
	string sNum1 = "", sNum2 = "";
	string commonFraction = "";
	cout<<"Введите десятичные дроби:"<<endl;
	cout<<"1: ";
	cin>>fNum1;
	cout<<"2: ";
	cin>>fNum2;
	cout<<"Сумма двух дробей: "<<(sumFractions(fNum1, fNum2))<<endl;
	cout<<"Введите обыкновенную дробь:"<<endl;
	cout<<"1: ";
	cin>>sNum1;
	cout<<"2: ";
	cin>>sNum2;
	cout<<"Сумма двух дробей: "<<(sumFractions(sNum1, sNum2))<<endl;
	getchar();
	return 0;
}
float sumFractions (float num1, float num2) {
	return (num1 + num2);
}
string sumFractions (string num1, string num2) {
	int numerator1 = 0, denominator1 = 0;
	divideToNumeratorAndDenominator(num1, numerator1, denominator1);
	int numerator2 = 0, denominator2 = 0;
	divideToNumeratorAndDenominator(num2, numerator2, denominator2);
	int temp = 0;
	int numeratorResult, denominatorResult;
	numeratorResult = numerator1 * denominator2 + numerator2 * denominator1;
	denominatorResult = denominator1 * denominator2;
	stringstream ssNumeratorResult;
	ssNumeratorResult<<numeratorResult;
	stringstream ssDenominatorResult;
	ssDenominatorResult<<denominatorResult;
	return (ssNumeratorResult.str() + '/' + ssDenominatorResult.str());
}
void divideToNumeratorAndDenominator(string fraction, int &numerator, int &denominator) {
	int indCurrentSym = 0;
	string forNumerator = "", forDenominator = "";
	while (fraction[indCurrentSym] != '/') {
		forNumerator += fraction[indCurrentSym];
		indCurrentSym++;
	}
	indCurrentSym++; 
	while (fraction[indCurrentSym] != '\0') {
		forDenominator += fraction[indCurrentSym];
		indCurrentSym++;
	}
	numerator = atoi(forNumerator.c_str());
	denominator = atoi(forDenominator.c_str());
}
