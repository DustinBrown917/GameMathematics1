//#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "Vec3.h"


using namespace std;

int main(int argc, const char* argv[]) {

	cout << "Initialize Vectors: \n";
	Vec3 v1 = Vec3(1.0f, 2.0f, 3.0f);
	Vec3 v2 = Vec3(3.0f, 2.0f, 1.0f);

	cout << "v1: " << v1.ToString() << endl;
	cout << "v2: " << v2.ToString();
	cout << endl << endl;

	cout << "Dot product of v1 with v2:\n";
	cout << v1.Dot(v2);
	cout << endl << endl;

	cout << "v1 Lerp'd with v2 by 0.5: \n";
	v1.Lerp(v2, 0.5f);
	cout << "v1: " << v1.ToString();
	cout << endl << endl;

	cout << "v1 Normalized: \n";
	v1.Normalize();
	cout << "v1: " << v1.ToString() << endl;
	cout << "v1 Magnitude: " << v1.Mag();
	cout << endl << endl;

	cout << "Setting v1's z to 0 to demonstrate rotation clearly: \n";
	v1.z = 0;
	cout << "v1: " << v1.ToString();
	cout << endl << endl;

	cout << "v1 rotated around the z axis by 45 degrees: \n";
	v1.RotateZ(45.0f);
	cout << "v1: " << v1.ToString() << endl;
	cout << "And by another 90 degrees: \n";
	v1.RotateZ(90.0f);
	cout << "v1: " << v1.ToString();
	cout << endl << endl;


	//Yield for user.
	system("pause");

}

