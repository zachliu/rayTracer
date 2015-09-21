#include "PointLight.h"

// ---------------------------------------------------------------------- default constructor
PointLight::PointLight(void)
	: 	Light(),
		mIntensity(1.0),
		color(1.0),
		mLightPoint(3, 3, 0)
{}

// ---------------------------------------------------------------------- dopy constructor
PointLight::PointLight(const PointLight& pl)
	: 	Light(pl),
		mIntensity(pl.mIntensity),
		color(pl.color),
		mLightPoint(pl.mLightPoint)  		
{}

// ---------------------------------------------------------------------- clone
Light* PointLight::clone(void) const {
	return ( new PointLight(*this) );
}

// ---------------------------------------------------------------------- assignment operator
PointLight& PointLight::operator= (const PointLight& rhs) 	
{
	if (this == &rhs)
		return (*this);
			
	Light::operator= (rhs);
	
	mIntensity  = rhs.mIntensity;
	color 	    = rhs.color;
	mLightPoint = rhs.mLightPoint;

	return (*this);
}


// ---------------------------------------------------------------------- destructor
PointLight::~PointLight(void) {}


// ---------------------------------------------------------------------- get_direction
// as this function is virtual, it shouldn't be inlined 
Vector3D PointLight::get_direction( ShadeRec& sr ) {
	return ( Vector3D( sr.hit_point, mLightPoint ).normalize() );
}	

// ------------------------------------------------------------------------------  L
RGBColor PointLight::L(ShadeRec& s) {	
	return ( mIntensity * color );
}

// ------------------------------------------------------------------------------  in_shadow
bool PointLight::in_shadow(const Ray &ray, const ShadeRec &sr) const {
	double t;
	size_t num_objects = sr.w.objects.size();
	double d = mLightPoint.distance(ray.o);

	bool in_shadow = false;

	for(size_t j = 0; j < num_objects; j++) {
		if(sr.w.objects[j]->casts_shadows()) {	
			if(sr.w.objects[j]->shadow_hit(ray,t) && t < d) {
				in_shadow = true;
			}
		}		
	}
	return in_shadow;
}