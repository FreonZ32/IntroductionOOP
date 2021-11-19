#include<iostream>
#include"String.h"
////////////////////Class defenition/////////////////////////
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}

//Constructor
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)//Делигируем выделение памяти конструктору по умолчанию
{
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	cout << "MoveConstructor:\t" << this << endl;
	other.str = nullptr; other.size = 0;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//Methods
void String::print()const
{
	cout << "Size = " << size << endl;
	cout << "Str = " << str << endl;
}
//Operator
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
	}
	cout << "CopyAssigment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	other.size = 0;
	return *this;
}
String String::operator+=(const String& other)
{
	return *this = *this + other;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		/*buffer.get_str()[i] = left.get_str()[i];*/
		buffer[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		/*buffer.get_str()[i + left.get_size()-1] = right.get_str()[i];*/
		buffer[i + left.get_size() - 1] = right[i];
	}
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}