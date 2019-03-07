#ifndef SPHERE_H
#define SPHERE_H

#include "Vector.h"

class Sphere
{

public:
	Vec3 position;
	float radius;
public:

	inline Sphere(Vec3 position_, float radius_) {
		position = position_;
		radius = radius_;
	}
	inline Sphere() : Sphere(Vec3(), 1.0f){}
	inline ~Sphere() {/*Stub*/}
};


#endif // !SPHERE_H
