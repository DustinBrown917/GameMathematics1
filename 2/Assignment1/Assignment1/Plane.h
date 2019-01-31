#ifndef PLANE_H
#define PLANE_H

#include "Vector.h"
#include "Ray.h"

struct Plane {

	Vec4 plane;

	//Four argument constructor
	inline Plane(float x_, float y_, float z_, float d_) {
		plane = Vec4(x_, y_, z_, d_);
	}

	//Three component constructor.
	inline Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2) {
		Vec3 e1 = v1 - v0;
		Vec3 e2 = v2 - v1;

		Vec3 n = Vec3::Cross(e1, e2);

		float d = Vec3::Dot((-1 * n), v0);

		plane.x = n.x;
		plane.y = n.y;
		plane.z = n.z;
		plane.w = d;
	}

	//Find the intersecting point
	inline Vec3 IntersectionPoint(Ray ray) {
		Vec3 n = Vec3(plane.x, plane.y, plane.z);
		float dotProduct = Vec3::Dot(n, ray.dir);
		float subProduct = Vec3::Dot(n, ray.start) + plane.w;

		if (dotProduct == 0) {
			if (subProduct == 0) {
				//Ray is contained in plane.
				return NULL;
			}
			else {				
				//No intersection.
				return NULL;
			}
		}
		
		float t = -((plane.w + Vec3::Dot(n, ray.start)) / Vec3::Dot(n, ray.dir));

		return ray.currentPosition(t);
	}

};






#endif
