// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Lambertian.h"
#include "Constants.h"

// ---------------------------------------------------------------------- default constructor

Lambertian::Lambertian(void) 
	:   BRDF(),
		kd(0.0), 
		cd(0.0)
{}


// ---------------------------------------------------------------------- copy constructor

Lambertian::Lambertian(const Lambertian& lamb) 
	:   BRDF(lamb),
		kd(lamb.kd), 
		cd(lamb.cd)
{}


// ---------------------------------------------------------------------- clone

BRDF* 
Lambertian::clone(void) const {
	return (new Lambertian(*this));
}	


// ---------------------------------------------------------------------- destructor

Lambertian::~Lambertian(void) {}


// ---------------------------------------------------------------------- assignment operator
Lambertian& Lambertian::operator= (const Lambertian& rhs) {
	if (this == &rhs)
		return (*this);
		
	BRDF::operator= (rhs);
	
	kd = rhs.kd; 
	cd = rhs.cd;
	
	return (*this);
}

RGBColor Lambertian::f(const ShadeRec& sr) const {
	//return (kd * cd * invPI);
	return (kd * cd);
}

// ---------------------------------------------------------------------- f
RGBColor Lambertian::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	//RGBColor L;
	//double ndotwi = sr.normal * wi;	// wi is the light direction

	//if (ndotwi > 0.0)
		//L = kd * cd * ndotwi;
		//L = kd * cd  * invPI * ndotwi;

	//return (kd * cd  * invPI);
	return (kd * cd);
}

// ---------------------------------------------------------------------- rho
RGBColor Lambertian::rho(const ShadeRec& sr) const {
	return (kd * cd);
}

// ---------------------------------------------------------------------- rho
RGBColor Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (kd * cd);
}


