#include<iostream>
using namespace std;

class Fraction
{
	int integer;		//Целая часть
	int numerator;		//Числитель
	int denominator;	//Знаменатель
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
	Fraction(int integer)
	{
		//Single-argument constructor - Конструктор с одним параметром.
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:" << this << endl;
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

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//				Methods:
	Fraction& to_proper()
	{
		//Переводит дробь в правильную - выделяет целую часть:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//Переводит дробь в НЕправильную - интегрирует целую часть в числитель:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_invert()
	{
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}
	void reduce()
	{
		int a = numerator; int b = denominator;
			while (b)
			{
				a %= b;
				swap(a, b);
			}
			numerator /= a;
			denominator /= a;
	}
	void print()
	{
		if (integer)cout << integer;	//Если есть целая часть, выводим ее на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
	}
	int NOD(const Fraction& other)	//Вычисляет НОД
	{
		int Lden = this->denominator; int Rden = other.get_denominator();
		while (Lden != Rden)
		{
			if (Lden > Rden)Lden -= Rden;
			else Rden -= Lden;
		}
		return Lden;
	}
	int NOK(const Fraction& other)	//Вычисляет НОК
	{
		return denominator * other.get_denominator() / NOD(other);
	}
	Fraction& operator*=(const Fraction other)
	{
		Fraction buffer = (*this * other);
		return buffer;
	}
};
//				Operator
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction buffer((left.get_numerator() * right.get_numerator()),(left.get_denominator() * right.get_denominator()));
	buffer.to_proper();
	return buffer;*/
	return Fraction((left.get_numerator() * right.get_numerator()), (left.get_denominator() * right.get_denominator())).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();*/
	//return Fraction((left.get_numerator() * right.get_denominator()),(left.get_denominator() * right.get_numerator())).to_proper();
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
}

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
	os << endl;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{

	return is;
}


//#define CONSTRUCTORS_CHECK
//#define OSTREAM_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();
	Fraction B = 5;	//Single-argument constructor (Конструктор с одним параметром).
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

	Fraction A(1, 2, 3);
	Fraction B(2, 4, 5);
	cout << A << endl;
	cout << B << endl;
	Fraction C = A + B;
	//Fraction C = A * B;
	cout << C << endl;
	A *= B;
	cout << A << endl;


}