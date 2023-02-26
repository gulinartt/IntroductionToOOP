#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n---------------------\n"

class Point
{
	//создавая структуру или класс мы создвем новый тип данных
	//классы и структуры еще называют пользовательскими типами данных

	double x; // переменные члены
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

	//        Constructors:
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

	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;

	}

	//       Destructors:

	~Point()
	{
		cout << "Distructor:\t\t" << this << endl;
	}

	//        Operators:
	
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;

	}

	Point operator++(int)
	{
		Point old = *this; //сохраняем старое значение объекта
		//Изменяем объект:
		x++;
		y++;
		return old;
	}


	//         Methods:

	double distance(const Point& other)const
	{
		//this - эта точка
		//other - та точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		
		double distabce = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distabce;

	}


	void print()const
	{
		cout << "X=" << x << "\tY=" << y << endl;
	}



};

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

//#define STRUCT_POINT
//#define CONSTRUCTOR_CHEK
//#define DISTABCE_CHEK
//#define ASSIGNMENT_CHEK
 
void main()
{

	setlocale(LC_ALL, "Russian");

#ifdef STRUCT_POINT
	int a;  //обьявление переменной 'а' типа 'int'
	Point A;// обьявление переменной 'А' типа 'Point'
	        //создание обьекта 'А' структуры 'Point'
	        //создание экземпляра 'А' структуры 'Point'
	        //обьекты классов и стуктур еще называют экземплярами классов и структур
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

#ifdef CONSTRUCTOR_CHEK
	Point A;    //Здесь вызывается конструктор по умолчанию (Default constructor)
	//A.set_x(2);
	//A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;   //Single-argument constructor
	B.print();

	Point C(22, 33);
	C.print();

	Point D = C; //Copy constructor
	D.print();

	Point E;
	E = D;  //Copy assignment
	E.print();


	/*for (int i = 0; i < 10; i++)
	{
		cout << i << "\t";

	}
	cout << endl;*/

#endif

#ifdef DISTABCE_CHEK
	


	Point A(2, 3);
	A.print();

	Point B(4, 5);
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки В до точки А: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;

	//Point C = B; //Copy constructor

#endif

#ifdef ASSIGNMENT_CHEK
	//Copy assignment
 
	int a, b, c;
	a = b = c = 2;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();

#endif //ASSIGNMENT_CHEK


	int a = 3;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	Point C = A + B;
	C.print();
	C++;
	C.print();

}