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

	//				Methods:
	Fraction& to_proper()
	{	//Переводит дробь в правильную - выделяет целую часть:
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{	//Переводит дробь в НЕправильную - интегрирует целую часть в числитель:
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_invert()
	{	//Переворачивает дробь
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}
	void reduce()
	{	//Сокращает дробь
		int a = numerator; int b = denominator;
			while (b)
			{
				a %= b;
				swap(a, b);
			}
			numerator /= a;
			denominator /= a;
			if (denominator == 1) 
			{	integer += numerator;numerator = 0;	}
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
			obj.set_integer(obj.get_integer() * 10);
			obj.set_integer((int(str[c++]) - 48) + obj.get_integer());
		}c += 2;
	}
	while (isdigit(str[c]))
	{
		obj.set_numerator(obj.get_numerator() * 10);
		obj.set_numerator((int(str[c++]) - 48) + obj.get_numerator());
	}c++;
	while (isdigit(str[c]))
	{
		if (obj.get_denominator() != 1)obj.set_denominator(obj.get_denominator() * 10);
		if (obj.get_denominator() != 1)obj.set_denominator((int(str[c++]) - 48) + obj.get_denominator());
		else obj.set_denominator(int(str[c++]) - 48);
	}
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

	Fraction A(2,45, 5);
	Fraction B(15, 5);
	cout << A << endl;
	cout << B << endl;
	//Fraction C = A + B;
	//Fraction C = A * B;
	//cout << C << endl;
	if (A < B)cout << "Воооооооо" << endl;
	else cout << "DDDDDDDDDDDDDDDDD" << endl;
	cout << A << endl;
	A.reduce();
	cout << A << endl;
	cout << "Введите дробь в формате \"Целое_число(пробел)(числитель/знаменатель)\" либо \"числитель/знаменатель\", либо \"Целое_число(пробел)\": " << endl;
	cin >> A;
	cout << A << endl;
}