#include<iostream>
#include<math.h>
using namespace std;
using::cout;
using::cin;
using::endl;

double distance(double x, double y, double x1, double y2);

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
	static double distance(double x, double y, double x1 = 0, double y1 = 0)	//static метод не имеет доступа к this!!!!!
	{ return sqrt(pow((x1 - x), 2) + pow((y1 - y), 2));}
};

//#define STRUCT_POINT

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
	double x, y;
	cout << "Введите координаты точки: "; cin >> x >> y;
	Point A;
	A.set_x(x);A.set_y(y);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << "Расстояние до точки равно: " << A.distance(A.get_x(), A.get_y()) << endl;
	cout << "Введите координаты второй точки x и y: "; cin >> x >> y; 
	Point B;
	B.set_x(x); B.set_y(y);
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Расстояние между точками равно: " << distance(A.get_x(), A.get_y(), B.get_x(), B.get_y()) << endl;
}

double distance(double x, double y, double x1, double y1)
{
	return Point::distance(x, y, x1, y1);
}
