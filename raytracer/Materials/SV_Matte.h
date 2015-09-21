#ifndef __SV_MATTE__
#define __SV_MATTE__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Material.h"
#include "SV_Lambertian.h"
#include "SV_GlossySpecular.h"

//----------------------------------------------------------------------------- class SV_Matte

class SV_Matte: public Material {	
	public:
		SV_Matte(void);
		SV_Matte(const SV_Matte& m);
		virtual Material* clone(void) const;
		SV_Matte& operator= (const SV_Matte& rhs);
		~SV_Matte(void);

		void set_ka(const double k);
		void set_kd(const double k);
		void set_ks(const double k);
		void set_cd(Texture* t_ptr);
		void set_cs(Texture* t_ptr);
		void set_exp(const double exp);

		virtual RGBColor shade(ShadeRec& sr);
		//virtual RGBColor area_light_shade(ShadeRec& sr);
		//virtual RGBColor path_shade(ShadeRec& sr);
		//virtual RGBColor global_shade(ShadeRec&	sr);

	private:
		SV_Lambertian*		ambient_brdf;
		SV_Lambertian*		diffuse_brdf;
		SV_GlossySpecular*	specula_brdf;
};

// ---------------------------------------------------------------- set_cd
inline void	SV_Matte::set_cd(Texture* t_ptr) {
	ambient_brdf->set_cd(t_ptr);
	diffuse_brdf->set_cd(t_ptr);
}

// ---------------------------------------------------------------- set_cs
inline void	SV_Matte::set_cs(Texture* t_ptr) {
	specula_brdf->set_cs(t_ptr);
}

// ---------------------------------------------------------------- set_ka
// this sets Lambertian::kd
// there is no Lambertian::ka data member because ambient reflection 
// is diffuse reflection
inline void	SV_Matte::set_ka(const double ka) {
	ambient_brdf->set_kd(ka);
}

// ---------------------------------------------------------------- set_kd
// this also sets Lambertian::kd, but for a different Lambertian object
inline void	SV_Matte::set_kd (const double kd) {
	diffuse_brdf->set_kd(kd);
}

// ---------------------------------------------------------------- set_ks
// this also sets Lambertian::kd, but for a different Lambertian object
inline void	SV_Matte::set_ks (const double ks) {
	specula_brdf->set_ks(ks);
}

// -------------------------------------------------------------- set_exp
inline void SV_Matte::set_exp(const double e) {
	specula_brdf->set_exp(e);
}

#endif
