#ifndef __CHECKER3D__
#define __CHECKER3D__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Texture.h"
#include "RGBColor.h"

// For checkers that are approximately square at the "equator" (polar angle theta = 90 degrees), there should be
// twice as many horizontal_checkers as vertical_checkers

//-----------------------------------------------------------------------------------class SphereChecker

class Checker3D: public Texture {		
	public:
		Checker3D(void);										
		Checker3D(const Checker3D& sc);
		Checker3D& operator= (const Checker3D& rhs);
		virtual Texture* clone(void) const;				

		~Checker3D(void);

		virtual RGBColor get_color(const ShadeRec& sr) const;

		void set_size(const double s);

		void set_color1(const double r, const double g, const double b);
		void set_color1(const double c);
		void set_color1(const RGBColor& c);
		
		void set_color2(const double r, const double g, const double b);
		void set_color2(const double c);	
		void set_color2(const RGBColor& c);									
		
	private:
		double		size;		// checker size
		RGBColor	color1;		// checker color 1
		RGBColor	color2;		// checker color 2								
};


// ---------------------------------------------------------------------------------------------------
inline void Checker3D::set_size(const double s) {
	size = s;
}

inline void Checker3D::set_color1(const double r, const double g, const double b) {
	color1.r = r; color1.g = g; color1.b = b;
}

inline void Checker3D::set_color1(const double c) {
	color1.r = c; color1.g = c; color1.b = c;
}

inline void Checker3D::set_color1(const RGBColor& c) {
	color1.r = c.r; color1.g = c.g; color1.b = c.b;
}

inline void Checker3D::set_color2(const double r, const double g, const double b) {
	color2.r = r; color2.g = g; color2.b = b;
}

inline void Checker3D::set_color2(const double c) {
	color2.r = c; color2.g = c; color2.b = c;
}

inline void Checker3D::set_color2(const RGBColor& c) {
color2.r = c.r; color2.g = c.g; color2.b = c.b;
}											

#endif