#include <iostream>
#include "Mat3.h"

//The identity of a Mat3 is always going to be the same.
//Why not make it a static const?
const Mat3 Mat3::Identity = Mat3(
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f
);

//Default constructor that sets the matrix to the identity.
Mat3::Mat3() {
	*this = Identity;
}

//Set each element of the matrix manually.
Mat3::Mat3(
	float m0, float m1, float m2, 
	float m3, float m4, float m5, 
	float m6, float m7, float m8
) {
	m[0] = m0; m[1] = m1; m[2] = m2;
	m[3] = m3; m[4] = m4; m[5] = m5;
	m[6] = m6; m[7] = m7; m[8] = m8;
}

//Just a normal every day average destructor
Mat3::~Mat3() { /*Stub*/}

void Mat3::SetIdentity()
{
	*this = Identity;
}

//Prepare the matrix for rotation around the Z axis by theta.
void Mat3::RotateZ(float theta)
{
	theta *= DEGREE_TO_RADIAN; //Constant to convert degrees to radians. Declared in Mat3.h

	m[0] = cos(theta);
	m[1] = -sin(theta);
	m[2] = 0.0f;
	m[3] = sin(theta);
	m[4] = cos(theta);
	m[5] = 0.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;
	m[8] = 1.0f;
}

//Prepare the matrix for scaling operations.
void Mat3::Scale(float x, float y, float z)
{
	m[0] = x;    m[1] = 0.0f; m[2] = 0.0f;
	m[3] = 0.0f; m[4] = y;    m[5] = 0.0f;
	m[6] = 0.0f; m[7] = 0.0f; m[8] = z;
}

//Swap rows and columns.
void Mat3::Transpose()
{
	Mat3 tempMatrix = *this;
	//Swap rows and columns using a temporary placeholder clone of the matrix.
	m[1] = tempMatrix.m[3];
	m[2] = tempMatrix.m[6];
	m[3] = tempMatrix.m[1];
	m[5] = tempMatrix.m[7];
	m[6] = tempMatrix.m[2];
	m[7] = tempMatrix.m[5];
}

//Get the determinant of this Matrix.
float Mat3::Det() const
{	//Find the determinant of this matrix using the sum of determinants from 2x2 matrices within.
	return (   m[0] * ((m[4] * m[8]) - (m[5] * m[7]))) + 
			(- m[1] * ((m[3] * m[8]) - (m[5] * m[6]))) + 
			(  m[2] * ((m[3] * m[7]) - (m[4] * m[6])));
}

//Print the matrix to console in a... somewhat nice way.
//I could use <iomanip> + setw() to ensure it is always neat,
//but didn't feel it was necessary to add for this assignment.
void Mat3::print() const {
	std::cout << m[0] << "\t" << m[1] << "\t" << m[2] << "\n";
	std::cout << m[3] << "\t" << m[4] << "\t" << m[5] << "\n";
	std::cout << m[6] << "\t" << m[7] << "\t" << m[8] << "\t";
}
