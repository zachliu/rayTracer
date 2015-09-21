#ifndef __SV_REFLECTIVE__
#define __SV_REFLECTIVE__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "SV_Matte.h"
#include "SV_PerfectSpecular.h"

class SV_Reflective: public SV_Matte {	
	public:
		SV_Reflective(void);
		SV_Reflective(const SV_Reflective& rm);
		SV_Reflective& operator= (const SV_Reflective& rhs);
		virtual SV_Reflective* clone(void) const;
		~SV_Reflective(void);										
		
		void set_kr(const double k);
		void set_cr(Texture* t_ptr);

		virtual RGBColor shade(ShadeRec& s);
		
	private:
		SV_PerfectSpecular*		reflective_brdf;		
};


// ---------------------------------------------------------------- set_kr
inline void SV_Reflective::set_kr(const double k) {
	reflective_brdf->set_kr(k);
}


// ---------------------------------------------------------------- set_cr
inline void SV_Reflective::set_cr(Texture* t_ptr) {
	reflective_brdf->set_cr(t_ptr);	
}


#endif
