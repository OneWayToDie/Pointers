#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);


void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]; //объявление динамического массива

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	//1) Создаём буферный массив нужного размера:

	int* buffer = new int[n + 1];

	//2) Копируем все элементы из исходного массива в буфферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3)

	arr[n] = value;
	n++;
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; // через арифметику указателей и оператор разыменования
	}
}
void Print(int arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; // через оператор индексирования
	}
	cout << endl;
}