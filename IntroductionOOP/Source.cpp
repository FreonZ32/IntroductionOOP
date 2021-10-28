#include<iostream>
#include<math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

double distance(class Point& A, class Point& B);

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{return x;}
	double get_y()const
	{return y;}
	void set_x(double x)
	{this->x = x;}
	void set_y(double y)
	{this->y = y;}

	//Constructor
	Point()
	{
		x = 0;
		y = 0;
		cout << "Default constractor:\t" << this << endl;
	}
	//Point() :x(0), y(0) {}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy constructor:\t" << this << endl;
	}	
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy Assignment:\t" << this << endl;
		/*return Point((x+=other.x),(y+=other.y));*/
		return *this;
	}
	//Increment/Decrement
	Point& operator++()	//Prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)	//Suffix increment
	{
		//Point old = *this;	//��������� ������� ���� ������ �������
		//this->x++;
		//this->y++;
		return Point(this->x++,this->y++);
	}

	//Metods
	double distance(const Point& other)
	{
		double x_distance = other.x - this->x;
		double y_distance = other.y - this->y;
		double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point buffer;
	buffer.set_x(left.get_x() + right.get_x());
	buffer.set_y(left.get_y() + right.get_y());
	return buffer;
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\t" << "Y = " << obj.get_y();
	return os;
}
istream& operator>>(istream& is,Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

#define delimiter "\n-----------------------------------------\n"
//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTOR
//#define ASSIGMENT_CHECK
#define OPERATOR_OVERLOADING
//#define ARITHMETICAL_OPERATOR_CHECK

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef STRUCT_POINT
	Point A;	//���������� ���������� � ���� Point.//���������� ����������(�������) A ��������� Point.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t " << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t " << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	double x, y;
	cout << "������� ���������� �����: "; cin >> x >> y;
	Point A;
	A.set_x(x); A.set_y(y);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	cout << delimiter << endl;
	cout << "������� ���������� ������ ����� x � y: "; cin >> x >> y;

	Point B;
	B.set_x(x); B.set_y(y);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	A.print();
	cout << delimiter << endl;

	cout << "���������� ����� ������� �����: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� �����: " << distance(A, B) << endl;
#endif // DISTANCE

#ifdef CONSTRUCTOR
	Point A;	//Default constuctor
	A.print();

	Point B(2, 3);
	B.print();

	Point C = B;
	C.print();

	Point D;
	D = B;
	D.print();

	Point V(B.get_x(), 4);
	cout << V.get_x() << "\t" << V.get_y() << endl;

#endif // CONSTRUCTOR

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);	//Point(2,3) ����� ����� ������������. ����� ������� ��������� ��������� ���������� ������,
	//������� ���������� ������ � �������� ���������. � ��������� ����� ����������.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGMENT_CHECK

#ifdef ARITHMETICAL_OPERATOR_CHECK
	Point A(2, 3);
	Point B(3, 4);
	Point C = A+B;	//����� ������� �������� + ���������� �����, ��� ����� ����������� ��� ������ �����.
	C.print();
	++C;
	C.print();
#endif // #define ARITHMETICAL_OPERATOR_CHECK

	/*for (Point i(2, 3); i.get_x() < 10; i++)
	{
		i.print();
	}*/
	Point A(2, 3);
	//A.print();
	Point B = A++;
	//B.print();
	//A.print();
	cout << A << endl;
	cout << B << endl;
	cout << "������� ���������� �����: ";
	cin >> A;
	cout << A << endl;

}

double distance(class Point& A ,class Point& B)
{ return A.distance(B);}
