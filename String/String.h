#pragma once	//Директива компоновщика, которая говорит, что данный файл нужно включить в сборку один раз, независимо от количества #include-ов
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

///////////////////////////////////////////////////////////////////
////////  объявление класса - class declaration  //////////////////
class String;
std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right); //Прототип оператора +

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//				Contructors:
	explicit String(int size = 80);
	String(const char* str);
	//Deep copy (побитовое копирование)
	//other
	//this
	//Shallow copy (Поверхностное копирование)
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
////////  конец объявление класса - class declaration end  ////////
