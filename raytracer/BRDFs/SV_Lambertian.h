
#ifndef __SV_LAMBERTIAN__
#define __SV_LAMBERTIAN__

#include "BRDF.h"
#include "Texture.h"

class SV_Lambertian: public BRDF
{
    public:
        SV_Lambertian(void);
        SV_Lambertian(const SV_Lambertian& lamb);
        virtual BRDF* clone(void) const;
        ~SV_Lambertian(void);
        SV_Lambertian& operator= (const SV_Lambertian& rhs);

        void set_cd(Texture* t_ptr);
        void set_ka(const double ka);
        void set_kd(const double kd);

        virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
        virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
        virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;

    private:
        double		kd;
        Texture*	cd;
};

// -------------------------------------------------------------- set_ka
inline void SV_Lambertian::set_cd(Texture* t_ptr) {
    cd = t_ptr;
}

// -------------------------------------------------------------- set_ka
inline void SV_Lambertian::set_ka(const double k) {
    kd = k;
}

// -------------------------------------------------------------- set_kd
inline void SV_Lambertian::set_kd(const double k) {
    kd = k;
}

#endif
