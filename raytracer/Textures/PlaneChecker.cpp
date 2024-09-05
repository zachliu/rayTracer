// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.
 
#include "Maths.h"
#include "PlaneChecker.h"

// ---------------------------------------------------------------- default constructor
PlaneChecker::PlaneChecker(void)
	:	Texture(),
		size(1.0),
		color1(white),
		color2(black)
{}

// ---------------------------------------------------------------- copy constructor
PlaneChecker::PlaneChecker(const PlaneChecker& sc)
	: 	Texture(sc),
		size(sc.size),
		color1(sc.color1),
		color2(sc.color2)
{}

// ---------------------------------------------------------------- assignment operator
PlaneChecker& PlaneChecker::operator= (const PlaneChecker& rhs) {
	if (this == &rhs)
		return (*this);
	
	Texture::operator=(rhs);
	
	size 	= rhs.size;
	color1	= rhs.color1;
	color2	= rhs.color2;

	return (*this);
}

// ---------------------------------------------------------------- clone
Texture* PlaneChecker::clone(void) const {
	return (new PlaneChecker(*this));
}	

// ---------------------------------------------------------------- destructor
PlaneChecker::~PlaneChecker(void) {}

// ---------------------------------------------------------------- get_color
RGBColor PlaneChecker::get_color(const ShadeRec& sr) const {

	double eps = 0.000187453738;	// small random number
	double x = sr.local_hit_point.x + eps;
	double y = sr.local_hit_point.y + eps;
	double z = sr.local_hit_point.z + eps;
	int ix = (int)floor( x / size );
	int iy = (int)floor( y / size );
	int iz = (int)floor( z / size );
	double fx = x / size - ix;
	double fy = y / size - iy;
	double fz = z / size - iz;
	double width = 0.5 * outline_width / size; 
	bool in_outline = (fx < width || fx > 1.0 - width) || (fz < width || fz > 1.0 - width) || (fy < width || fy > 1.0 - width) ;
	
	if ((ix + iy + iz) % 2 == 0) {
		if (!in_outline)	
			return (color1);
	}
	else {
		if (!in_outline)	
			return (color2);
	}
	
	return (outline_color);
}

	




