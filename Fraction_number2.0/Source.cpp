#include<iostream>
#include<ctype.h>
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
	{ numerator += integer * denominator; integer = 0; }
	void to_proper()	//Переделывает в дробь с целым числом.
	{ integer += numerator / denominator; numerator %= denominator;}
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
	void to_NOK(int NOK)
	{
		if (this->denominator < NOK)
		{
			int i = this->get_numerator();
			this->set_numerator(i*(NOK / this->get_denominator()));
			this->set_denominator(NOK);
		}
	}
	void reduce()	//Сокращает дробь
	{
		to_improper();
		int y, x;
		if (numerator > denominator){ x = numerator; y = denominator; }
		else { y = numerator; x = denominator; }
		while (x != y)
		{
			if (x > y)x -= y; else y -= x;
		}
		numerator /= y;
		denominator /= y;
	}
	Fraction operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		this->integer++;
		return old;
	}

};	
//Cin Cout
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
	int n = 31; int c = 0;
	bool FracType = false;	//false - простая/true - с целым числом
	char str[31]{};
	obj.set_integer(0); obj.set_numerator(0), obj.set_denominator(1);
	is.getline(str, n);
	for (int i = 0; str[i]; i++) if (isblank(str[i])) { FracType = true; break; }
	if (FracType)
	{
		while (isdigit(str[c]))
		{
			obj.set_integer(obj.get_integer()* 10);
			obj.set_integer((int(str[c++]) - 48)+obj.get_integer());
		}c+=2;
	}
	while (isdigit(str[c]))
	{
		obj.set_numerator(obj.get_numerator() * 10);
		obj.set_numerator((int(str[c++])-48) + obj.get_numerator());
	}c++;
	while (isdigit(str[c]))
	{
		if(obj.get_denominator() != 1)obj.set_denominator(obj.get_denominator() * 10);
		if (obj.get_denominator() != 1)obj.set_denominator((int(str[c++]) - 48) + obj.get_denominator());
		else obj.set_denominator(int(str[c++]) - 48);
	}
	return is;
}

Fraction operator+(Fraction& left,Fraction& right)
{
	int n = left.NOK(right);
	left.to_NOK(n); left.to_improper(); left.print();
	right.to_NOK(n); right.to_improper(); right.print();
	Fraction buffer;
	buffer.set_numerator(left.get_numerator() + right.get_numerator());
	buffer.set_denominator(n);
	buffer.reduce();
	buffer.to_proper();
	return buffer;
}
Fraction operator-(Fraction& left, Fraction& right)
{
	int n = left.NOK(right);
	left.to_NOK(n); left.to_improper();
	right.to_NOK(n); right.to_improper();
	Fraction buffer;
	buffer.set_numerator(left.get_numerator() - right.get_numerator());
	buffer.set_denominator(n);
	buffer.reduce();
	buffer.to_proper();
	return buffer;
}
Fraction operator* (Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction buffer;
	buffer.set_numerator(left.get_numerator() * right.get_numerator());
	buffer.set_denominator(left.get_denominator() * right.get_denominator());
	buffer.reduce();
	buffer.to_proper();
	return buffer;
}


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

	Fraction A(50,10);
	Fraction B(24,10);
	Fraction C(80,10);
	/*cout << "Введите дробь в формате \"Целое_число(пробел)(числитель/знаменатель)\" либо \"числитель/знаменатель\", либо \"Целое_число(пробел)\": " << endl;
	cin >> B;
	cout << B << endl;*/
	/*cout << A.NOK(B) << endl;
	cout << A.NOD(B) << endl;*/
	A.print();
	B.print();
	C.print();
	cout << endl;
	Fraction V;
	V = A + B;
	cout << V;
	V = V - A;
	cout << V;
	V++;
	cout << V;
	++V;
	cout << V;
	V = A * B;
	cout << V;
}