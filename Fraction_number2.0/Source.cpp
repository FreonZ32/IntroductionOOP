#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{ return integer; }
	int get_numerator()const
	{ return numerator; }
	int get_denominator()const
	{ return denominator; }
	void set_integer(int integer)
	{ this->integer = integer;}
	void set_numerator(int numerator)
	{ this->numerator = numerator;}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator; 
	}

	//Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 0;
		cout << "SingleConstructor\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "DoubleConstructor\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "FullConstructor\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment\t" << this << endl;
		return *this;
	}
	
	//Methods
	void print()
	{	
		/*if (integer != 0)
			if (numerator == denominator) cout << integer << endl;
			else cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
		else cout << numerator << "/" << denominator << endl;*/
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
	void to_improper()	//Переделывает в простую дробь.
	{
		numerator += integer * numerator;
		integer = 0;
	}
	void to_proper()	//Переделывает в дробь с целым числом.
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void reduce()
	{
		/*int x = numerator;
		int y = denominator;*/
		/*int more, less;
		if(numerator>denominator)
		while (x != y)
			if (x > y)x -= y;
			else y -= y;
		numerator /= y;
		denominator /= y;
		integer = 0;*/
	}
};	

//#define CONSTRUCTOR_CHECK

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef CONSTRUCTOR_CHECK
	Fraction A;
	A.print();
	Fraction B = 5;
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTOR_CHECK

	Fraction A(90,30);
	A.reduce();
	A.print();
}