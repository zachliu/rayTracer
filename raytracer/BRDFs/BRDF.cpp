// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Constants.h"
#include "BRDF.h"

// ---------------------------------------------------------- default constructor
BRDF::BRDF(void) {}

// ---------------------------------------------------------- copy constructor
BRDF::BRDF (const BRDF& brdf) {}	

// --------------------------------------------------------------- assignment operator
BRDF&														
BRDF::operator= (const BRDF& rhs) {
	if (this == &rhs)
		return (*this);

	return (*this);
}

// ---------------------------------------------------------- destructor
BRDF::~BRDF(void) {}  




// ------------------------------------------------------------------------ f
RGBColor
BRDF::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

RGBColor
BRDF::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const {
	return (black);
}


// ------------------------------------------------------------------------ sample_f

RGBColor
BRDF::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, double& pdf) const {
	return (black);
}


// ------------------------------------------------------------------------ rho	
	
RGBColor
BRDF::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (black);
}

