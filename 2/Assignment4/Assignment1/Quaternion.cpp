#include "Quaternion.h"




Quaternion::~Quaternion(){/*Stub*/}

MATH::Vec3 Quaternion::Rotate(MATH::Vec3 v_)
{
	//Invert the quaternion
	Quaternion qInv = *this;
	qInv.Invert();

	//Get the vector as a flat quaternion
	Quaternion qFlat = Quaternion(v_.x, v_.y, v_.z, 0);

	//Multiply multiply the resultant quaternions
	Quaternion qr = (*this) * qFlat * qInv;
	

	return MATH::Vec3(qr.q.x, qr.q.y, qr.q.z);
}

MATH::Matrix3 Quaternion::ConvertToMatrix3()
{
	return MATH::Matrix3((1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z), (2.0f*q.x*q.y + 2.0f * q.z*q.w), (2.0f*q.x*q.z - 2.0f*q.y*q.w),
		(2.0f*q.x*q.y - 2.0f*q.z*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z), (2.0f * q.y*q.z + 2.0f * q.x*q.w),
		(2.0f*q.x*q.z + 2.0f*q.y*q.w), (2.0f*q.y*q.z - 2 * q.x*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y));
}

MATH::Matrix4 Quaternion::ConvertToMatrix4()
{
	return MATH::Matrix4((1.0f - 2.0f*q.y*q.y - 2.0f*q.z*q.z), (2.0f*q.x*q.y + 2.0f * q.z*q.w), (2.0f*q.x*q.z - 2.0f*q.y*q.w), 0.0f,
		(2.0f*q.x*q.y - 2.0f*q.z*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.z*q.z), (2.0f * q.y*q.z + 2.0f * q.x*q.w), 0.0f,
		(2.0f*q.x*q.z + 2.0f*q.y*q.w), (2.0f*q.y*q.z - 2 * q.x*q.w), (1.0f - 2.0f*q.x*q.x - 2.0f*q.y*q.y), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

EulerAngles Quaternion::ConvertToEuler()
{
	//Find the test factor n
	float n = (q.x * q.y) + (q.z * q.w);

	float heading = 0.0f;
	float attitude = 0.0f;
	float bank = 0.0f;

	//if n is oriented northward
	if (n == 0.5f) {
		heading = 2.0f * atan2(q.x, q.w);
	}
	//if n is oriented southward
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
