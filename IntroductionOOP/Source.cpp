#include<iostream>
using namespace std;
using::cout;
using::cin;
using::endl;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
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
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
}