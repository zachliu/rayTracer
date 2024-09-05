#include "Transparent.h"
#include "Maths.h"

// ---------------------------------------------------------------- default constructor
Transparent::Transparent()
	:	Matte(),
		reflective_brdf(new PerfectSpecular),
		specular_btdf(new PerfectTransmitter)
{}

// ---------------------------------------------------------------- copy constructor
Transparent::Transparent(const Transparent& tm)
	: 	Matte(tm) {
	
	if(tm.reflective_brdf)
		reflective_brdf = tm.reflective_brdf->clone(); 
	else  
		reflective_brdf = NULL;

	if(tm.specular_btdf)
		specular_btdf = tm.specular_btdf->clone(); 
	else  
		specular_btdf = NULL;
}

// ---------------------------------------------------------------- assignment operator
Transparent& Transparent::operator= (const Transparent& rhs) {
	if (this == &rhs)
		return (*this);
		
	Matte::operator=(rhs);
	
	if (reflective_brdf) {
		delete reflective_brdf;
		reflective_brdf = NULL;
	}
	if (rhs.reflective_brdf)
		reflective_brdf = rhs.reflective_brdf->clone();

	if (specular_btdf) {
		delete specular_btdf;
		specular_btdf = NULL;
	}
	if (rhs.specular_btdf)
		specular_btdf = rhs.specular_btdf->clone();

	return (*this);
}


// ---------------------------------------------------------------- clone
Transparent* Transparent::clone(void) const {
	return (new Transparent(*this));
}

// ---------------------------------------------------------------- destructor
Transparent::~Transparent()
{}

// ------------------------------------------------------------------------------------ shade 
RGBColor Transparent::shade(ShadeRec& sr) {
	RGBColor L(Matte::shade(sr));

	Vector3D wo = -sr.ray.d;	// wo is the inverse eye ray direction 
	Vector3D wi;
	RGBColor fr = reflective_brdf->sample_f(sr,wo,wi);
	Ray reflected_ray(sr.hit_point,wi);

	if(specular_btdf->tir(sr))	// if total internal reflection
		L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth + 1);
	else {
		Vector3D wt;
		RGBColor ft = specular_btdf->sample_f(sr,wo,wt);
		Ray transmitted_ray(sr.hit_point,wt);

		//L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray,sr.depth+1) * std::abs(sr.normal * wi);
		L += fr * sr.w.tracer_ptr->trace_ray(reflected_ray, sr.depth+1);
		L += ft * sr.w.tracer_ptr->trace_ray(transmitted_ray, sr.depth+1) * std::abs(sr.normal * wi);
		//L += ft * sr.w.tracer_ptr->trace_ray(transmitted_ray, sr.depth+1);
	}

	return L;
}