// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "SV_Lambertian.h"
#include "Constants.h"

// ---------------------------------------------------------------------- default constructor
SV_Lambertian::SV_Lambertian(void) 
	:   BRDF(),
		kd(0.0), 
		cd()
{}


// ---------------------------------------------------------------------- copy constructor
SV_Lambertian::SV_Lambertian(const SV_Lambertian& lamb) 
	:   BRDF(lamb),
            kd(lamb.kd), 
            cd(lamb.cd) {
	if(lamb.cd)
		cd = (Texture*)lamb.cd->clone(); 
	else  cd = NULL;
}


// ---------------------------------------------------------------------- clone
BRDF* SV_Lambertian::clone(void) const {
	return (new SV_Lambertian(*this));
}	


// ---------------------------------------------------------------------- destructor
SV_Lambertian::~SV_Lambertian(void) {}


// ---------------------------------------------------------------------- assignment operator
SV_Lambertian& SV_Lambertian::operator= (const SV_Lambertian& rhs) {
	if (this == &rhs)
		return (*this);
		
	BRDF::operator= (rhs);
	
	kd = rhs.kd; 
	cd = rhs.cd;
	
	return (*this);
}


// ---------------------------------------------------------------------- f
RGBColor SV_Lambertian::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	//RGBColor L;
	//double ndotwi = sr.normal * wi;	// wi is the light direction

	//if (ndotwi > 0.0)
	//	L = kd * cd->get_color(sr) * ndotwi;
	//	//L = kd * cd->get_color(sr)  * invPI * ndotwi;

	//return ( kd * cd->get_color(sr) * invPI );
	return ( kd * cd->get_color(sr) );
}


// ---------------------------------------------------------------------- rho
RGBColor SV_Lambertian::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return ( kd * cd->get_color(sr) );
}


// ---------------------------------------------------------------------- f
RGBColor SV_Lambertian::sample_f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	return (black);
}