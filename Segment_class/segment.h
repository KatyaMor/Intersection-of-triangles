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
	//���������� ���� ������
	bool SegmentContainPoint(const Point&)const;
	// ��������, �� �������� ����� Y ������
	bool intersectionOfLines(const Segment&)const;
	// �������� �� ����� ������ ������ �����
private:
	Point P1, P2;
};