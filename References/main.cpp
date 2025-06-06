#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a; // омпил€тор сам, не€вно берЄт адрес переменной СaТ, и записывает его в ссылку СraТ
	ra += 3;
	cout << a << endl;
	cout << &a << endl;
	cout << &ra << endl;

}