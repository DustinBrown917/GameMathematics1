#ifndef RAY_H
#define RAY_H

#include "Vector.h"

struct Ray {
	Vec3 start;
	Vec3 dir;

	//Two argument constructor.
	inline Ray(Vec3 start_, Vec3 dir_) {
		start = start_;
		dir = dir_;
	} 

	//Get the position of the line at distance t
	inline Vec3 currentPosition(float t) {
		return (dir * t) + start;
	}
};

#endif
