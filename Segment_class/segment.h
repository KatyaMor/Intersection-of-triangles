///////////////////////////////
//Creator: Katerina Morgunova//
///////////////////////////////

#pragma once

#include "line.h"
#include "point.h"
#include <string>

class Segment
{
public:
	Segment();
	Segment(const Point&, const Point&);
	void set(const Point&, const Point&);
	//встановлює кінці відрізка
	bool SegmentContainPoint(const Point&)const;
	// перевіряє, чи належить точка Y відрізку
	bool intersectionOfLines(const Segment&)const;
	// перевіряє чи мають відрізки спільну точку
private:
	Point P1, P2;
};