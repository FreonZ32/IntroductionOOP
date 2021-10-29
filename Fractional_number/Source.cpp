#include<iostream>
#include<math.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


#define DEBUG

class Fraction
{
	//int integral;		//???
	//bool positive;	//???
	int numerator;
	unsigned int denominator;
	bool decimal;
public:
																		//get/set
	int get_num()const { return numerator; }
	void set_num(int numerator) { this->numerator = numerator; }
	int get_den()const { return denominator; }
	void set_den(unsigned int denominator) { this->denominator = denominator; }
	bool get_dec()const { return decimal; }
	void set_dec(bool decimal) { this->decimal = decimal; }
																		//Constructors
	Fraction()
	{	
		numerator = 0;
		denominator = 0;
		decimal = false;
#ifdef DEBUG 
		cout << "Default costr.\t" << this << endl;
#endif // DEBUG 
	}
	Fraction(int numerator, unsigned int denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		decimal = false;
		for (unsigned int i = 10; i < 1000000000; i*=10)
		{
			if (denominator == i) 
			{ decimal = true; break; }
		}
#ifdef DEBUG 
		cout << "Costr.\t" << this << endl;
#endif // DEBUG 
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->decimal = other.decimal;
#ifdef DEBUG
		cout << "Copy constructor:\t" << this << endl;
#endif // DEBUG

	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor.\t" << this << endl;
#endif // DEBUG
	}
																		//Methods
	void print()
	{
		cout << numerator << " / " << denominator << endl;
	}
																		//Operators
	Fraction& operator=(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->decimal = other.decimal;
#ifdef DEBUG
		cout << "= Operator.\t" << this << endl;
#endif // DEBUG
	}
	Fraction& operator++()
	{ this->numerator += denominator; return *this; }
	Fraction operator++(int)
	{ Fraction old; this->numerator += denominator; return old; }
	
};
								
																		//Cin/Cout
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_dec()) 
	{
		double x = obj.get_num();
		double y = obj.get_den();
		double dec = x/y;
		os << dec << endl;
	}
	else if(obj.get_den() == 1)os << obj.get_num();
	else os << obj.get_num() << " / " << obj.get_den();
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	int num; unsigned int den;
	is >> num >> den;
	obj.set_num(num);
	obj.set_den(den);
	obj.set_dec(false);
	for (unsigned int i = 10; i < 1000000000; i *= 10)
	{
		if (den == i)
		{ obj.set_dec(true); break;}
	}
	return is;
}

void main()
{
	setlocale(LC_ALL, "rus");
	Fraction A(-21, 100000);
	cout << A << endl;
	cout << "¬ведите дробь в формате \"числитель_знаменатель\": "; cin >> A;
	cout << A << endl;
	A++;
	cout << A << endl;
	++A;
	cout << A << endl;
}