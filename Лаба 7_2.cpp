#include <iostream>

using namespace std;
int min (int k, int firstNum, ...);
double min (int k, double firstNum, ...);
int main()
{
	setlocale(LC_ALL, "Russian");
	cout<<"Программа ищет минимальное число в заданной последовательности"<<endl;
	cout<<"Минимальное из чисел 5, 6, 7, 3, 1: "<<min(5, 5, 6, 7, 3, 1)<<endl;
	cout<<"Минимальное из чисел 1.2, 12.0, 33.71, 24.15, 44.0, 48.01, 34.16, 1.1, 0.15, 8.13: "<<
	min(10, 1.2, 12.0, 33.71, 24.15, 44.0, 48.01, 34.16, 1.1, 0.15, 8.13)<<endl;
	cout<<"Минимальное из чисел 121, 54, 34, 666, 777, 13, 7, 51, 98, 100, 67, 6: "<<
	min(12, 121, 54, 34, 666, 777, 13, 7, 51, 98, 100, 67, 6)<<endl;
	cout<<"Минимальное из чисел 12.0, 115.1, 3.03, 55.5, 77.41, 16.8: "<<
	min(6, 12.0, 115.1, 3.03, 55.5, 77.41, 16.8)<<endl;
	cout<<"Минимальное из чисел 999, 121, 503, 444, 871, 123, 321, 120: "<<
	min(8, 999, 121, 503, 444, 871, 123, 321, 120)<<endl;
	getchar();
	return 0;
}
int min (int k, int firstNum, ...) {
	int *minNumber = &firstNum;
	int *number = minNumber;
	for ( ; k > 1; k--) {
		number += 2;
		if (*number <= *minNumber)
			*minNumber = *number;
	}
	return *minNumber;
}
double min (int k, double firstNum, ...) {
	double *minNumber = &firstNum;
	double *number = minNumber;
	for ( ; k > 1; k--) {
		number += 1;
		if (*number <= *minNumber)
			*minNumber = *number;
	}
	return *minNumber;
}
