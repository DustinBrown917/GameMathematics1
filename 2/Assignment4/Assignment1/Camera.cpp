#include <iostream>
#include "Camera.h"



Camera::Camera()
{
	projection = Matrix4();
	view = Matrix4();
	position = Vec3();
	euler = EulerAngles();
	fovy = 45.0;
	aspectRatio = 16.0f/9.0f;
	near = 0.5f;
	far = 100.0f;
	Update();
}


Camera::~Camera()
{
}

void Camera::SetOrientation(const EulerAngles euler_)
{
	euler = euler_;
	Update();
}

void Camera::setFov(const float fov_)
{
	fovy = fov_;
	Update();
}

void Camera::setAspectRatio(const float ratio_)
{
	aspectRatio = ratio_;
	Update();
}

void Camera::Update()
{
	float radializedFov = 1.0f / tan(fovy* 0.5f * DEGREES_TO_RADIANS);
	/// Don't forget, this looks row centric but it really is a column matrix - right-hand rule rules
	projection = Matrix4(radializedFov / aspectRatio, 0.0f, 0.0f, 0.0f,
		0.0f, r  adializedFov, 0.0f, 0.0f,
		0.0f, 0.0f, (near + far) / (near - far), -1.0,
		0.0, 0.0, (2.0f*near*far) / (near - far), 0.0);
}

void Camera::print() const
{
	std::cout << "Position: [" << position.x << ", " << position.y << ", " << position.z << "]" << std::endl
		<< "Euler: [yaw " << euler.yaw << ", pitch " << euler.pitch << ", roll " << euler.yaw << "]" << std::endl
		<< "FOV: " << fovy << std::endl
		<< "Aspect Ratio: " << aspectRatio << std::endl
		<< "Near Clipping Plane: " << near << std::endl
		<< "Far Clipping Plane: " << far << std::endl
		<< "Projection Matrix: " << std::endl << std::endl;

	projection.print();

	std::cout << "View Matrix: " << std::endl;

	view.print();
}
