#pragma warning(disable : 4996)
#include<iostream>
#include<math.h>
using namespace std;

class Fraction
{
	int integer;		//????? ?????
	int numerator;		//?????????
	int denominator;	//???????????
public:
	int get_integer()const
	{ return integer; }
	int get_numerator()const
	{ return numerator; }
	int get_denominator()const
	{ return denominator; }
	void set_integer(int integer)
	{ this->integer = integer; }
	void set_numerator(int numerator)
	{ this->numerator = numerator; }
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//					Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:" << this << endl;
	}
	/*Fraction(double obj)
	{
		int d = 0;
		double n, i;
		n = modf(obj,&i);
		integer = i;
		for (n,d;; n*=10,d++)
		{if (int(n) - n == 0)break;}
		numerator = n;
		denominator = pow(10,d);
		reduce();
		cout << "From double to Fraction Constructor:" << this << endl;
	}*/
	Fraction(double decimal)
	{
		decimal += 1e-11;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "From double to Fraction Constructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	//			Type cast operator
	explicit operator int()const
	{ return integer;}
	explicit operator double()const
	{ return ((integer*denominator) + numerator)/denominator;}

	//				Methods:
	Fraction& to_proper()
	{	//????????? ????? ? ?????????? - ???????? ????? ?????:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{	//????????? ????? ? ???????????? - ??????????? ????? ????? ? ?????????:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_invert()
	{	//?????????????? ?????
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}
	Fraction& reduce()
	{	//????????? ?????
		int a, b;
		if (numerator == 0)
		{
			denominator = 1;
			return *this;
		}
		if(numerator>denominator){a = numerator; b = denominator;}
		else b = numerator; a = denominator;
			while (b)
			{
				a %= b;
				swap(a, b);
			}
			numerator /= a;
			denominator /= a;
			if (denominator == 1) 
			{	integer += numerator;numerator = 0;	}
			return *this;
	}
	void print()
	{
		if (integer)cout << integer;	//???? ???? ????? ?????, ??????? ?? ?? ?????
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
	}
	int NOD(const Fraction& other)	//????????? ???
	{
		int Lden = this->denominator; int Rden = other.get_denominator();
		while (Lden != Rden)
		{
			if (Lden > Rden)Lden -= Rden;
			else Rden -= Lden;
		}
		return Lden;
	}
	int NOK(const Fraction& other)	//????????? ???
	{
		return denominator * other.get_denominator() / NOD(other);
	}


	//			Operator
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction other)
	{
		*this = *this * other;
		return *this;
	}
	Fraction& operator/=(const Fraction other)
	{
		*this = *this / other;
		return *this;
	}
	Fraction& operator+=(const Fraction other)
	{
		*this = *this + other;
		return *this;
	}
	Fraction& operator-=(const Fraction other)
	{
		*this = *this - other;
		return *this;
	}
	Fraction& operator++()
	{ integer++;return *this; }
	Fraction& operator++(int)
	{ 
		Fraction old = *this;
		this->integer++;return old; 
	}
	Fraction& operator--()
	{
		if ((integer - 1) < 0)numerator -= denominator;
		else integer--; return *this;
	}
	Fraction& operator--(int)
	{
		Fraction old = *this;
		if ((this->integer - 1) < 0)this->numerator -= this->denominator;
		else this->integer--; return old;
	}

	//				Friend_functions
	friend Fraction operator*(Fraction, Fraction);
	friend Fraction operator/(Fraction, Fraction);
	friend Fraction operator+(Fraction, Fraction);
	friend Fraction operator-(Fraction, Fraction);
};

//				Operator
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction((left.get_numerator() * right.get_numerator()), (left.get_denominator() * right.get_denominator())).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.to_invert();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int n = left.NOK(right);
	return Fraction(
	((left.get_numerator() * (n/left.get_denominator())) + (right.get_numerator() * (n/right.get_denominator()))), n
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int n = left.NOK(right);
	return Fraction(
		((left.get_numerator() * (n / left.get_denominator())) - (right.get_numerator() * (n / right.get_denominator()))), n
	).to_proper();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int n = left.NOK(right);
	return ((left.get_numerator() * (n / left.get_denominator())) == (right.get_numerator() * (n / right.get_denominator())));
}
bool operator!=(Fraction left, Fraction right)
{ return !(left == right); }
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int n = left.NOK(right);
	return ((left.get_numerator() * (n / left.get_denominator())) > (right.get_numerator() * (n / right.get_denominator())));
}
bool operator<(Fraction left, Fraction right)
{ return !(left > right); }
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int n = left.NOK(right);
	return ((left.get_numerator() * (n / left.get_denominator())) >= (right.get_numerator() * (n / right.get_denominator())));
}
bool operator<=(Fraction left, Fraction right)
{ return !(left >= right); }


