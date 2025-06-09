#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[], int& n, const int value);
int* Push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* Insert(int arr[], int& n, const int value);

void Print_Insert(int arr[], int n);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]; //объявление динамического массива
	FillRand(arr, n);
	Print(arr, n);
	int value;
	/*cout << "Введите добавляемое значение: "; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);*/

	cout << "Введите добавляемое значение: "; cin >> value;

	arr = Insert(arr, n, value);
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
	/*cout << arr << endl;
	cout << *arr << endl;*/
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; // через оператор индексирования
	}
	cout << endl;
}
int* Push_back(int arr[], int& n, const int value)
{
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем все элементы из исходного массива в буфферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;
	//4) Подменяем адрес исходного массива, адресом нового
	arr = buffer;
	buffer = nullptr; // nullptr - это указатель на 0;
	//5) Только после всего вышенаписанного в массиве 'arr' появляется элемент, в который можно сохранить добавляемое значение:
	arr[n] = value;
	//6) После добавления элемента в массив, количество его элементов увеличивается на 1
	n++;
	return arr;
}
int* Push_front(int arr[], int& n, const int value)
{
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1];
	//2) Копируем все элементы из исходного массива в буфферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	//3) Удаляем исходный массив
	delete[] arr;

	buffer[0] = value;
	//5)
	n++;
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* Insert(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	/*arr = buffer;*/
	int position;
	cout << "Введите индекс числа: "; cin >> position;

	for (int i = n; i > position; i--)
	{
		buffer[i] = buffer[i - 1];
	}
	buffer[position] = value;

	n++;
	return buffer;
}
void Print_Insert(int arr[], int n)
{
	for (int i = 0; i < n + 1; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}