#ifndef __SV_GLOSSY_SPECULAR__
#define __SV_GLOSSY_SPECULAR__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// this implements glossy specular reflection for direct and indirect illumination

#include "BRDF.h"
#include "Texture.h"

class SV_GlossySpecular: public BRDF {
    public:
        SV_GlossySpecular(void);
        ~SV_GlossySpecular(void);
        virtual SV_GlossySpecular* clone(void) const;

        virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
        virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, double& pdf) const;
        virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
        void set_cs(Texture* t_ptr);
        void set_ks(const double ks);
        void set_exp(const double exp);
        //void set_sampler(Sampler* sp, const double exp);   			// any type of sampling
        //void set_samples(const int num_samples, const double exp); 	// multi jittered sampling
        void set_normal(const Normal& n);

    private:
        double		ks;			// (specular) surface reflectance coefficient
        Texture* 	cs;			// specular color
        double		exp; 		// specular exponent (shininess)
        //Sampler*	sampler;    // for use in sample_f
};

// -------------------------------------------------------------- set_cs
inline void SV_GlossySpecular::set_cs(Texture* t_ptr) {
    cs = t_ptr;
}

// -------------------------------------------------------------- set_ks
inline void SV_GlossySpecular::set_ks(const double k) {
    ks = k;
}

// -------------------------------------------------------------- set_exp
inline void SV_GlossySpecular::set_exp(const double e) {
    exp = e;
}

#endif

