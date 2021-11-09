#include<iostream>
#include<string.h>
#pragma warning(disable : 4996)
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int length;
	char* str;
public:
	char* get_str()const
	{	return str;	}
	char* get_str_i(int n)const
	{	return &str[n]; }
	void set_str(char* str)
	{	strcpy(this->str, str);	}
	void set_str_i(char* value, int n)
	{	str[n] = *value;}
	int get_length()const
	{	return length;	}
	void set_length(int length)
	{	this->length = length;}
	//Constructors
	String()
	{
		this->length = 80;
		this->str = new char[80]{};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(int length)
	{
		this->length = length;
		this->str = new char[length]{};
		cout << "ConstructorWithLength:\t" << this << endl;
	}
	String(char* str)
	{
		int n = strlen(str);
		this->length = n;
		this->str = new char[n + 1];
		for (int i = 0; i<n; i++)
		{
			this->str[i] = str[i];
		}
		this->str[n] = '\0';
		cout << "ConstructorWithValue:\t" << this << endl;
	}
	String(String& other)
	{
		int n = strlen(other.get_str());
		this->length = n;
		this->str = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			this->str[i] = other.get_str()[i];
		}
		this->str[n] = '\0';
		cout << "CopyConstructor:\t" << this << endl;
	}

	~String()
	{
		delete[] this->str;
		cout << "Destructor\t" << this << endl;
	}

	//Methods
	void print()
	{
		cout << this->str;
		cout << ":print" << endl;
	}
	//Operators
	String& operator=(const char* obj)
	{
		delete[] this->str;
		int n = strlen(obj);
		this->length = n;
		this->str = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			this->str[i] = obj[i];
		}
		this->str[n] = '\0';
		return *this;
	}
	
};

String& operator+(String left, String right)
{
	int l = strlen(left.get_str());
	int r = strlen(right.get_str());
	int k = l + r;
	String buffer = new char[k]{};
	buffer.set_length(k);
	int i = 0;
	for (i; i < l; i++)
	{buffer.set_str_i(left.get_str_i(i),i);}
	for (int j = 0; j < r;j++, i++)
	{buffer.set_str_i(right.get_str_i(j), i);}
	buffer.set_str_i(left.get_str_i(l), k);
	return buffer;
}
void main()
{
	setlocale(LC_ALL, "rus");
	String A;
	A = "Hello";
	A.print();
	String B;
	B = "World";
	B.print();
	String C;
	C = A + B;
	C.print();
}

