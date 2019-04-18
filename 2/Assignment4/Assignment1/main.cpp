#include <iostream>
#include "Quaternion.h"
#include "Vector.h"
#include "EulerAngles.h"

using namespace MATH;
int main(int arg, char* argv[]) {


	Quaternion rot = Quaternion(Vec3(0,0,1), 90);

	Vec3 v = Vec3(1, 0, 0);
	v.print();
	v = rot.Rotate(v);
	v.print();

	Quaternion q1 = Quaternion(1.0f, 2.0f, 2.0f, 3.0f);
	Quaternion q2 = Quaternion(2.0f, 1.0f, 2.0f, 5.0f);

	q1.print();

	q2.print();

	Quaternion q3 = q1 * q2;

	q3.print();

	system("pause");
}