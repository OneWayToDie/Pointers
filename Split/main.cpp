#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
int Chetnoe(int arr[], const int n);
int Nechetnoe(int arr[], const int n);
int Even(int arr[], int even[], const int n);
int Odd(int arr[], int odd[], const int n);
void Print(int arr[], const int n);
int ochistka(int odd[], int even[]);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	int cntChetnoe = Chetnoe(arr, n);
	int* even = new int[cntChetnoe];
	Even(arr, even, n);
	int cntNeChetnoe = Nechetnoe(arr, n);
	int* odd = new int[cntNeChetnoe];
	Odd(arr, odd, n);
	ochistka(odd, even);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
int Chetnoe(int arr[], const int n)
{
	int cntChetnoe = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			cntChetnoe++;
		}
	}
	cout << "количество чётных чисел в массиве - " << cntChetnoe << endl;
	return cntChetnoe;
}
int Nechetnoe(int arr[], const int n)
{
	int cntNeChetnoe = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			cntNeChetnoe++;
		}
	}
	cout << "количество нечётных чисел в массиве - " << cntNeChetnoe << endl;
	return cntNeChetnoe;
}
int Even(int arr[], int even[], const int n)
{
	cout << "Массив even - ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even[i] = arr[i];
			cout << even[i] << " ";
		}
	}
	cout << endl;
	return n;
}
int Odd(int arr[], int odd[], const int n)
{
	cout << "Массив odd - ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			odd[i] = arr[i];
			cout << odd[i] << " ";
		}
	}
	return n;
	
}
void Print(int arr[], const int n)
{
	cout << "Массив arr - ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int ochistka(int odd[], int even[])
{
	delete[] odd, even;
	return 1;
}
