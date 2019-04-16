#ifndef EULERANGLES_H
#define EULERANGLES_H
#include "Vector.h"

struct EulerAngles {
	float yaw, pitch, roll;

	inline EulerAngles() : EulerAngles(0.0f,0.0f,0.0f){}

	inline EulerAngles(float yaw_, float pitch_, float roll_) {
		yaw = yaw_;
		pitch = pitch_;
		roll = roll_;
	}

	inline EulerAngles(MATH::Vec3 &vec) : EulerAngles(vec.x, vec.y, vec.z) {}
};

#endif // !EULERANGLES_H