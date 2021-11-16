#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class Binary
{
	int size;
	unsigned int* arr;
public:
	int get_size()const
	{
		return size;
	}
	const int get_arr()const
	{
		return *arr;
	}
	int get_arr()
	{
		return *arr;
	}

	Binary() noexcept
	{
		this->size = 10;
		this->arr = new unsigned int[size]{};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Binary(const int number)
	{
		int s = 0;
		int n = number;
		while ((n /= 10) > 0)s++;
		s++; n = number;
		this->size = s;
		this->arr = new unsigned int[size] {};
		for (int i = size-1; n; i--)
		{
			arr[i] = n % 10;
			n /= 10;
		}
		cout << "Constructor:\t" << this << endl;
	}
	Binary(const Binary& other)
	{
		this->size = other.size;
		this->arr = new unsigned int[size] {};
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = other.arr[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	Binary(Binary&& other) noexcept
	{
		this->size = other.size;
		this->arr = other.arr;
		other.arr = nullptr;
		other.size = 0;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~Binary()
	{
		delete[] this->arr;
		cout << "Destructior:\t" << this << endl;
	}
	//Operators
	Binary& operator=(const Binary& other)
	{
		if (this != &other)
		{
			delete[]this->arr;
			this->size = other.size;
			this->arr = new unsigned int[size] {};
			for (int i = 0; i < size; i++)
				this->arr[i] = other.arr[i];
		}
		cout << "CopyAssigment:\t\t" << this << endl;
		return *this;
	}
	Binary& operator=(Binary&& other) noexcept
	{
		this->size = other.size;
		this->arr = other.arr;
		other.arr = nullptr;
		other.size = 0;
		return *this;
	}

	//Methods
	void print()
	{
		cout << "Size = " << size << endl;
		cout << "Binary = ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}
};

//Binary& operator+(const Binary& left, const Binary& right)
//{
//}

void main()
{
	setlocale(LC_ALL, "rus");
	Binary A = 1010111;
	A.print();
	Binary B = 11010;
	B.print();

}