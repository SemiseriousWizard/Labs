#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int size = 100;
int sumOfElemUnderMainDiagonal(int *arr[]);
void findMaxSum (int* arr, int n);
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	setlocale(LC_ALL, "Russian");
	int n;
	int count = 0;
	int matrix[size][size];
	int arrOfSums[size];
	do {
		cout<<"Введите размер квадратной матрицы (не меньше 2 и не больше 100): ";
		cin>>size;
	} while (size < 2 || size > 100);
	do {
		cout<<"Введите количество матриц (не меньше 1 не больше 100): ";
		cin>>n;
	} while (n < 1 || n > 100);
	int *pMatrix[size];
	int sum;
	while (count < n) {
		cout<<"Матрица "<<count+1<<":"<<endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matrix[i][j] = rand() % 900 + 100;
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		for (int i = 0; i < size; i++) {
			pMatrix[i] = matrix[i];
		}
		sum = sumOfElemUnderMainDiagonal(pMatrix);
		cout<<"Сумма элементов, расположенных ниже главной диагонали: "<<sum<<endl;
		cout<<endl;
		arrOfSums[count] = sum;
		count++;
	}
	findMaxSum(arrOfSums, count);
	getchar();
	return 0;
}
int sumOfElemUnderMainDiagonal(int *arr[]) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i > j)
				sum += arr[i][j];
		}
	}
	return sum;
}
void findMaxSum (int* arr, int n) {
	int max = arr[0];
	int imax = 0;
	for (int i = 1; i <= n; i++)
		if (arr[i] > max) {
			max = arr[i];
			imax = i;
		}
	cout<<"Максимальная сумма "<<max<<" находится в матрице под номером "<<imax + 1<<endl;
}
