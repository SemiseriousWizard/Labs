#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	setlocale(LC_ALL, "Russian");
	int n = 100;
	int a[n];
	int k;
	do {
		cout<<"������� ������ ������� (�� ������ 2 � �� ������ 100): ";
		cin>>n;
	} while (n > 100 || n < 2);
	cout<<"�������� ������:"<<endl;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 150;
		cout<<i + 1<<") "<<a[i]<<endl;
	}
	do {
		cout<<"������� ���������� ������� ������ ��� �������� (������ 0): ";
		cin>>k;
	} while (k < 1);
	int temp;
	for (int i = 0; i <= n - 1; i++) {
		a[i] = a[i + 1];
	}
	n--;
	for (int i = 1; i <= k; i++) {
		temp = a[n-1];
		for (int j = n - 1; j >= 1; j--) {
			a[j] = a[j - 1];
		}
		a[0] = temp;
	}
	cout<<"�������� ��������� ����� �������� ������� �������� � �������:"<<endl;
	for (int i = 0; i < n; i++) {
		cout<<i+1<<") "<<a[i]<<endl;
	}
	getchar();
	return 0;
}
