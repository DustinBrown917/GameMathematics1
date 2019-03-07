#ifndef AXISALIGNEDBOX_H
#define AXISALIGNEDBOX_H

#include "Vector.h"
#include "Plane.h"

class AxisAlignedBox
{
public:
	Vec3 r;
	Plane box[6];


public:

	inline AxisAlignedBox(Vec3 bounds_) {
		r = bounds_;
		box[0] = Plane(1, 0, 0, 0);
		box[1] = Plane(0, 1, 0, 0);
		box[2] = Plane(0, 0, 1, 0);
		box[3] = Plane(1, 0, 0, -r.x);
		box[4] = Plane(0, 1, 0, -r.y);
		box[5] = Plane(0, 0, 1, -r.z);
	}

	inline AxisAlignedBox() : AxisAlignedBox(Vec3(1)) {}
	inline ~AxisAlignedBox() {};
};

#endif // !AXISALIGNEDBOX_H
