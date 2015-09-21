#ifndef __PINHOLE__
#define __PINHOLE__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This file contains the declaration of the class Pinhole

#include "Point2D.h"
#include "World.h"    // we can #include "World.h" here

//--------------------------------------------------------------------- class Pinhole

class Pinhole: public Camera {
    public:

        Pinhole();   							

        Pinhole(const Pinhole& ph);	

        virtual Camera*						
        clone(void) const;			

        Pinhole& 							
        operator= (const Pinhole& rhs);	

        virtual
        ~Pinhole();   						

        void set_view_distance(const double vpd);
        void set_zoom(const double zoom_factor);
        Vector3D get_direction(const Point2D& p) const;
        virtual void render_scene(const World& w);
        virtual RGBColor non_adaptiveSS( const World& w, const ViewPlane& vp, Ray& ray, int i, int j, int depth );
        virtual RGBColor adaptiveSS( const World& w, const ViewPlane& vp, Ray& ray, double i, double j, int depth, double size );

        //int**			ray_flag;				// nxn array for counting rays per pixel
        //RGBColor**		ray_color;		

    private:
        double	d;			// view plane distance
        double	zoom;		// zoom factor
        double	rpp;
        int	x, y;
};




//-------------------------------------------------------------------------- set_vpd

inline void
Pinhole::set_view_distance(double _d) {
    d = _d;
}	
	


//-------------------------------------------------------------------------- set_zoom

inline void
Pinhole::set_zoom(double zoom_factor) {
    zoom = zoom_factor;
}	

#endif

