// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include <Maths.h>

#include "GlossySpecular.h"
//#include "MultiJittered.h"
#include "Constants.h"

// ---------------------------------------------------------------------- default constructor

GlossySpecular::GlossySpecular(void) 
	: 	ks(0.0), 
		cs(1.0),
		exp(1.0)//,
		//sampler(NULL)
{}

// ---------------------------------------------------------------------- destructor
GlossySpecular::~GlossySpecular(void) {}

// ---------------------------------------------------------------------- clone
GlossySpecular* GlossySpecular::clone (void) const {
	return (new GlossySpecular(*this));
}

// ---------------------------------------------------------------------- set_sampler
// this allows any type of sampling to be specified in the build functions
//void GlossySpecular::set_sampler(Sampler* sp, const double exp) {
//	sampler_ptr = sp;
//	sampler_ptr->map_samples_to_hemisphere(exp);
//}

// ---------------------------------------------------------------------- set_samples
// this sets up multi-jittered sampling using the number of samples
//void GlossySpecular::set_samples(const int num_samples, const double exp) {
//	sampler_ptr = new MultiJittered(num_samples);
//	sampler_ptr->map_samples_to_hemisphere(exp);
//}

RGBColor GlossySpecular::f(const ShadeRec& sr) const {
	return (black);
}

// ----------------------------------------------------------------------------------- f
// no sampling here: just use the Phong formula or Hall formula
// this is used for direct illumination only
RGBColor GlossySpecular::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
	RGBColor	L;
	double		ndotwi = sr.normal * wi;						// wi is the light direction
	Vector3D	r(-wi +  2.0  * ndotwi * sr.normal);
	double 		rdotwo = r.normalize() * wo;					// wo is the inverse eye ray direction 
	Vector3D	H = wo + wi;
	H.normalizeThis();
	double		ndoth = sr.normal * H;
	//if (rdotwo > 0.0)
	//	L = ks * cs * std::pow(rdotwo, exp);

	L = ks * cs * std::pow(ndoth, exp);

	return (L);
}

// ----------------------------------------------------------------------------------- sample_f
// this is used for indirect illumination
RGBColor GlossySpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, double& pdf) const {
	
	//double ndotwo = sr.normal * wo;
	//Vector3D r = -wo + 2.0 * sr.normal * ndotwo;     // direction of mirror reflection
	//
	//Vector3D w = r;								
	//Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w; 
	//u.normalize();
	//Vector3D v = u ^ w;
	//	
	//Point3D sp = sampler_ptr->sample_hemisphere();
	//wi = sp.x * u + sp.y * v + sp.z * w;			// reflected ray direction
	//
	//if (sr.normal * wi < 0.0) 						// reflected ray is below tangent plane
	//	wi = -sp.x * u - sp.y * v + sp.z * w;

	//double phong_lobe = pow(r * wi, exp);
	//pdf = phong_lobe * (sr.normal * wi);

	//return (ks * cs * phong_lobe);
	return (black);
}

// ----------------------------------------------------------------------------------- rho
RGBColor GlossySpecular::rho(const ShadeRec& sr) const {
	return (black);
}

// ----------------------------------------------------------------------------------- rho
RGBColor GlossySpecular::rho(const ShadeRec& sr, const Vector3D& wo) const {
	return (black);
}

