#include <iostream>
#include "Ray.h"
#include "Plane.h"

int main(int arg, char* argv[]) {

	Ray r = Ray(Vec3(1, 0, 1), Vec3(3, 2, 1));

	Plane p = Plane(2, 1, 0, -4);

	std::cout << "Ray1: Start - " << r.start.ToString() << " Dir - " << r.dir.ToString() << std::endl << std::endl;
	std::cout << "Plane1: " << p.plane.ToString() << std::endl << std::endl;
	std::cout << "Ray1 intersects plane 1 at: " << p.IntersectionPoint(r).ToString() << std::endl << std::endl;

	system("pause");
}