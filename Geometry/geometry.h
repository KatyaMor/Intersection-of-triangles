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
	// �����������, ���� ������� ���������� ���������
	std::string OutputPoints()const;
	// �������� ���������� �����
	bool InputTriangle();
	// ������� ���������� �� ������ ������ CreateTriangle
	bool TrianglesIntersection(const Triangles&);
	// ��������, �� �� ������� ���������� ABC i DEF ���������� �������
	bool SameTriangles(const Triangles&)const;
	// �������� �� ������� ����������, ����� ����� ������� �����
	bool TriangleInTriangle(const Triangles&)const;
	// �������� �� ����������� ��������� � ������ ����������
	bool OnOneSide(const Line&, const Point&)const;
	//�������� �� ������ ��������� �� ����� �� ���� �� �� �����, ����� ����� �������� ����, �� ���� 

private:

	static const int  n = 3;

	Point points[n+1];
	Line lines[n];
	Segment sides[n];

	bool isGood;
	// �����, ��� ������a� �� ���������� ���������� 
	bool OnOneLine()const;
	//�������� �� �� ����������� �� ����� ���������� �� ���� ����� ���� �������� ���� ��������, ������ �������� ����
	bool CorrectTriangle();
	//�������� �� ����������� �������� ���������, ����� ���� �� ��� ����� ������� ��� ������ �� ���� �����, �� ����
	bool OK(const Triangles&);
	//���� ��� ���� � ���� ���������� ������������, �� isOk ������������ ����
	bool IsCorrectIO();
	//������� ��� ����� �� �������� ���� �����������
	void CreateTriangle();
	//������� ���������(��, ��������)
	void ArrangeTriangle();
	//���������� ����� ����������
	void Cycles();
	//����� ��� ������������ ������� ������ �� ������ �� ������ ������������� ����� 
	
};
