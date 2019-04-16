#include <stdio.h>
#include "Collider.h"


bool Collider::RaySphereCollisionDetected(const Ray & ray, const Sphere & sphere)
{
	float D = Descriminant(ray, sphere);
	if (D >= 0) { return true; }
	else { return false; }
}

bool Collider::RayAABCollisionDetected(const Ray & ray, const AxisAlignedBox & box)
{
	//Check for possible face collisions using cascading if statements. 
	//Return without progression if collision is found.
	if (ray.dir.x != 0) {
		if(ray.dir.x > 0){
			//Test x=0
			float t = (-ray.start.x) / (ray.dir.x);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
		else {
			//Test x=rx
			float t = (box.r.x - ray.start.x) / (ray.dir.x);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
	}

	if (ray.dir.y != 0) {
		if (ray.dir.y > 0) {
			//Test y=0
			float t = (-ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
		else {
			//Test y=ry
			float t = (box.r.y - ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
	}

	if (ray.dir.z != 0) {
		if (ray.dir.z > 0) {
			//Test z=0
			float t = (-ray.start.z) / (ray.dir.z);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
		else {
			//Test z=rz
			float t = (box.r.y - ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return true;
				}
			}
		}
	}
	return false;
}

Vec3 Collider::RaySphereCollisionPoint(const Ray & ray, const Sphere & sphere)
{
	float a = Vec3::Dot(ray.dir, ray.dir);
	float b = 2 * (Vec3::Dot(ray.start, ray.dir));
	float c = Vec3::Dot(ray.start, ray.start) - (sphere.radius * sphere.radius);
	float d = Descriminant(ray, sphere);

	if (d < 0) { return Vec3(); } //No collision, handle error

	float t1 = (-b + sqrt(d)) / (2 * a);
	float t2 = (-b - sqrt(d)) / (2 * a);


	if (t1 == t2) { return ray.currentPosition(t1); }
	else {
		if (t1 < t2) { return ray.currentPosition(t1); }
		else { return ray.currentPosition(t2); }
	}
	printf("No collision detected");
	return Vec3();
}

Vec3 Collider::RayAABCollisionPoint(const Ray & ray, const AxisAlignedBox & box)
{
	//Check for possible face collisions using cascading if statements. 
	//Return the point at which the collision was found.
	//In instances where collisions occur in parallel with a plane, I return the point at the beginning of the ray.
	//My reasoning is that in a game, if a distinguishable start point begins in a collided state, then that point is the point of collision.
	//This is specifically because a ray HAS a start point. Were we dealing with infinite lines, it would be a different story.
	if (ray.dir.x != 0) {
		if (ray.dir.x > 0) {
			//Test x=0
			float t = (-ray.start.x) / (ray.dir.x);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
		else {
			//Test x=rx
			float t = (box.r.x - ray.start.x) / (ray.dir.x);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
	}

	if (ray.dir.y != 0) {
		if (ray.dir.y > 0) {
			//Test y=0
			float t = (-ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
		else {
			//Test y=ry
			float t = (box.r.y - ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
	}

	if (ray.dir.z != 0) {
		if (ray.dir.z > 0) {
			//Test z=0
			float t = (-ray.start.z) / (ray.dir.z);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
		else {
			//Test z=rz
			float t = (box.r.y - ray.start.y) / (ray.dir.y);
			if (t >= 0) {
				Vec3 p = ray.currentPosition(t);
				if (p.x >= 0 && box.r.x >= p.x &&
					p.y >= 0 && box.r.y >= p.y &&
					p.z >= 0 && box.r.z >= p.z) {
					return p;
				}
			}
		}
	}
	printf("No collision detected");
	return Vec3();
}

//Useful subroutine for grabbing the discriminant in a ray/sphere collision.
//Useful for avoiding divide by zero cases.
float Collider::Descriminant(const Ray & ray, const Sphere & sphere)
{
	float a = Vec3::Dot(ray.dir, ray.dir);
	float b = 2 * (Vec3::Dot(ray.start, ray.dir));
	float c = Vec3::Dot(ray.start, ray.start) - (sphere.radius * sphere.radius);

	return (b * b) - 4 * a * c;
}
