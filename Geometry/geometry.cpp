///////////////////////////////
//Creator: Katerina Morgunova//
///////////////////////////////

#include <iostream>
#include <string>
#include "point.h"
#include "line.h"
#include "segment.h"
#include "geometry.h"

using namespace std;

void Triangles::Cycles()
{
	ArrangeTriangle();
	for (int t = 0; t < n; t++) lines[t] = Line(points[t], points[t + 1]);
	for (int k = 0; k < n; k++) sides[k] = Segment(points[k], points[k + 1]);
}

Triangles::Triangles() : isGood(false)
{
	for (int i = 0; i <= n; i++) points[i].set(0,0);
	CreateTriangle();
}

void Triangles::CreateTriangle()
{
	points[3] = points[0];
	Cycles();
	CorrectTriangle();
}

bool Triangles::InputTriangle()
{
	if (IsCorrectIO())
	{
		CreateTriangle(); return 1;
	}
	else return 0;
}

bool Triangles::CorrectTriangle()
{
	if (!OnOneLine() && !(points[0] == points[1] || points[1] == points[2] || points[2] == points[0]))
		return isGood = true;
	return isGood;
} 

bool Triangles::OK(const Triangles& DEF)
{
	if (isGood && DEF.isGood) return 1;
	return 0;
}

bool Triangles::IsCorrectIO()
{ 
	bool Ok = true;

	for (int i = 0; i < n; i++)
	{
		if (!points[i].read()) Ok = false;
	}

	return Ok;
}

void Triangles::ArrangeTriangle()
{
	while (points[0]>points[1] || points[1]>points[2] || points[2]<points[0])
	{
		if (points[0]>=points[1]) swap(points[0], points[1]);
		if (points[1]>=points[2]) swap(points[1], points[2]);
		if (points[0]>=points[2]) swap(points[0], points[2]);
	}
	points[3] = points[0];
}

string Triangles::OutputPoints()const
{
	std::string Info="\n";
	if (!isGood) Info += "Incorrect triangle! Points are on one line!!!\n";
	for (int i = 0; i < n; i++)
		Info += std::to_string(i + 1) + " point is " + points[i].operator std::string() + "\n";
	return Info;
}

bool Triangles::OnOneLine()const
{
	if (lines[0].contain(points[2]) || lines[1].contain(points[0]) || lines[2].contain(points[1])) return 1;
	else return 0;
}

bool Triangles::SameTriangles(const Triangles& DEF)const
{
	if ((points[0]==DEF.points[0]) && (points[1] == DEF.points[1]) && (points[2] == DEF.points[2])) return 1;
	else return 0;
}

bool Triangles::OnOneSide(const Line&L, const Point& A )const
{
	if ((L.oneSide(points[0], points[1]) && L.oneSide(points[1], points[2])
		&& L.oneSide(points[2], points[3]) && L.oneSide(points[0], A)))
	return 1;
	else return 0;
}

bool Triangles::TriangleInTriangle(const Triangles& DEF)const
{
	if ((DEF.OnOneSide(lines[0], points[2]) && DEF.OnOneSide(lines[1], points[0]) && DEF.OnOneSide(lines[2], points[1]))
		|| (OnOneSide(DEF.lines[0], DEF.points[2])
			&& OnOneSide(DEF.lines[1], DEF.points[0]) 
			&& OnOneSide(DEF.lines[2], DEF.points[1]))) return 1;
	else return 0;
}//якщо трикутник всередині трикутника, якщо одна зі сторін внутр трикутника лежить на стороні зовн, але третя точка всередині
//якщо вершина внутр на стороні зовн, а інші вершини всередині зовн

bool Triangles::TrianglesIntersection(const Triangles& DEF)
{
	bool inter = 0;
	if (OK(DEF))
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (!inter && sides[i].intersectionOfLines(DEF.sides[j]))
					inter = 1;
			}
		}

		if (TriangleInTriangle(DEF) || SameTriangles(DEF) || inter) return 1;
		else return 0;
	}
	else return 0;
} 