//				Cin Cout
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	//int n = 31; int c = 0;
	//bool FracType = false;	//false - ???????/true - ? ????? ??????
	//char str[31]{};
	//obj.set_integer(0); obj.set_numerator(0), obj.set_denominator(1);
	//is.getline(str, n);
	//for (int i = 0; str[i]; i++) if (isblank(str[i])) { FracType = true; break; }
	//if (FracType)
	//{
	//	while (isdigit(str[c]))
	//	{
	//		obj.set_integer(obj.get_integer() * 10);
	//		obj.set_integer((int(str[c++]) - 48) + obj.get_integer());
	//	}c += 2;
	//}
	//while (isdigit(str[c]))
	//{
	//	obj.set_numerator(obj.get_numerator() * 10);
	//	obj.set_numerator((int(str[c++]) - 48) + obj.get_numerator());
	//}c++;
	//while (isdigit(str[c]))
	//{
	//	if (obj.get_denominator() != 1)obj.set_denominator(obj.get_denominator() * 10);
	//	if (obj.get_denominator() != 1)obj.set_denominator((int(str[c++]) - 48) + obj.get_denominator());
	//	else obj.set_denominator(int(str[c++]) - 48);
	//}
	//return is;

	const int SIZE = 50;
	char buffer[SIZE] = {};
	char delimiters[] = "()/ ";
	//		5
	//		1/2
	//		5(1/2)
	//		5 1/2
	//		5.5
	//is >> buffer;
	is.getline(buffer, SIZE);
	char* value[3] = {};
	int n = 0;
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		value[n++] = pch;
	}
	switch (n)
	{
	case 1: obj.set_integer(atoi(value[0])); break;
	case 2:
		obj.set_numerator(atoi(value[0]));
		obj.set_denominator(atoi(value[1]));
		break;
	case 3:
		obj.set_integer(atoi(value[0]));
		obj.set_numerator(atoi(value[1]));
		obj.set_denominator(atoi(value[2]));
	}
	return is;
}


//#define CONSTRUCTORS_CHECK
//#define OSTREAM_CHECK
//#define IOSTREAM_OPERATOR_CHECK
//#define TYPE_CONVERSION_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define CONVERSION_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();
	Fraction B = 5;	//Single-argument constructor (??????????? ? ????? ??????????).
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef OSTREAM_CHECK
	Fraction A(46, 48);
	A.to_proper();
	cout << A << endl;
	A.to_improper();
	cout << A << endl;
	A.reduce();
	cout << A << endl;
#endif // OSTREAM_CHECK

#ifdef IOSTREAM_OPERATOR_CHECK
	Fraction A(4, 2, 3);
	//Fraction B(15, 5);
	//cout << A << endl;
	//cout << B << endl;
	////Fraction C = A + B;
	////Fraction C = A * B;
	////cout << C << endl;
	//if (A < B)cout << "?????????" << endl;
	//else cout << "DDDDDDDDDDDDDDDDD" << endl;
	//cout << A++ << endl;
	//A.reduce();
	//cout << A << endl;
	///*cout << "??????? ????? ? ??????? \"?????_?????(??????)(?????????/???????????)\" ???? \"?????????/???????????\", ???? \"?????_?????(??????)\": " << endl;
	//cin >> A;
	//cout << A << endl;*/
	//A = 2.752;
	//cout << A << endl;  
#endif // IOSTREAM_OPERATOR_CHECK

#ifdef TYPE_CONVERSION_BASICS
	int a = 2;	//No conversions
	double b = 3;	//Conversion from int(4) to double(8)
	int c = b;	//Conversion from double(8) to int(4) without data loss
	int d = 4.7;	//Conversion from double(8) to int(4) with data loss
	cout << d << endl;
#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	double a = 2;	//From int to double
	Fraction A = (Fraction)5;	//From int to Fraction
	cout << A << endl;
	Fraction B;
	B = Fraction(8);	//explicit ??????????? ????? ???????? ?????? ???
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	/*Fraction A(2, 3, 4);
int a = int(A);
cout << A << endl;
cout << a << endl;
double b = double(A);
cout << b << endl;*/
	/*Fraction A = 2.76;
	cout << A << endl;
	Fraction C(2, 76, 100);
	cout << C << endl;*/
	Fraction D(1, 3);
	cout << D*3 << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

}