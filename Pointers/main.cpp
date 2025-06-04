#include<iostream>
using namespace std;

//#define POINTER_BASICS

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // Вывод переменной 'a' на экран;
	cout << &a << endl;	//взятие адреса переменной 'a' прямо при выводе;
	cout << pa << endl;	// Вывод адреса переменной 'a', хранящегося в указателе 'pa';
	cout << *pa << endl;// разыменование указателя 'pa', и вывод на экран значения по адресу;

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

	// int - 'int';
	// int* - указатель на 'int';
	//double - 'double';
	//double* - указатель на 'double';
#endif

	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
