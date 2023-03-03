#pragma once	//��������� ������������, ������� �������, ��� ������ ���� ����� �������� � ������ ���� ���, ���������� �� ���������� #include-��
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////
////////  ���������� ������ - class declaration  //////////////////
class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right); //�������� ��������� +

class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//				Contructors:
	explicit String(int size = 80);
	String(const char* str);
	//Deep copy (��������� �����������)
	//other
	//this
	//Shallow copy (������������� �����������)
	String(const String& other);
	String(String&& other);
	~String();

	//				Operators:
	String& operator=(const String& other);

	String& operator=(String&& other);


	String& operator+=(const String& other);

	char operator[](int i)const;
	char& operator[](int i);

	//				Methods:
	void print()const;
};

///////////////////////////////////////////////////////////////////
////////  ����� ���������� ������ - class declaration end  ////////
