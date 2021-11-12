#include<iostream>
#include<string.h>
using namespace std;

class Matrix
{
	int rows;
	int cols;
	int** arr;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	//Constructor
	Matrix(int rows = 2, int cols = 2)
	{
		this->rows = rows;
		this->cols = cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols] {};
		}
		cout << "Constructor:\t" << this << endl;
	}
	Matrix(int n) :Matrix(1,n)
	{

	}
	Matrix(const Matrix& other):Matrix(other.rows, other.cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = other.arr[i][j];
			}
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
		rows = 0;
		cols = 0;
		cout << "Destructor:\t" << this << endl;
	}

	//Operators
	const int* operator[](int i)const
	{
		return arr[i];
	}
	int* operator[](int i)
	{
		return arr[i];
	}
	Matrix& operator=(const Matrix& other)
	{
		this->~Matrix();
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			this->arr[i] = new int[cols] {};
			memcpy(this->arr[i], other.arr[i], cols * sizeof(int));
		}
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}

	//Methods
	void print()const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "rus");

	Matrix A(3,4);
	for (int i = 0; i < A.get_rows(); i++)
	{
		for (int j = 0; j < A.get_cols(); j++)
		{
			A[i][j] = rand() % 100;
		}
	}
	A.print();

	Matrix B;
	B = A;
	B.print();
}