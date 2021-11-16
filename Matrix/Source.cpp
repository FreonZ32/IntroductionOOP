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
	const int* get_arr(int i)const
	{
		return arr[i];
	}
	int* get_arr(int i)
	{
		return arr[i];
	}
	//Constructor
	Matrix(int rows = 2, int cols = 2) noexcept
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
	Matrix(int n) :Matrix(1, n){}
	Matrix(const Matrix& other)
	{
		*this = other;
		cout << "CopyConstructor:\t" << this << endl;
	}
	Matrix(Matrix&& other) noexcept
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = other.arr;
		/*for (int i = 0; i < rows; i++)		//Why not?????????
		{
			other.arr[i] = nullptr;
		}*/
		other.arr = nullptr;
		other.cols = 0;
		other.rows = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	Matrix(const Matrix& left, const Matrix& right)
	{
		int r, c;
		if (left.get_rows() > right.get_rows())r = left.get_rows();
		else r = right.get_rows();
		if (left.get_cols() > right.get_cols())c = left.get_rows();
		else c = right.get_cols();
		this->rows = r;
		this->cols = c;
		this->arr = new int* [rows] {};
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols] {};
		}
		cout << "FusionConstructor:\t" << this << endl;
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
		if (this == &other)return *this;
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
	Matrix& operator=(Matrix&& other) noexcept
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->arr = other.arr;
		other.arr = nullptr;
		other.cols = 0;
		other.rows = 0;
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
	void filling(int value = 100)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				this->arr[i][j] = rand() % value;
			}
		}
		cout << "Filling:\t" << this << endl;
	}
};

Matrix operator+(const Matrix& left, const Matrix& right)
{
	/*Matrix buffer(left,right);
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < left.get_cols(); j++)buffer[i][j] = left.get_arr(i)[j];
	}
	for (int i = 0; i < right.get_rows(); i++)
	{
		for (int j = 0; j < right.get_cols(); j++)buffer[i][j] += right.get_arr(i)[j];
	}*/
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows())
	{
		cout << "Matrix not compare!" << endl;
		return Matrix();
	}
	Matrix buf(left.get_rows(), left.get_cols());
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < left.get_cols(); j++)
		{
			buf[i][j] = left.get_arr(i)[j] + right.get_arr(i)[j];
		}
	}
	return buf;
}
Matrix operator-(const Matrix& left, const Matrix& right)
{
	Matrix buffer(left,right);
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < left.get_cols(); j++)buffer[i][j] = left.get_arr(i)[j];
	}
	for (int i = 0; i < right.get_rows(); i++)
	{
		for (int j = 0; j < right.get_cols(); j++)buffer[i][j] -= right.get_arr(i)[j];
	}
	return buffer;
}
Matrix operator*(const Matrix& left, const Matrix& right)
{
	Matrix buffer(left, right);
	for (int i = 0; i < left.get_rows(); i++)
	{
		for (int j = 0; j < left.get_cols(); j++)buffer[i][j] = left.get_arr(i)[j];
	}
	for (int i = 0; i < right.get_rows(); i++)
	{
		for (int j = 0; j < right.get_cols(); j++)buffer[i][j] *= right.get_arr(i)[j];
	}
	return buffer;
}

void main()
{
	setlocale(LC_ALL, "rus");

	Matrix A(3, 4);
	A.filling();
	A.print();
	cout << endl;

	/*Matrix B;
	B = A;
	B.print();
	cout << endl;*/

	Matrix D(3, 4);
	D.filling(300);
	D.print();

	cout << endl;
	Matrix C;
	C = A + D;
	C.print();
	cout << endl;

	/*C = C - D;
	C.print();
	cout << endl;

	C = A * D;
	C.print();*/
}