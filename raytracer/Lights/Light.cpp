#include "Light.h"

#include "Constants.h"

// ---------------------------------------------------------------------- default constructor

Light::Light(void) {}

// ---------------------------------------------------------------------- dopy constructor

Light::Light(const Light& ls) {}


// ---------------------------------------------------------------------- assignment operator

Light& 
Light::operator= (const Light& rhs) {
	if (this == &rhs)
		return (*this);

	return (*this);
}


// ---------------------------------------------------------------------- destructor

Light::~Light(void) {} 



// ---------------------------------------------------------------------- L
// returns the radiance
RGBColor Light::L(ShadeRec& s) {
	return (black);
}

// ---------------------------------------------------------------------- casts_shadows
bool Light::casts_shadows() {
	return shadows;
}

// ----------------------------------------------------------------------set_shadows
void Light::set_shadows(bool b) {
	shadows = b;
}

// ---------------------------------------------------------------------- in_shadow
bool Light::in_shadow(const Ray &ray, const ShadeRec &sr) const {
	return (false);
}