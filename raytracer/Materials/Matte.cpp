// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Matte.h"

// ---------------------------------------------------------------- default constructor
Matte::Matte (void)
	:	Material(),
		ambient_brdf(new Lambertian),
		diffuse_brdf(new Lambertian),
		specula_brdf(new GlossySpecular)
{}

// ---------------------------------------------------------------- copy constructor
Matte::Matte(const Matte& m) : Material(m)
{
	if(m.ambient_brdf)
		ambient_brdf = (Lambertian*)m.ambient_brdf->clone(); 
	else  ambient_brdf = NULL;
	
	if(m.diffuse_brdf)
		diffuse_brdf = (Lambertian*)m.diffuse_brdf->clone(); 
	else  diffuse_brdf = NULL;

	if(m.specula_brdf)
		specula_brdf = (GlossySpecular*)m.specula_brdf->clone(); 
	else  specula_brdf = NULL;
}

// ---------------------------------------------------------------- clone
Material* Matte::clone(void) const {
	return (new Matte(*this));
}	

// ---------------------------------------------------------------- assignment operator
Matte& Matte::operator= (const Matte& rhs) {
	if (this == &rhs)
		return (*this);
		
	Material::operator=(rhs);
	
	if (ambient_brdf) {
		delete ambient_brdf;
		ambient_brdf = NULL;
	}
	if (rhs.ambient_brdf)
		ambient_brdf = (Lambertian*)rhs.ambient_brdf->clone();
		
	if (diffuse_brdf) {
		delete diffuse_brdf;
		diffuse_brdf = NULL;
	}
	if (rhs.diffuse_brdf)
		diffuse_brdf = (Lambertian*)rhs.diffuse_brdf->clone();

	if (specula_brdf) {
		delete specula_brdf;
		specula_brdf = NULL;
	}
	if (rhs.specula_brdf)
		specula_brdf = (GlossySpecular*)rhs.specula_brdf->clone();

	return (*this);
}

// ---------------------------------------------------------------- destructor
Matte::~Matte(void) {

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
RGBColor Matte::shade(ShadeRec &sr) {
	Vector3D wo			= -sr.ray.d;	// wo is the inverse eye ray direction 
	RGBColor L			= ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);	// ambient light
	size_t num_lights	= sr.w.lights.size();

	for(size_t i = 0; i < num_lights; i++)
	{
		Vector3D wi = sr.w.lights[i]->get_direction(sr);	// wi is the light direction
		//wi.normalizeThis();
		double ndotwi = sr.normal * wi;
		if(ndotwi > 0.0)
		{
			bool in_shadow = false;

			if(sr.w.lights[i]->casts_shadows()) {
				Point3D new_hit_point = sr.hit_point + Vector3D(sr.normal * EPSILON);
				Ray shadowRay(new_hit_point,wi);
				//Ray shadowRay(sr.hit_point,wi);
				in_shadow = sr.w.lights[i]->in_shadow(shadowRay,sr);
			}

			if(!in_shadow)
				L += ( diffuse_brdf->f(sr,wo,wi) * ndotwi + specula_brdf->f(sr,wo,wi) ) * sr.w.lights[i]->L(sr);
		}
	}

	return L;
}

RGBColor Matte::area_light_shade(ShadeRec&	sr) {
	Vector3D wo = -sr.ray.d;
	RGBColor L = ambient_brdf->rho(sr,wo) * sr.w.ambient_ptr->L(sr);

	size_t num_lights = sr.w.lights.size();

	for(size_t i = 0; i < num_lights; i++ )
	{
		Vector3D wi = sr.w.lights[i]->get_direction(sr);
		double ndotwi = sr.normal * wi;
		if( ndotwi > 0.0 )
		{
			//bool in_shadow = false;

			//if(sr.w.lights[i]->casts_shadows()) {
			//	Ray shadow_ray(sr.hit_point,wi);
			//	in_shadow = sr.w.lights[i]->in_shadow(shadow_ray,sr);
			//}
			//if(!in_shadow)
			//	L += (diffuse_brdf->f(sr,wo,wi) + specula_brdf->f(sr,wo,wi)) * sr.w.lights[i]->L(sr) * sr.w.lights[i]->G(sr) * ndotwi / sr.w.lights[i]->pdf(sr);
		}
	}
	return L;
}


