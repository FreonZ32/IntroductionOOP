#include<iostream>
#include<math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

double distance(class Point A, class Point B);

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
	//Operators
	void operator =(const Point& other)
	{

		this->x = other.x;
		this->y = other.y;
		cout << "Copy Assignment:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	double distance(Point other)
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

//#define STRUCT_POINT
//#define DISTANCE
#define CONSTRUCTOR

void main()
{
	setlocale(LC_ALL, "rus");
#ifdef STRUCT_POINT
	Point A;	//Объявление переменной А типа Point.//Объявление экземпляра(объекта) A структуры Point.
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t " << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t " << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	double x, y;
	cout << "Введите координаты точки: "; cin >> x >> y;
	Point A;
	A.set_x(x); A.set_y(y);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	cout << "Введите координаты второй точки x и y: "; cin >> x >> y;

	Point B;
	B.set_x(x); B.set_y(y);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	A.print();

	cout << "Расстояние между точками равно: " << A.distance(B) << endl;
	cout << "Расстояние между точками равно: " << distance(A, B) << endl;
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
#endif // CONSTRUCTOR

}

double distance(class Point A ,class Point B)
{ return A.distance(B);}
