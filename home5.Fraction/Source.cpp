#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right); 
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer; //����� �����
	int numerator;//���������
	int denominator;//�����������
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}


	//     Constructors:
	Fraction()  
	/*����������� � �� ��������� ���������� 
	��������������*/
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	/*����������� � ����� ����������, 
    ������� ��������� ������ ����� �����*/
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	/*����������� ��� ��������� � ����������� 
	��� ����� �����*/
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);/*����� �� ������ ���������� ��� ���, ������� set 
		                              ��� �����������, �.�. ��� ���� �������� �� 0*/
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
    /*�����������, ����� ������ ������� 
    ��� ���� ������*/
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	/*����������� ����������� ��������� ����������� 
	������ �� ������� ������*/
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;/*������������� ������������ set, �.�. ������ ����������� 
		                                       � ������� �������, � ��� ������ ��� �������������*/
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//     Operators:
	Fraction& operator=(const Fraction& other)/*�������� ������������ ���������� ������ �� ������*/
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;/*�������������� this*/
	}
	Fraction& operator++()
	{
		integer++;
		numerator++;
		denominator++;
		return *this;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other; 
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//     Methods:
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else more = denominator, less = numerator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD; 
		denominator /= GCD;
		return *this;
	}
	Fraction& to_improper()/*������� � ������������ �����*/
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()/*�������������� � ���������� �����*/
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const /*����� ��� ��������������� �����*/
	{
		Fraction inverted = *this; //��������� ����� ������ inverted � �������� ������
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);/*������ ��������� � �����������*/
		return inverted;
	}
	void print()const /*����������� �����*/
	{
		if (integer)cout << integer;/*���� ���� ����� �����, ����� ������� ��*/
		if (numerator)/*���� ���� ���������*/
		{
			if (integer)cout << "(";/*���� ���� ����� �����, �� �������� ������ ����� ����������*/
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;/*���� ��� ����� �����, ������� 0*/
		cout << endl;
	}
};
Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator*(Fraction left, Fraction right)  
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	return result;*/
	//������� ��������� ���������� ������, � ����� �� ���������� ��� �� ����� ������.
	//��������� ���������� ������� ���������� ������ � �������� ������ ��������� (�� ;)
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
/////////////////////////////////////////////////////////////////////
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
	!true == false;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
/////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
/////////////////////////////////////////////////////////////////////


//#define CONSTRUCTORS_CHEC
//#define ARITHMETICAL_OPERATORS_CHECK

int main()
{

	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHEC
	Fraction A; //Default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif CONSTRUCTORS_CHEC


#ifdef ARITHMETICAL_OPERATORS_CHECK

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	(A + B).print();


	/*Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print();*/

	int a = 2;
	int b = 3;
	a *= b;  //a=6        //a = a * b;
	a /= b;  //a=2

	/*A *= B;
	A.print();

	A /= B;
	A.print();*/

#endif ARITHMETICAL_OPERATORS_CHECK


	//cout <<(Fraction(1, 2) >= Fraction(5, 10)) << endl;


	Fraction A(2, 3, 4);
	//cout << A << endl;
	A.print(); 

	/*A--;                 //�������, ��� �� ���������� �������� ++ � --, ������? 
	                         �������� �� ����� � �������� ����� ��������� ��������� 
					         ���� ��������� � �� ����� � ����� ������������ �� ���������
					         � �������� ������ �� ������ �� ������ ��� �������� � �� ��������� �������� ��� ���
	A++;
	A.print();*/

	Fraction B(3, 4, 5);
	B.print();

	A *= B;
	A.print();

	A /= B;
	A.print();

	Fraction C = A * B;
	C.print();

	Fraction D = A / B;
	D.print(); 

	Fraction S;
	S == A;
	S.print();


}