///////////////////////////////
//Creator: Katerina Morgunova//
///////////////////////////////

#include <iostream>
#include <string>
#include "point.h"
#include "line.h"
#include "segment.h"

Segment::Segment()
{
	set(0, 0);
}

Segment::Segment(const Point&A, const Point&B)
{
	set(A, B);
}

void Segment::set(const Point& p1, const Point& p2)
{
	P1 = p1;
	P2 = p2;
}

bool Segment::SegmentContainPoint(const Point&Y)const
{
	if ((Y.operator>(P1) && (Y.operator<(P2))) || (Y.operator>(P2) && (Y.operator<(P1)))) return 1;
	else return 0;
}

bool Segment::intersectionOfLines(const Segment& S)const
{
	Line L1(P1, P2);
	Line L2(S.P1, S.P2);
	Point inter;

	if (L1.intersect(L2)) inter = L1.intersection(L2);
	else return 0;

	if (SegmentContainPoint(inter) && S.SegmentContainPoint(inter)) return 1;
	else return 0;
}