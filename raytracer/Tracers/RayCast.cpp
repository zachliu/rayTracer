// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "RayCast.h"
#include "World.h"
#include "ShadeRec.h"
#include "Material.h"

// -------------------------------------------------------------------- default constructor

RayCast::RayCast(void)
	: Tracer()
{}


// -------------------------------------------------------------------- constructor
		
RayCast::RayCast(World* _worldPtr)
	: Tracer(_worldPtr)
{}


// -------------------------------------------------------------------- destructor

RayCast::~RayCast(void) {}


// -------------------------------------------------------------------- trace_ray
// this ignores the depth argument
RGBColor RayCast::trace_ray(const Ray ray, const int depth) const {
	if(depth > world_ptr->vp.max_depth)
		return RGBColor();
	else {
		ShadeRec sr( world_ptr->hit_objects(ray) );

		if (sr.hit_an_object) {
			sr.ray = ray;			// used for specular shading
			sr.depth = depth;		//
			return ( sr.material_ptr->shade(sr) );
		}   
		else
			return ( world_ptr->background_color );
	}
}


