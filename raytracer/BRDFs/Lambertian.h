#ifndef __LAMBERTIAN__
#define __LAMBERTIAN__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This implements a perfect diffuse scatterer

#include "BRDF.h"

class Lambertian: public BRDF {
    public:
        Lambertian(void);
        Lambertian(const Lambertian& lamb);
        virtual BRDF* clone(void) const;
        ~Lambertian(void);
        Lambertian& operator= (const Lambertian& rhs);

        virtual RGBColor f(const ShadeRec& sr) const;
        virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
        virtual RGBColor rho(const ShadeRec& sr) const;
        virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
        void set_ka(const double ka);
        void set_kd(const double kd);
        void set_cd(const RGBColor& c);
        void set_cd(const double r, const double g, const double b);
        void set_cd(const double c);

    private:
        double	 kd;
        RGBColor cd;
};

// -------------------------------------------------------------- set_ka
inline void Lambertian::set_ka(const double k) {
    kd = k;
}

// -------------------------------------------------------------- set_kd
inline void Lambertian::set_kd(const double k) {
    kd = k;
}

// -------------------------------------------------------------- set_cd
inline void Lambertian::set_cd(const RGBColor& c) {
    cd = c;
}

// ---------------------------------------------------------------- set_cd
inline void Lambertian::set_cd(const double r, const double g, const double b) {
    cd.r = r; cd.g = g; cd.b = b;
}

// ---------------------------------------------------------------- set_cd
inline void Lambertian::set_cd(const double c) {
    cd.r = c; cd.g = c; cd.b = c;
}

#endif
