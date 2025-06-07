#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Chetnoe_nechetnoe(int arr[], const int n, int cntChetnoe, int cntNeChetnoe);
void Even(int arr[], int even[], const int n);
void Odd(int arr[], int odd[], const int n);
void Print(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	int cntChetnoe = 0;
	int cntNeChetnoe = 0;
	int* even = new int[n];
	int* odd = new int[n];

	FillRand(arr, n);
	Chetnoe_nechetnoe(arr, n, cntChetnoe, cntNeChetnoe);
	Even(arr, even, n);
	Odd(arr, odd, n);
	cout << "Массив arr - ";
	Print(arr, n);

	delete[] even;
	delete[] odd;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}
void Chetnoe_nechetnoe(int arr[], const int n, int cntChetnoe, int cntNeChetnoe)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			cntChetnoe++;
		}
		if (arr[i] % 2 != 0)
		{
			cntNeChetnoe++;
		}
	}
	cout << "количество чётных чисел в массиве - " << cntChetnoe << endl;
	cout << "количество нечётных чисел в массиве - " << cntNeChetnoe << endl;
}
void Even(int arr[], int even[], const int n)
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
	
}
void Odd(int arr[], int odd[], const int n)
{
	cout << endl;
	cout << "Массив odd - ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			odd[i] = arr[i];
			cout << odd[i] << " ";
		}
	}
	cout << endl;
	
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

