#ifndef COLLIDER_H
#define COLLIDER_H

#include "Vector.h"
#include "Sphere.h"
#include "Ray.h"
#include "AxisAlignedBox.h"

class Collider
{
public:
	static bool RaySphereCollisionDetected(const Ray &ray, const Sphere &sphere);
	static bool RayAABCollisionDetected(const Ray &ray, const AxisAlignedBox &box);
	static Vec3 RaySphereCollisionPoint(const Ray &ray, const Sphere & sphere);
	static Vec3 RayAABCollisionPoint(const Ray &ray, const AxisAlignedBox &box);
	static float Descriminant(const Ray &ray, const Sphere &sphere);
};

#endif // !COLLIDER_H

