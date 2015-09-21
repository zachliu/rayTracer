// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "SV_PerfectSpecular.h"
#include "Constants.h"
#include "Maths.h"

// ---------------------------------------------------------- default constructor

SV_PerfectSpecular::SV_PerfectSpecular(void)
	: 	BRDF(),
		kr(0.0), 
		cr()
{}

// ---------------------------------------------------------------------- copy constructor
SV_PerfectSpecular::SV_PerfectSpecular(const SV_PerfectSpecular& perf) 
	:   BRDF(perf),
		kr(perf.kr), 
		cr(perf.cr) {
	if(perf.cr)
		cr = (Texture*)perf.cr->clone(); 
	else  cr = NULL;
}

// ---------------------------------------------------------------------- clone
SV_PerfectSpecular* SV_PerfectSpecular::clone(void) const {
	return (new SV_PerfectSpecular(*this));
}

// ---------------------------------------------------------- destructor
SV_PerfectSpecular::~SV_PerfectSpecular(void) {}

// ---------------------------------------------------------- f
RGBColor
SV_PerfectSpecular::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	return (black);
}


// ---------------------------------------------------------- sample_f
// this computes wi: the direction of perfect mirror reflection
// it's called from from the functions Reflective::shade and Transparent::shade.
// the abs in the last statement is for transparency
RGBColor SV_PerfectSpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const {
	double ndotwo = sr.normal * wo;
	wi = -wo + 2.0 * sr.normal * ndotwo;		// calculate the reflected ray
	return (kr * cr->get_color(sr));
	//return (kr * cr / std::abs(sr.normal * wi)); // why is this abs? // kr would be a Fresnel term in a Fresnel reflector
}											 // for transparency when ray hits inside surface?, if so it should go in Chapter 24


// ---------------------------------------------------------- sample_f
// this version of sample_f is used with path tracing
// it returns ndotwi in the pdf
RGBColor SV_PerfectSpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, double& pdf) const {
	double ndotwo = sr.normal * wo;
	wi = -wo + 2.0 * sr.normal * ndotwo; 
	pdf = std::abs(sr.normal * wi);
	return (kr * cr->get_color(sr));  
}

// ---------------------------------------------------------- rho

RGBColor
SV_PerfectSpecular::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (black);
}

