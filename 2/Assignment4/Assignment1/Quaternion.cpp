#include "Quaternion.h"



Quaternion::Quaternion()
{
}


Quaternion::Quaternion(MATH::Vec3 axis, float angleInDegrees)
{
}

Quaternion::~Quaternion()
{
}

MATH::Vec3 Quaternion::Rotate(MATH::Vec3)
{
	return MATH::Vec3();
}

MATH::Matrix3 Quaternion::ConvertToMatrix()
{
	return MATH::Matrix3((1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z), (2.0f*q.x*q.y + 2.0f * q.z*q.w), (2.0f*q.x*q.z - 2.0f*q.y*q.w),
		(2.0f*q.x*q.y - 2.0f*q.z*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z), (2.0f * q.y*q.z + 2.0f * q.x*q.w),
		(2.0f*q.x*q.z + 2.0f*q.y*q.w), (2.0f*q.y*q.z - 2 * q.x*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y));
}

EulerAngles Quaternion::ConvertToEuler()
{
	float n = (q.x * q.y) + (q.z * q.w);

	float heading = 0.0f;
	float attitude = 0.0f;
	float bank = 0.0f;

	if (n == 0.5f) {
		heading = 2.0f * atan2(q.x, q.w);
	}
	else if (n == -0.5f) {
		heading = -2.0f * atan2(q.x, q.w);
	}
	else {
		heading = atan2(2.0f*q.y*q.w - 2.0f*q.x*q.z, 1.0f - 2.0f * (q.y * q.y) - 2.0f * (q.z * q.z));
		attitude = asin(2.0f * q.x*q.y + 2.0f*q.z*q.w);
		bank = atan2(2.0f * q.x * q.w - 2.0f * q.y*q.z, 1.0f - 2.0f * (q.x * q.x) - 2.0f * (q.z*q.z));
	}
	return EulerAngles(heading, attitude, bank);
}
