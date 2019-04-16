#ifndef CAMERA_H
#define CAMERA_H
#include "Matrix.h"
#include "Vector.h"
#include "EulerAngles.h"

using namespace MATH;

class Camera
{
private:
	Matrix4 projection;
	Matrix4 view;
	Vec3 position;

	float fovy;
	float aspectRatio;
	float near, far;

	EulerAngles euler;
	
public:
	Camera();
	~Camera();

	inline Matrix4 getView() const { return view; };
	inline Matrix4 getProjection() const { return projection; };
	inline Vec3 getPosition() const { return position; };
	void SetOrientation(const EulerAngles euler_);
	void setFov(const float fov_);
	void setAspectRatio(const float ratio_);
	void print() const;

private:
	void Update();

};

#endif // !CAMERA_H