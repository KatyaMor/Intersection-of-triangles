///////////////////////////////
//Creator: Katerina Morgunova//
///////////////////////////////

#pragma once

#include "line.h"
#include "point.h"
#include "segment.h"
#include <string>

class Triangles
{
public:
	Triangles();
	// конструктор, який створює вироджений трикутник
	std::string OutputPoints()const;
	// виводить координати точок
	bool InputTriangle();
	// введеня трикутника та виклик методу CreateTriangle
	bool TrianglesIntersection(const Triangles&);
	// перевіряє, чи має перетин трикутників ABC i DEF ненульовий перетин
	bool SameTriangles(const Triangles&)const;
	// перевіряє чи однакові трикутники, тобто мають однакові точки
	bool TriangleInTriangle(const Triangles&)const;
	// перевіряє чи знаходиться трикутник в іншому трикутнику
	bool OnOneSide(const Line&, const Point&)const;
	//перевіряє чи лежать трикутник та точка по один бік від прямої, якощо точка належить прямі, то хиба 

private:

	static const int  n = 3;

	Point points[n+1];
	Line lines[n];
	Segment sides[n];

	bool isGood;
	// змінна, яка відповідaє за коректність трикутника 
	bool OnOneLine()const;
	//перевіряє чи не знаходяться всі точки трикутника на одній прямій якщо введення було коректне, інакше виводить хибу
	bool CorrectTriangle();
	//перевіряє на корректність введений трикутник, тобто якщо всі три точки однакові або лежать на одній прямій, то хиба
	bool OK(const Triangles&);
	//якщо хоч один з двох трикутників неправильний, то isOk присвоюється хиба
	bool IsCorrectIO();
	//виконнує ввід точок та перевіряє його корректність
	void CreateTriangle();
	//створює трикутник(лінії, сегменти)
	void ArrangeTriangle();
	//впорядковує точки трикутника
	void Cycles();
	//цикли для встановлення значень прямих та відрізків та виконує упорядкування точок 
	
};
