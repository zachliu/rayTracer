// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This file contains the definition of the class sphere

#include "Sphere.h"

const double Sphere::kEpsilon = 0.001;
					
// ---------------------------------------------------------------- default constructor

Sphere::Sphere(void)	
	: 	GeometricObject(),
		center(0.0),
		radius(1.0)
{}


// ---------------------------------------------------------------- constructor

Sphere::Sphere(Point3D c, double r)
	: 	GeometricObject(),
		center(c),
		radius(r)
{}


// ---------------------------------------------------------------- clone

Sphere* 
Sphere::clone(void) const {
	return (new Sphere(*this));
}


// ---------------------------------------------------------------- copy constructor

Sphere::Sphere (const Sphere& sphere)
	: 	GeometricObject(sphere),
		center(sphere.center),
		radius(sphere.radius)
{}



// ---------------------------------------------------------------- assignment operator

Sphere& 
Sphere::operator= (const Sphere& rhs)		
{
	if (this == &rhs)
		return (*this);

	GeometricObject::operator= (rhs);

	center 	= rhs.center;
	radius	= rhs.radius;

	return (*this);
}


// ---------------------------------------------------------------- destructor

Sphere::~Sphere(void) {}


//---------------------------------------------------------------- hit
bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
	double 		t;
	Vector3D	temp 	= ray.o - center;
	double 		a 		= ray.d * ray.d;
	double 		b 		= 2.0 * temp * ray.d;
	double 		c 		= temp * temp - radius * radius;
	double 		disc	= b * b - 4.0 * a * c;
	
	if (disc < 0.0)
		return(false);
	else {	
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;    // smaller root
	
		if (t > kEpsilon) {
			tmin = t;
			sr.normal 	 = (temp + t * ray.d) / radius;
			sr.local_hit_point = ray.o + t * ray.d;
			return (true);
		} 
	
		t = (-b + e) / denom;    // larger root
	
		if (t > kEpsilon) {
			tmin = t;
			sr.normal   = ((temp + t * ray.d) / radius).normalize();	// normal at hit point
			sr.local_hit_point = ray.o + t * ray.d;
			return (true);
		} 
	}
	
	return (false);
}

//---------------------------------------------------------------- shadow_hit
bool Sphere::shadow_hit( const Ray& ray, double& tmin ) const {
	double t;
	Vector3D temp = ray.o - center;
	double a = ray.d * ray.d;
	double b = 2.0 * temp * ray.d;
	double c = temp * temp - radius * radius;
	double disc = b * b - 4.0 * a * c;

	if(disc < 0.0)
		return false;
	else {
		double e = sqrt(disc);
		double demon = 2.0 * a;

		t = ( -b - e ) / demon;

		if( t > kEpsilon ) {
			tmin = t;

			return true;
		}

		t = (-b + e) / demon;
		if( t > kEpsilon ) {
			tmin = t;
			return true;
		}
	}
	return false;
}







