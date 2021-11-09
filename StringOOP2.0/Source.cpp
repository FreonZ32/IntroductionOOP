#include<iostream>
#include<string.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
	int size;
	char* str;
public:
	const char* get_str()const
	{	return str;	}
	const int get_size()const
	{	return size;}

	//Constructor
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//Methods
	void print()const
	{
		cout << "Size = " << size << endl;
		cout << "Str = " << str << endl;
	}
	//Operator
	String& operator=(const String& other)
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
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTOR_CHECK

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

	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;
}