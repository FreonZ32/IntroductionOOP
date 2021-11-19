#include<iostream>
#include"String.h"
using std::cout;
using std::cin;
using std::endl;

//#define CONSTRUCTOR_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTOR_CHECK
	String Str;
	Str.print();

	String str1 = "Hello";
	str1.print();
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;

	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // CONSTRUCTOR_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl << endl;
	str1 += str2;
	cout << str1 << endl << endl;
#endif // OPERATOR_PLUS_CHECK

	String str1(25);	//Default constructor
	str1.print();

	String str2 = "Hello";	//Single Argument
	cout << str2 << endl;
	str2.print();

	String str3("World");	//Single Argument
	cout << str3 << endl;

	String str4();	//ќбъ€вление функции str4, котора€ ничего не принимает и возвращает объект класса String;

	String str5{};	//явный вызов конструктора по умолчанию.
	cout << str5 << endl;

	String str6{ "Single arg constructor" };
	cout << str6 << endl;

	String str7 = str6;
	cout << str7 << endl;

	cout << str2 + " " + str3 << endl;
} 