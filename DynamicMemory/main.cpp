#include<iostream>
using namespace std;
#define DYNAMIC_MEMORY_1 // ctrl+shift+u - смена регистра
#define DYNAMIC_MEMORY_2
//#define realization_1
#define resheno
#define Dont_define

#ifdef Dont_define
void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
#endif
#ifdef DYNAMIC_MEMORY_1
template<typename T> void Print(T arr[], const int n);
template<typename T> T* Push_back(T arr[], int& n, const T value);
template<typename T> T* Push_front(T arr[], int& n, const T value);
template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);
template<typename T> T* Insert(T arr[], int& n, const T value, const int position);
template<typename T> T* Erase(T arr[], int& n, const T value, int position);
#endif
#ifdef DYNAMIC_MEMORY_2
template<typename T> void Allocate(T** arr, const int rows, const int cols);
template<typename T> T** Allocate_pravilbnbIi(const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);
template<typename T> void Clear_pravilbnbIi(T**& arr, const int rows, const int cols = 0);
template<typename T> void FillRand(T** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T** arr, const int rows, const int cols);
template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> T** pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> T** Insert_row(T** arr, int& rows, const int cols, int position);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int position);
template<typename T> T** Erase_row(T** arr, int& rows, int cols, int position);
template<typename T> void Insert_cols(T** arr, const int rows, int& cols, int position);
template<typename T> void Erase_cols(T** arr, const int rows, int& cols, int position);
#endif

#define DATATYPE double
typedef int DataType;

void main()
{
	setlocale(LC_ALL, "");
#ifdef realization_1
	int n;
	int position;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);
	DataType value;
	cout << "Введите добавляемое значение: "; cin >> value;
	Print(arr = Push_back(arr, n, value), n);
	cout << "Введите добавляемое значение: "; cin >> value;
	Print(arr = Push_front(arr, n, value), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс числа: "; cin >> position;
	Print(arr = Insert(arr, n, value, position), n);
	cout << "Введите индекс числа: "; cin >> position;
	Print(arr = Erase(arr, n, value, position), n);
	delete[] arr;
#endif
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	//1) СОЗДАЁМ МАССИВ УКАЗАТЕЛЕЙ И ВЫДЕЛЯЕМ ПАМЯТЬ ПОДСТРОКИ
	DataType** arr = Allocate_pravilbnbIi<int>(rows, cols);

	//Copy - функция НЕ изменяет переданную в неё память, а возвращает изменненую копию полученной памяти
	//Mutable - функция изменяет полученный блок памяти;
	
	//2) РАБОТА-РАБОТА, ПЕРЕЙДИ НА ФЕДОТА
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
	cout << "Добавляем строку в назначенное место двумерного динамического массива: " << endl;
	cout << "Введите индекс добавляемой строки: "; cin >> position;
	arr = insert_row(arr, rows, cols, position);
	FillRand(arr[position], cols, 100, 1000);
	Print(arr, rows, cols);
	cout << "Удаляем строку в назначенном месте двумерного динамического массива: " << endl;
	cout << "Введите индекс удаляемой строки: "; cin >> position;
	arr = Erase_row(arr, rows, cols, position);
	Print(arr, rows, cols);
	cout << "Вставляем столбец в назначенное место двумерного динамического массива: " << endl;
	cout << "Введите индекс добавляемого столбца: "; cin >> position;
	Insert_cols(arr, rows, cols, position);
	for (int i = 0; i < rows; i++)arr[i][position] = rand() % 1000;
	Print(arr, rows, cols);
	cout << "Удаляем столбец в назначенном месте двумерного динамического массива: " << endl;
	cout << "Введите удаляемого столбца: "; cin >> position;
	Erase_cols(arr, rows, cols, position);
	Print(arr, rows, cols);
	Clear_pravilbnbIi(arr, rows, cols);
#endif
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
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // через арифметику указателей и оператор разыменования
		arr[i] /= 100;
	}
}
#endif

#ifdef DYNAMIC_MEMORY_1
template<typename T>  void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; // через оператор индексирования
	}
	cout << endl;
}
template<typename T> T* Push_back(T arr[], int& n, const T value)
{
	//1) Создаём буферный массив нужного размера:
	T* buffer = new T[n + 1];
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
template<typename T> T* Push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T* Insert(T arr[], int& n, const T value, const int position)
{
	T* buffer = new T[n + 1];
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
template<typename T> T* Erase(T arr[], int& n, const T value, int position)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n+1 ; i++)
	{
		i < position ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
#endif

#ifdef DYNAMIC_MEMORY_2
template<typename T> void FillRand(T** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
template<typename T> void Print(T** arr, const int rows, const int cols)
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
template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	buffer[0] = new T [cols] {};
	rows++;
	return buffer;
}
template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols+1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T** pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T [--cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
		return arr;
	}
}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T> T** Insert_row(T** arr, int& rows, const int cols, int position)
{
		T** buffer = new T * [rows + 1];
		for (int i = 0; i < rows; i++)buffer[i] = arr[i];
		delete[] arr;
		for (int i = rows; i > position; i--)buffer[i] = buffer[i - 1];
		buffer[position] = new T[cols]{};
		rows++;
		return buffer;
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int position)
{
	if (position < 0 || position > rows)
	{
		cout << "Error: Out of range exception" << endl;
		return arr;
	}
		T** buffer = new T * [rows + 1] {};
		for (int i = 0;i < rows; i++)buffer[i < position ? i : i + 1] = arr[i];
		delete[] arr;
		buffer[position] = new T[cols]{};
		rows++;
		return buffer;
}
template<typename T> T** Erase_row(T** arr, int& rows, int cols, int position)
{
	
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows + 1; i++)
	{
		i < position ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
template<typename T> void Insert_cols(T** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < position; j++)buffer[j] = arr[i][j];
		for (int j = position; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T> void Erase_cols(T** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols-1];
		for (int j = 0; j < cols-1; j++)
		{
			position > j ? buffer[j] = arr[i][j] : buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T> void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
}
template<typename T> void Clear_pravilbnbIi(T**& arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}
template<typename T> void Allocate(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
}
template<typename T> T** Allocate_pravilbnbIi(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
#endif