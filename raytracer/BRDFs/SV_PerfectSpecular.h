#ifndef __SV_PERFECT_SPECULAR__
#define __SV_PERFECT_SPECULAR__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// this implements perfect specular reflection for indirect illumination
// with reflective materials 

#include "BRDF.h"
#include "Texture.h"

class SV_PerfectSpecular: public BRDF 
{
    public:
        SV_PerfectSpecular(void);
        SV_PerfectSpecular(const SV_PerfectSpecular& perf);
        virtual SV_PerfectSpecular* clone(void) const;
        ~SV_PerfectSpecular(void);

        void set_kr(const double k);
        void set_cr(Texture* t_ptr);

        virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
        virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
        virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, double& pdf) const;
        virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;

    private:
        double		kr;			// reflection coefficient
        Texture* 	cr;			// the reflection color
};


// -------------------------------------------------------------- set_kr

inline void
SV_PerfectSpecular::set_kr(const double k) {
    kr = k;
}


// -------------------------------------------------------------- set_cr
inline void SV_PerfectSpecular::set_cr(Texture* t_ptr) {
    cr = t_ptr;
}


#endif

