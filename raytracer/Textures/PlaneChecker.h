#ifndef __PLANE_CHECKER__
#define __PLANE_CHECKER__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Texture.h"
#include "RGBColor.h"

// For checkers that are approximately square at the "equator" (polar angle theta = 90 degrees), there should be
// twice as many horizontal_checkers as vertical_checkers
//-----------------------------------------------------------------------------------class SphereChecker
class PlaneChecker: public Texture {		
	public:
		PlaneChecker(void);										
		PlaneChecker(const PlaneChecker& sc);
		PlaneChecker& operator= (const PlaneChecker& rhs);
		virtual Texture* clone(void) const;				

		~PlaneChecker(void);

		virtual RGBColor get_color(const ShadeRec& sr) const;

		void set_size(const double s);
		void set_outline_width(const double w);
		void set_outline_color(const RGBColor& c);

		void set_color1(const double r, const double g, const double b);
		void set_color1(const double c);
		void set_color1(const RGBColor& c);
		
		void set_color2(const double r, const double g, const double b);
		void set_color2(const double c);	
		void set_color2(const RGBColor& c);									
		
	private:
		double		size;			// checker size
		double		outline_width;	// outline width
		RGBColor	outline_color;	// outline color
		RGBColor	color1;			// checker color 1
		RGBColor	color2;			// checker color 2						
};


// ---------------------------------------------------------------------------------------------------
inline void PlaneChecker::set_size(const double s) {
	size = s;
}

inline void PlaneChecker::set_outline_width(const double w) {
	outline_width = w;
}

inline void PlaneChecker::set_outline_color(const RGBColor& c) {
	outline_color = c;
}

inline void PlaneChecker::set_color1(const double r, const double g, const double b) {
	color1.r = r; color1.g = g; color1.b = b;
}

inline void PlaneChecker::set_color1(const double c) {
	color1.r = c; color1.g = c; color1.b = c;
}

inline void PlaneChecker::set_color1(const RGBColor& c) {
	color1.r = c.r; color1.g = c.g; color1.b = c.b;
}

inline void PlaneChecker::set_color2(const double r, const double g, const double b) {
	color2.r = r; color2.g = g; color2.b = b;
}

inline void PlaneChecker::set_color2(const double c) {
	color2.r = c; color2.g = c; color2.b = c;
}

inline void PlaneChecker::set_color2(const RGBColor& c) {
color2.r = c.r; color2.g = c.g; color2.b = c.b;
}											

#endif