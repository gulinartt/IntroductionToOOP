#pragma once
#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////////
///////////		ОБЪЯВЛЕНИЕ КЛАСС - CLASS DECLARATION		///////////					

#define delimiter "\n-------------------------\n"
class Point;
Point operator+(const Point& left, const Point& right);

class Point
{
	//Создавая структуру или класс мы создаем новый тип данных
	//Классы и структуры еще называют пользовательскими типами данных
	//						КЛАСС - ЭТО ТИП ДАННЫХ!!!
	//					СТРУКТУРА - ЭТО ТИП ДАННЫХ!!!
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

///////////	КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLARATION END	///////////	
///////////////////////////////////////////////////////////////////////
