#ifndef MAT3_H
#define MAT3_H

#ifndef DEGREE_TO_RADIAN
#define DEGREE_TO_RADIAN 0.01745329251f;
#endif

#ifndef TINY_FLOAT
#define TINY_FLOAT 1.0e-7f
#endif

#include "Vector.h"

class Mat3 {
private: //I know classes are private by default, this is just to improve readability.
	float m[9];

public:
	static const Mat3 Identity; //Identity will always be the same. More useful as a static constant.

public:
	//Overloaded assignment operator.
	inline Mat3& operator = (const Mat3 other) {
		for (int i = 0; i < 9; i++) {
			m[i] = other[i];
		}
		return *this;
	}

	//Allow array style reading of element at index
	inline const float operator [] (int index) const {
		return m[index];
	}

	//Allow array style writing to element at index.
	inline float& operator [] (int index) {
		return m[index];
	}

	//Multiplication operator.
	inline const Mat3 operator * (const Mat3& other) const {
		Mat3 result = Mat3(0.0f);
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < 3; i++) {
					result[k * 3 + j] += (m[i * 3 + j] * other[k * 3 + i]);
				}
			}
		}
		return result;
	}

	//Multiplication + assignment operator.
	inline Mat3& operator *= (const Mat3& other) {
		*this = *this * other;
		return *this;
	}

	//Multiply this matrix by a Vec3.
	inline const Vec3 operator * (const Vec3& vec) const {
		Vec3 result = Vec3(0);

		result.x = (m[0] * vec.x) + (m[1] * vec.y) + (m[2] * vec.z);
		result.y = (m[3] * vec.x) + (m[4] * vec.y) + (m[5] * vec.z);
		result.z = (m[6] * vec.x) + (m[7] * vec.y) + (m[8] * vec.z);
		return result;
	}

public:
	Mat3(); //Default constructor
	Mat3(float unit);
	Mat3(float m0, float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8); //Constructor to set each element manually.
	~Mat3(); //Default destructor

	//Set this matrix to identity.
	void SetIdentity(); //Seems a useless method now that I can just write "*this = Mat3::Identity;"
	//Prepare this matrix for rotation by theta around the Z axis.
	void RotateZ(float theta);
	//Prepare the matrix for scaling in 3 dimensions.
	void Scale(float x, float y, float z);
	//Swap rows and columns.
	void Transpose();
	//Get the determinant of the matrix.
	float Det() const;
	//Invert the matrix
	static const Mat3 Inverse(const Mat3& m);

	//Print the matrix to console.
	void print() const;
};

#endif
