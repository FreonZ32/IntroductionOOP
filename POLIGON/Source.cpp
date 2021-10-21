#include <iostream>
#include <math.h>
using namespace std;

double distance(class Point A, class Point B);

class Point
{

	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(double x, double y)
	{
		return sqrt((this->x * x) + (this->y * y));
	}

};
//#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A;//объявление переменной А типа Point
//объявление экземпляра А структуры Point
//объявление, создание объекта А структуры Point   
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STR

	Point A;
	A.set_x(5);
	A.set_y(5);
	cout << "Координаты точки А: " << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки А до начала координат: " << A.distance(A.get_x(), A.get_y()) << endl;

	Point B;
	B.set_x(6);
	B.set_y(4);
	cout << "Координаты точки В: " << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Координаты точки В: " << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние от точки В до начала координат: " << B.distance(B.get_x(), B.get_y()) << endl;
	cout << "Расстояние между двумя точками А и В: " << distance(A, B) << endl;


}

double distance(class Point A, class Point B)
{
	double x, y;
	return abs(A.distance(A.get_x(), A.get_y()) - B.distance(B.get_x(), B.get_y()));
}