#ifndef __ADAPTIVE__
#define __ADAPTIVE__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "Sampler.h"

class Adaptive: public Sampler {

	public:
		Adaptive(void);
		Adaptive(const int num, const double fdiff);
		Adaptive(const Adaptive& u);
		Adaptive& operator= (const Adaptive& rhs);
		virtual Adaptive* clone(void) const;
		virtual ~Adaptive(void);
		virtual void generate_samples(void);
		//bool test_tolerance( const RGBColor* L );

		//int**			ray_flag;				// nxn array for counting rays per pixel
		//RGBColor**		ray_color;
		//int		sub_division_level;
		//double	adap_MAX;					
		//int		N;
};

//inline bool Adaptive::test_tolerance( const RGBColor* L ) {
//	if ( abs( L[2].r - L[3].r ) > tolerance && 
//		 abs( L[0].r - L[2].r ) > tolerance && 
//		 abs( L[0].r - L[1].r ) > tolerance && 
//		 abs( L[1].r - L[3].r ) > tolerance &&
//		 abs( L[0].r - L[3].r ) > tolerance &&
//		 abs( L[1].r - L[2].r ) > tolerance ) {
//		return (true);
//	}
//	else {
//		return (false);
//	}
//};

#endif