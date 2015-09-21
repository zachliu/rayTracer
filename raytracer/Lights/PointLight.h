#ifndef __POINTLIGHT__
#define __POINTLIGHT__

#include "Light.h"
//#include "Vector3D.h"
#include "Point3D.h"
#include "RGBColor.h"

#include "World.h"			// you will need this later on for shadows
#include "ShadeRec.h"


class PointLight: public Light {
	public:	
		PointLight(void);
		PointLight(const PointLight& pl);
		
		virtual Light* clone(void) const;

		PointLight& operator= (const PointLight& rhs); 
			
		virtual	~PointLight(void);

		void set_point(const Point3D& rLightPoint);
		void set_intensity(const double b);
		
		void set_color(const double c);
		void set_color(const RGBColor& c);
		void set_color(const double r, const double g, const double b); 		
					
		virtual Vector3D get_direction( ShadeRec& sr );
		virtual RGBColor L(ShadeRec& sr);	
		virtual bool in_shadow(const Ray& ray,const ShadeRec& sr) const;

	private:

		double		mIntensity;			
		RGBColor	color;
		Point3D		mLightPoint;
};


// inlined access functions

// ------------------------------------------------------------------------------- set_point
inline void PointLight::set_point(const Point3D& rLightPoint) {
	mLightPoint = rLightPoint;
}

// ------------------------------------------------------------------------------- scale_radiance
inline void PointLight::set_intensity(const double b) { 
	mIntensity = b;
}

// ------------------------------------------------------------------------------- set_color
inline void PointLight::set_color(const double c) {
	color.r = c; color.g = c; color.b = c;
}

// ------------------------------------------------------------------------------- set_color
inline void PointLight::set_color(const RGBColor& c) {
	color = c;
}

// ------------------------------------------------------------------------------- set_color
inline void PointLight::set_color(const double r, const double g, const double b) {
	color.r = r; color.g = g; color.b = b;
}


#endif
