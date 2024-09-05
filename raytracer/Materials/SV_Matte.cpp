// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "SV_Matte.h"

// ---------------------------------------------------------------- default constructor
SV_Matte::SV_Matte (void)
	:	Material(),
		ambient_brdf(new SV_Lambertian),
		diffuse_brdf(new SV_Lambertian),
		specula_brdf(new SV_GlossySpecular)
{}

// ---------------------------------------------------------------- copy constructor
SV_Matte::SV_Matte(const SV_Matte& m) : Material(m)
{
	if(m.ambient_brdf)
		ambient_brdf = (SV_Lambertian*)m.ambient_brdf->clone(); 
	else  ambient_brdf = NULL;
	
	if(m.diffuse_brdf)
		diffuse_brdf = (SV_Lambertian*)m.diffuse_brdf->clone(); 
	else  diffuse_brdf = NULL;

	if(m.specula_brdf)
		specula_brdf = (SV_GlossySpecular*)m.specula_brdf->clone(); 
	else  specula_brdf = NULL;
}

// ---------------------------------------------------------------- clone
Material* SV_Matte::clone(void) const {
	return (new SV_Matte(*this));
}	

// ---------------------------------------------------------------- assignment operator
SV_Matte& SV_Matte::operator= (const SV_Matte& rhs) {
	if (this == &rhs)
		return (*this);
		
	Material::operator=(rhs);
	
	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}
	if (rhs.ambient_brdf)
		ambient_brdf = (SV_Lambertian*)rhs.ambient_brdf->clone();
		
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}
	if (rhs.diffuse_brdf)
		diffuse_brdf = (SV_Lambertian*)rhs.diffuse_brdf->clone();

	if (specula_brdf) {
		delete specula_brdf;
		specula_brdf = NULL;
	}
	if (rhs.specula_brdf)
		specula_brdf = (SV_GlossySpecular*)rhs.specula_brdf->clone();

	return (*this);
}

// ---------------------------------------------------------------- destructor
SV_Matte::~SV_Matte(void) {

	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}
	
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}

	if (specula_brdf) {
		delete specula_brdf;
		specula_brdf = NULL;
	}
}

// ---------------------------------------------------------------- shade
RGBColor SV_Matte::shade(ShadeRec& sr)
{
	//Vector3D 	wo 			= -sr.ray.d;	// wo is the inverse eye ray direction 
	//RGBColor 	L 			= ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);	// ambient light
	//size_t 		num_lights	= sr.w.lights.size();
	//
	//for (size_t j = 0; j < num_lights; j++)
	//{
	//	Vector3D wi = sr.w.lights[j]->get_direction(sr);
	//	//wi.normalizeThis();
	//	double ndotwi = sr.normal * wi;
	//	if(ndotwi> 0.0)
	//		L += ( diffuse_brdf->f(sr, wo, wi) + specula_brdf->f(sr, wo, wi) ) * sr.w.lights[j]->L(sr) * ndotwi;	// diffuse and specular
	//}
	//
	//return (L);

	Vector3D wo = -sr.ray.d;
	RGBColor L = ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);	// ambient light

	size_t numLights = sr.w.lights.size();

	for(size_t j = 0;j < numLights;j++) {
		Vector3D wi = sr.w.lights[j]->get_direction(sr);
		//wi.normalizeThis();
		double ndotwi = sr.normal * wi;

		if(ndotwi> 0.0) {
			bool in_shadow = false;
			
			if(sr.w.lights[j]->casts_shadows()) {
				Point3D new_hit_point = sr.hit_point + Vector3D(sr.normal * EPSILON);
				Ray shadowRay(new_hit_point,wi);
				//Ray shadowRay(sr.hit_point,wi);
				in_shadow = sr.w.lights[j]->in_shadow(shadowRay,sr);
			}
			
			if(!in_shadow)
				L += ( diffuse_brdf->f(sr,wo,wi) * ndotwi + specula_brdf->f(sr, wo, wi) ) * sr.w.lights[j]->L(sr);
		}
	}

	return L;
}