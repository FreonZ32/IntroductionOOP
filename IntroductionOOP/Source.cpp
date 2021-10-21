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
	double distance(double x, double y, double x1 = 0, double y1 = 0)
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
	Point A;
	A.set_x(6);
	A.set_y(4);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	cout << A.distance(A.get_x(),A.get_y()) << endl;
	int x1, y1;
	cout << "Введите координаты второй точки x и y: "; cin >> x1 >> y1; 
	cout << distance(A.get_x(), A.get_y(), x1, y1) << endl;
}

double distance(double x, double y, double x1, double y1)
{
	Point A;
	return A.distance(x, y, x1, y1);
}
