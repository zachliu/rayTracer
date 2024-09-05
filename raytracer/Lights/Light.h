#ifndef __LIGHT__
#define __LIGHT__

#include "Vector3D.h"
#include "RGBColor.h"
#include "Ray.h"

class ShadeRec;


//-------------------------------------------------------------------- class Light

class Light {	
	public:
		Light(void);					
		Light(const Light& ls);
		Light& operator= (const Light& rhs);
		virtual Light* clone(void) const = 0;
		virtual ~Light(void);
						
		virtual Vector3D get_direction(ShadeRec& sr) = 0;													
		virtual RGBColor L(ShadeRec& sr);	
		virtual bool in_shadow(const Ray& ray,const ShadeRec& sr) const;
		bool casts_shadows();
		void set_shadows(bool b);

	protected:
		bool shadows;
};

#endif