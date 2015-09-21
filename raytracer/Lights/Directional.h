#ifndef __DIRECTIONAL__
#define __DIRECTIONAL__

#include "Light.h"
#include "Vector3D.h"
#include "RGBColor.h"

#include "World.h"			// you will need this later on for shadows
#include "ShadeRec.h"


class Directional: public Light {
	public:
	
		Directional(void);   							

		Directional(const Directional& dl); 
		
		virtual Light* clone(void) const;			

		Directional& 									
		operator= (const Directional& rhs); 
			
		virtual											
		~Directional(void); 
				
		void
		scale_radiance(const double b);
		
		void
		set_color(const double c);
		
		void
		set_color(const RGBColor& c);
		
		void
		set_color(const double r, const double g, const double b); 		
			
		void
		set_direction(Vector3D d);						
		
		void
		set_direction(double dx, double dy, double dz);
		
		virtual Vector3D								
		get_direction(ShadeRec& sr);
				
		virtual RGBColor		
		L(ShadeRec& sr);	

		virtual bool in_shadow(const Ray& ray,const ShadeRec& sr) const;

	private:

		double		ls;			
		RGBColor	color;
		Vector3D	dir;		// direction the light comes from
};


// inlined access functions


// ------------------------------------------------------------------------------- scale_radiance

inline void
Directional::scale_radiance(const double b) { 
	ls = b;
}

// ------------------------------------------------------------------------------- set_color

inline void
Directional::set_color(const double c) {
	color.r = c; color.g = c; color.b = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
Directional::set_color(const RGBColor& c) {
	color = c;
}


// ------------------------------------------------------------------------------- set_color

inline void
Directional::set_color(const double r, const double g, const double b) {
	color.r = r; color.g = g; color.b = b;
}


// ---------------------------------------------------------------------- set_direction

inline void
Directional::set_direction(Vector3D d) {
	dir = d;
	dir.normalizeThis();
}


// ---------------------------------------------------------------------- set_direction 

inline void
Directional::set_direction(double dx, double dy, double dz) {
	dir.x = dx; dir.y = dy; dir.z = dz;
	dir.normalizeThis();
}


#endif
