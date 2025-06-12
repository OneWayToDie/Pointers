#include<iostream>
using namespace std;
//#define DYNAMIC_MEMORY_1 // ctrl+shift+u - смена регистра
#define DYNAMIC_MEMORY_2
#define resheno
#define Dont_define

#ifdef Dont_define
void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
#endif

#ifdef DYNAMIC_MEMORY_1
void Print(int arr[], const int n);
int* Push_back(int arr[], int& n, const int value);
int* Push_front(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* Insert(int arr[], int& n, const int value, int position);
int* Erase(int arr[], int& n, const int value, int position);
#endif

#ifdef DYNAMIC_MEMORY_2
void Allocate(int** arr, const int rows, const int cols);
void Clear(int** arr, const int rows);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int** arr, const int rows, const int cols);
int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
int** pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
int** Insert_row(int** arr, int& rows, const int cols, int position);
int** Erase_row(int** arr, int& rows, const int cols, int position);
void Insert_cols(int** arr, const int rows, int& cols, int position);
#endif

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]; //объявление динамического массива
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = Push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	int position;
	cout << "Введите индекс числа: "; cin >> position;
	arr = Insert(arr, n, value, position);
	Print(arr, n);
	cout << "Введите индекс числа: "; cin >> position;
	arr = Erase(arr, n, value, position);
	Print(arr, n);
	delete[] arr;
#endif //DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	//1) СОЗДАЁМ МАССИВ УКАЗАТЕЛЕЙ
	int** arr = new int* [rows];

	//2) ВЫДЕЛЯЕМ ПАМЯТЬ ПОДСТРОКИ
	Allocate(arr, rows, cols);

	//3) РАБОТА-РАБОТА, ПЕРЕЙДИ НА ФЕДОТА
	cout << "Выводим наш двумерный массив: " << endl;
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

#ifdef resheno
	cout << "добавляем строку в конец двумерного динамического массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << "Добавляем столбец в конец двумерного динамического массива: " << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);
	cout << "Добавляем столбец в начало двумерного динамического массива: " << endl;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][0] = rand() % 1000;
	Print(arr, rows, cols);
	cout << "Добавляем строку в начало двумерного динамического массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << "удаляет последнюю строку: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "удаляет первую строку: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "удаляет последний столбец: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "удаляет первый столбец: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	int position;
	cout << "Введите индекс числа: "; cin >> position;
	cout << "Добавляем строку в назначенное место двумерного динамического массива: " << endl;
	arr = Insert_row(arr, rows, cols, position);
	FillRand(arr[position], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << "Введите индекс числа: "; cin >> position;
	cout << "Удаляем строку в назначенном месте двумерного динамического массива: " << endl;
	arr = Erase_row(arr, rows, cols, position);
	Print(arr, rows, cols);
	cout << "Введите индекс числа: "; cin >> position;
	cout << "Вставляем столбец в назначенное место двумерного динамического массива: " << endl;
	Insert_cols(arr, rows, cols, position);
	for (int i = 0; i < rows; i++)arr[i][position] = rand() % 1000;
	Print(arr, rows, cols);

#endif
	// УДАЛЕНИЕ СТРОК ДВУМЕРНОГО МАССИВА
	Clear(arr, rows);
	// Удаление массива указателей
	delete[] arr;
#endif
}
#ifdef Dont_define
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // через арифметику указателей и оператор разыменования
	}
}
#endif

#ifdef DYNAMIC_MEMORY_1
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
int* Insert(int arr[], int& n, const int value, int position)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	for (int i = n; i > position; i--)
	{
		buffer[i] = buffer[i - 1];
	}
	buffer[position] = value;
	n++;
	return buffer;
}
int* Erase(int arr[], int& n, const int value, int position)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n+1 ; i++)
	{
		if (i < position)
		{
			buffer[i] = arr[i];
		}
		else
		{
			buffer[i] = arr[i + 1];
		}
	}
	delete[] arr;
	return buffer;
}
#endif

#ifdef DYNAMIC_MEMORY_2
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	delete[] arr;

	buffer[rows] = new int[cols] {};

	rows++;

	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}

	delete[] arr;


	buffer[0] = new int [cols] {};
	
	rows++;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буферную строку нужного размера
		int* buffer = new int[cols + 1] {};
		//2) Копируем элементы из исходной строки в буфферуню
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}
void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1] {};

		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];

		delete[] arr[i];

		arr[i] = buffer;
	}
	cols++;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int [--cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	}
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1];

		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];

		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
int** Insert_row(int** arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	for (int i = rows; i > position; i--)
	{
		buffer[i] = buffer[i-1];
	}
	buffer[position] = new int[cols] {};

	rows++;
	return buffer;
}
int** Erase_row(int** arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows + 1; i++)
	{
		i < position ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
void Insert_cols(int** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};

		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		
		delete[] arr[position];

		arr[position] = buffer;
		
		for (int j = cols; j > position; j--)
		{
			 arr[i][j] = buffer[j];
		}
		
		arr[position] = new int[rows] {};
	}
	cols++;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
}
void Allocate(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}
#endif