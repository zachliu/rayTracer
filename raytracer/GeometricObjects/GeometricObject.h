#ifndef __GEOMETRIC_OBJECT__
#define __GEOMETRIC_OBJECT__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "Constants.h"
#include "BBox.h"
#include "RGBColor.h"
#include "Point3D.h"
#include "Vector3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Maths.h"

class Material;	

//----------------------------------------------------------------------------------------------------- class GeometricObject

class GeometricObject {	
    public:	

        GeometricObject(void);									

        GeometricObject(const GeometricObject& object);			

        virtual GeometricObject* clone(void) const = 0;

        virtual ~GeometricObject(void);	

        virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;	
        virtual bool shadow_hit(const Ray& ray, double& tmin) const;
        
        // This needs to be virtual so that it can be overridden in Compound
        virtual void set_material(Material* mPtr); // It therefore shouldn't be inlined

        Material* get_material(void) const;


        // The following three functions are only required for Chapter 3
        //void set_color(const RGBColor& c);	
        //void set_color(const double r, const double g, const double b);
        //RGBColor get_color(void);

        virtual void set_bounding_box(void);

        virtual BBox get_bounding_box(void);

        virtual void add_object(GeometricObject* object_ptr);   // required for compound objects


        // The following two functions are only required for objects that are light sources, eg disks, rectangles, and spheres
        virtual Point3D sample(void);

        virtual double pdf(ShadeRec& sr); 

        // The following two functions allow us to simplify the code for smooth shaded triangle meshes
        virtual Normal get_normal(void) const; 

        virtual Normal get_normal(const Point3D& p); 

        void set_shadows(bool b);

        bool casts_shadows();

    protected:

        mutable Material*   material_ptr;   	// mutable allows the const functions Compound::hit, Instance::hit, and RegularGrid::hit to assign to material_ptr
        RGBColor            color;		// only used for Bare Bones ray tracing

        GeometricObject& operator= (const GeometricObject& rhs);
        bool                shadows;
};


//// --------------------------------------------------------------------  set_color
//inline void GeometricObject::set_color(const RGBColor& c) {
//	color = c;
//}
//
//// --------------------------------------------------------------------  set_color
//inline void GeometricObject::set_color(const double r, const double g, const double b) {
//	color.r = r;
//	color.b = b;
//	color.g = g;
//}
//
//// --------------------------------------------------------------------  get_color
//inline RGBColor GeometricObject::get_color(void) {
//      return (color);
//}

#endif
