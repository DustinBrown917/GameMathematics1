#include <iostream>
#include "Ray.h"
#include "Plane.h"
#include "Sphere.h"
#include "Collider.h"
#include "AxisAlignedBox.h"

int main(int arg, char* argv[]) {

	Sphere sphere = Sphere(Vec3(), 5.0f);

	Ray r = Ray(Vec3(2, -1, -1), Vec3(0, 2, 3));

	AxisAlignedBox b = AxisAlignedBox(Vec3(20, 10, 10));


	std::cout << Collider::RaySphereCollisionPoint(r, sphere).ToString() << std::endl;

	std::cout << Collider::RayAABCollisionPoint(r, b).ToString() << std::endl;


	system("pause");
}