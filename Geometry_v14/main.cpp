///////////////////////////////
//Creator: Katerina Morgunova//
///////////////////////////////

#include <iostream>
#include "geometry.h"
#include "copyright.h"

using namespace std;

int main()
{
	cout << "\n\t\t\t\t Geometry\n";
	information();//copyright
	cout << "\t\t\t\tVariant 14\n";
	cout << "\tChecking of non-zero intersection area of triangles ABC and DEF\n\n";

	Triangles ABC, DEF;

	cout << "Enter points for the triangle ABC: ";
	if (!ABC.InputTriangle()) { cout << "\n\nInvalid Input! I can not check intesection area correctly(\n"; system("pause"); return 0;}
	cout << "\nEnter points for the triangle DEF: ";
	if (!DEF.InputTriangle()) { cout << "\n\nInvalid Input! I can not check intesection area correctly(\n"; system("pause"); return 0; }

	cout << "\n\n__Points of  the triangle ABC__\n";
	cout << ABC.OutputPoints();
	cout << "\n__Points of the triangle DEF__\n";
	cout << DEF.OutputPoints();

	if (ABC.TrianglesIntersection(DEF)) cout << "\n__Triangles have non-zero intersection area__\n";
	else cout << "\n__Triangles have not non-zero intersection area__\n";

	system("pause");
	return 0;
}