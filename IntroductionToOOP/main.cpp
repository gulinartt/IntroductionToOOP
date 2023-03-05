#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------\n"

class Point
{
	//�������� ��������� ��� ����� �� ������� ����� ��� ������
	//������ � ��������� ��� �������� ����������������� ������ ������
	//						����� - ��� ��� ������!!!
	//					��������� - ��� ��� ������!!!
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);

	//				  Constructors:
	/*Point()
	{
		x = y = double();
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//					Operators:
	Point& operator=(const Point& other);

	Point& operator++();
	Point operator++(int);

	//					Methods:
	double distance(const Point& other)const;
	void print()const;
};

double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

//				  Constructors:
/*Point()
{
	x = y = double();
	cout << "DefaultConstructor:\t" << this << endl;
}
Point(double x)
{
	this->x = x;
	this->y = 0;
	cout << "1ArgConstructor:\t" << this << endl;
}*/
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "Constructor:\t\t" << this << endl;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyConstructor:\t" << this << endl;
}
Point::~Point()
{
	cout << "Destructor:\t\t" << this << endl;
}

//					Operators:
Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

Point& Point::operator++()	//Prefix increment
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)
{
	Point old = *this;	//��������� ������ �������� �������
	//�������� ������:
	x++;
	y++;
	return old;
}

//					Methods:
double Point::distance(const Point& other)const
{
	//this - ��� �����
	//other - �� �����
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
void Point::print()const
{
	cout << "X = " << x << "\tY = " << y << endl;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

int add(int a = 0, int b = 0)
{
	return a + b;
}

//#define STRUCT_POINT
//#define CONTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK

void main()
{

	setlocale(LC_ALL, "Russian");

	//cout << add() << endl;
	//cout << "\n----------------------------\n";

#ifdef STRUCT_POINT
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
	//�������� ������� 'A' ��������� 'Point'
	//�������� ���������� 'A' ��������� 'Point'
	//������� ������� � �������� ��� �������� ������������ ������� � ��������.

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef CONTRUCTORS_CHECK
	Point A;		//����� ���������� ����������� �� ��������� (Default constructor)
	//A.set_x(2);
	//A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;	//Single-argument constructor
	B.print();

	Point C(22, 33);
	C.print();

	Point D = C;	//Copy constructor
	D.print();

	Point E;		//Default constructor
	E = D;			//Copy assignment
	E.print();


	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";

	}
	cout << endl;*/
#endif // CONTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	/*
------------------
1. ��������� ������;
2. ��� ���� ���������� �����;
3. � ���� ����� ���������� ��������� �����
   (������� ��� �� �������������� ������ ���� �������);
------------------
*/

	Point A(2, 3);
	A.print();

	Point B(4, 5);
	B.print();

	cout << delimiter << endl;
	cout << "���������� �� ����� A �� ����� B:" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� B �� ����� A:" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� A � B:  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� B � A:  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	//Copy assignment:

	int a, b, c;
	a = b = c = 2;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << "\n-------------------------------\n";
	A = B = C = Point(2, 3);
	cout << "\n-------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);	A.print();
	Point B(4, 5);	B.print();
	Point C = A + B; C.print();
	C++; C.print();
}
