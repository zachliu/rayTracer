#ifndef __MATTE__
#define __MATTE__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Material.h"
#include "Lambertian.h"
#include "GlossySpecular.h"

//----------------------------------------------------------------------------- class Matte

class Matte: public Material {	
	public:
		Matte(void);
		Matte(const Matte& m);
		virtual Material* clone(void) const;
		Matte& operator= (const Matte& rhs);
		~Matte(void);											
		
		void set_ka(const double k);
		void set_kd(const double k);
		void set_ks(const double k);
		void set_cd(const RGBColor c);
		void set_cd(const double r, const double g, const double b);
		void set_cd(const double c);
		void set_cs(const RGBColor& c);
		void set_cs(const double r, const double g, const double b);
		void set_cs(const double c);
		void set_exp(const double exp);

		virtual RGBColor shade(ShadeRec& sr);
		virtual RGBColor area_light_shade(ShadeRec& sr);

	private:
		Lambertian*		ambient_brdf;
		Lambertian*		diffuse_brdf;
		GlossySpecular*	specula_brdf;
};

// ---------------------------------------------------------------- set_ka
// this sets Lambertian::kd
// there is no Lambertian::ka data member because ambient reflection 
// is diffuse reflection
inline void	Matte::set_ka(const double ka) {
	ambient_brdf->set_kd(ka);
}

// ---------------------------------------------------------------- set_kd
// this also sets Lambertian::kd, but for a different Lambertian object
inline void	Matte::set_kd (const double kd) {
	diffuse_brdf->set_kd(kd);
}

// ---------------------------------------------------------------- set_cd
inline void Matte::set_cd(const RGBColor c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

// ---------------------------------------------------------------- set_cd
inline void Matte::set_cd(const double r, const double g, const double b) {
	ambient_brdf->set_cd(r, g, b);
	diffuse_brdf->set_cd(r, g, b);
}

// ---------------------------------------------------------------- set_cd
inline void	Matte::set_cd(const double c) {
	ambient_brdf->set_cd(c);
	diffuse_brdf->set_cd(c);
}

// ---------------------------------------------------------------- set_kr
// this also sets Lambertian::kd, but for a different Lambertian object
inline void	Matte::set_ks (const double kr) {
	specula_brdf->set_ks(kr);
}

// -------------------------------------------------------------- set_exp
inline void Matte::set_exp(const double e) {
	specula_brdf->set_exp(e);
}

// -------------------------------------------------------------- set_cs
inline void Matte::set_cs(const RGBColor& c) {
	specula_brdf->set_cs(c);
}

// ---------------------------------------------------------------- set_cs
inline void Matte::set_cs(const double r, const double g, const double b) {
	specula_brdf->set_cs(r, g, b);
}

// ---------------------------------------------------------------- set_cs
inline void Matte::set_cs(const double c) {
	specula_brdf->set_cs(c);
}

#endif
