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
	Quaternion(MATH::Vec3 axis, float angleInDegrees);
	~Quaternion();

	inline const Quaternion operator *( const Quaternion other){
		MATH::Vec3 myV = MATH::Vec3(q.x, q.y, q.z);
		MATH::Vec3 oV = MATH::Vec3(other.q.x, other.q.y, other.q.z);
		MATH::Vec3 crossed(q.w * oV + other.q.w * myV + MATH::VMath::cross(myV, oV));


		return Quaternion(crossed.x, crossed.y, crossed.z, q.w * other.q.w - MATH::VMath::dot(q, other.q));
	}

	inline const float Mag() const {
		return sqrt((q.x * q.x) + (q.y * q.y) + (q.z *q.z) + (q.w * q.w));
	}

	inline const Quaternion Normal() const {
		MATH::Vec4 n = q / Mag();
		return Quaternion(n.x, n.y, n.z, n.w);
	}

	inline void Conjugate() {
		q.x *= -1.0f;
		q.y *= -1.0f;
		q.z *= -1.0f;
	}

	inline void Invert() {
		Quaternion q2 = Quaternion(q.x, q.y, q.z, q.w);
		q2.Conjugate();

		
	}

	MATH::Vec3 Rotate(MATH::Vec3);
	MATH::Matrix3 ConvertToMatrix();
	EulerAngles ConvertToEuler();
};

#endif

