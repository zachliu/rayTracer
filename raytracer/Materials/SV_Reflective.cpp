// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "SV_Reflective.h"

// ---------------------------------------------------------------- default constructor

SV_Reflective::SV_Reflective (void)
	:	SV_Matte(),
		reflective_brdf(new SV_PerfectSpecular)
{}


// ---------------------------------------------------------------- copy constructor

SV_Reflective::SV_Reflective(const SV_Reflective& rm)
	: 	SV_Matte(rm) {
	
	if(rm.reflective_brdf)
		reflective_brdf = rm.reflective_brdf->clone(); 
	else  
		reflective_brdf = NULL;
}


// ---------------------------------------------------------------- assignment operator

SV_Reflective& 
SV_Reflective::operator= (const SV_Reflective& rhs) {
	if (this == &rhs)
		return (*this);
		
	SV_Matte::operator=(rhs);
	
	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}

	if (rhs.reflective_brdf)
		reflective_brdf = rhs.reflective_brdf->clone();

	return (*this);
}


// ---------------------------------------------------------------- clone

SV_Reflective*										
SV_Reflective::clone(void) const {
	return (new SV_Reflective(*this));
}	


// ---------------------------------------------------------------- destructor
SV_Reflective::~SV_Reflective(void) {}


// ------------------------------------------------------------------------------------ shade 
RGBColor SV_Reflective::shade(ShadeRec& sr) {	
	RGBColor L(SV_Matte::shade(sr));  // direct illumination

	// make the new_hit_point "higher" than original hit_point in the normal direction
	// this is to avoid round off error
	Point3D new_hit_point = sr.hit_point + Vector3D(sr.normal * EPSILON);

	Vector3D wo = -sr.ray.d;
	Vector3D r;
	RGBColor fr = reflective_brdf->sample_f(sr, wo, r); 
	Ray reflected_ray(new_hit_point, r);
	//Ray reflected_ray(sr.hit_point, r);

	//reflected_ray.depth = sr.depth + 1;

	double ndotwi = sr.normal * r;
	//if(ndotwi > 0.0) {
		//L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1) * ndotwi;
		L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1);
	//}
	return (L);
}



