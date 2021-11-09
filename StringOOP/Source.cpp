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
	void set_str(char* str)
	{	strcpy(this->str, str);	}
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
		this->str = new char[80]{};
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
	/*String& operator=(const String& other)
	{

	}*/
};

void main()
{
	setlocale(LC_ALL, "rus");
	String A("help");
	A.print();
}

