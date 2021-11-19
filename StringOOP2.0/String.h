#pragma once
#include<iostream>
#include<string.h>
//using namespace std;
using std::cout;
using std::cin;
using std::endl;

//////////////////Class declaration/////////////////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

class String
{
	int size;
	char* str;
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	//Constructor
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();

	//Methods
	void print()const;
	//Operator
	String& operator=(const String& other);
	String& operator=(String&& other);
	String operator+=(const String& other);
	const char& operator[](int i)const;
	char& operator[](int i);
};