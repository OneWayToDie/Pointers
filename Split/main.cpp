#include<iostream>
using namespace std;

void Arrays_chet_nechet(int arr[], int even[], int odd[], const int n, int cntChetnoe, int cntNeChetnoe);
void Print(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	
	const int n = 10;
	int arr[n];
	int cntChetnoe = 0;
	int cntNeChetnoe = 0;
	int* even = new int[cntChetnoe];
	int* odd = new int[cntNeChetnoe];

	Arrays_chet_nechet(arr, even, odd, n, cntChetnoe, cntNeChetnoe);
	cout << "Массив arr - ";
	Print(arr, n);
	
	delete[] even;
	delete[] odd;
}

void Arrays_chet_nechet(int arr[], int even[], int odd[], const int n, int cntChetnoe, int cntNeChetnoe)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
	cout << "Массив even - ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			cntChetnoe++;
			even[i] = arr[i];
			cout << even[i] << " ";
		}
	}
	cout << endl;
	cout << "Массив odd - ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0)
		{
			cntNeChetnoe++;
			odd[i] = arr[i];
			cout << odd[i] << " ";
		}
	}
	cout << endl;
	cout << "количество чётных чисел в массиве - " << cntChetnoe << endl;
	cout << "количество нечётных чисел в массиве - " << cntNeChetnoe << endl;
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
