//TODO:
//0. Выучить теорию!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//1. В Solution 'IntroductionToOOP' добавить проект 'Fraction', и в нем реализовать класс 'Fraction',
//описывающий простую дробь.В классе должны быть все необходимые методы и операторы;

#include<iostream>
using namespace std;

class Fraction
{
	int h;
	int z;

public:
	int get_h()const
	{
		return h;
	}
	int get_z()const
	{
		return z;
	}

	void set_h(int h)
	{
		this->h = h;
	}
	void set_z(int z)
	{
		if (z == 0)z = 1;
		this->z = z;
	}

//     Constructors:
	Fraction(int h = 0, int z = 1)
	{
		this->h = h;
		this->z = z;
		cout << "Constructor:\t\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

//     Metods:
	void print()const
	{
		cout << "HICLITEL = " << h << "\tZNAMENATEL = " << z << endl;
	}
	Fraction& vvFraction()
	{
		cout << "Введите числитель: ";
		cin >> h;
		cout << "Введите знаменатель: ";
		cin >> z;
		cout << "\n";
		return *this;
	}
};

int main()
{
	setlocale(0, "");

	Fraction A;
	A.vvFraction();
	A.print();
}