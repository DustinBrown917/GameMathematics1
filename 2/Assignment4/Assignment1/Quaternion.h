#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector.h"
#include "VMath.h"
#include "EulerAngles.h"
#include "Matrix.h"

class Quaternion
{
public:

	MATH::Vec4 q;

	inline Quaternion() : Quaternion(0.0f,0.0f,0.0f,1.0f) {}
	inline Quaternion(float x, float y, float z, float w) { q.x = x; q.y = y; q.z = z; q.w = w; }
	inline Quaternion(MATH::Vec3 axis, float angleInDegrees) {
		
		//Convert angle to radians
		angleInDegrees = angleInDegrees / 360.0f * M_PI * 2.0f;

		q.w = cos(angleInDegrees*0.5f);

		axis = axis * sin(angleInDegrees * 0.5f);

		q.x = axis.x;
		q.y = axis.y;
		q.z = axis.z;

	}
	~Quaternion();

	inline Quaternion operator *( const Quaternion other){
		MATH::Vec3 v = MATH::Vec3(q.x, q.y, q.z);
		MATH::Vec3 otherV = MATH::Vec3(other.q.x, other.q.y, other.q.z);
		float w = q.w * other.q.w - MATH::VMath::dot(v, otherV);

		MATH::Vec3 ijk = other.q*q.w + v * other.q.w + MATH::VMath::cross(v, otherV);

		return Quaternion(ijk.x, ijk.y, ijk.z , w);
	}

	inline const float Mag() const {
		return sqrt((q.x * q.x) + (q.y * q.y) + (q.z *q.z) + (q.w * q.w));
	}

	inline Quaternion Normal() const {
		MATH::Vec4 n = q / Mag();
		return Quaternion(n.x, n.y, n.z, n.w);
	}

	inline void Conjugate() {
		q.x *= -1.0f;
		q.y *= -1.0f;
		q.z *= -1.0f;
	}

	inline void Invert() {
		float mag = this->Mag();

		Conjugate();
		q = q / mag;
	}

	inline void print() {
		q.print();
	}

	MATH::Vec3 Rotate(MATH::Vec3);
	MATH::Matrix3 ConvertToMatrix3();
	MATH::Matrix4 ConvertToMatrix4();
	EulerAngles ConvertToEuler();
};

#endif

