#include<iostream>

using std::cin;
using std::cout;
using std::endl;

class Fraction
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

	Fraction(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;

	}

	~Fraction()
	{
		cout << "Distructor:\t\t" << this << endl;
	}

	//        Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;

	}

	Fraction operator++(int)
	{
		Fraction old = *this; //сохраняем старое значение объекта
		//Изменяем объект:
		x++;
		y++;
		return old;
	}


	//         Methods:

	double distance(const Fraction& other)const
	{
		//this - эта точка
		//other - та точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;

		double distabce = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distabce;

	}

};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}



void main()
{

	setlocale(LC_ALL, "Russian");

	int a = 3;
	int b = 3;
	int c = a + b;

	Fraction A(2, 3);
	A.print();
	Fraction B(4, 5);
	B.print();
	Fraction C = A + B;
	C.print();
	C++;
	C.print();

}