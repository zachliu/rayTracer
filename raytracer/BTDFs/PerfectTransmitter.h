#ifndef __PERFECT_TRANSMITTER__
#define __PERFECT_TRANSMITTER__

#include "BTDF.h"

class PerfectTransmitter:public BTDF {
    public:
        PerfectTransmitter();
        virtual PerfectTransmitter* clone(void) const;
        ~PerfectTransmitter();

        virtual RGBColor f(const ShadeRec& sr,const Vector3D& wt,const Vector3D& wo)const;
        virtual RGBColor sample_f(const ShadeRec& sr,const Vector3D& wo,Vector3D& wt)const;
        virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wt, double& pdf) const;
        virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo)const ;
        virtual bool tir(const ShadeRec& sr)const;
        void set_kt(const double t);
        void set_ior(const double i);
        void set_ct(const RGBColor& c);
        void set_ct(const double r, const double g, const double b);
        void set_ct(const double c);

    protected:
        double		kt;
        double		ior;
        RGBColor 	ct;			// the specular transmissive color of object
};

// -------------------------------------------------------------- set_kt
inline void PerfectTransmitter::set_kt(const double t) {
    kt = t;
}

// -------------------------------------------------------------- set_ior
inline void PerfectTransmitter::set_ior(const double i) {
    ior = i;
}

// -------------------------------------------------------------- set_ct
inline void PerfectTransmitter::set_ct(const RGBColor& c) {
    ct = c;
}

// ---------------------------------------------------------------- set_ct
inline void PerfectTransmitter::set_ct(const double r, const double g, const double b) {
    ct.r = r; ct.g = g; ct.b = b;
}

// ---------------------------------------------------------------- set_ct
inline void	PerfectTransmitter::set_ct(const double c) {
    ct.r = c; ct.g = c; ct.b = c;
}

#endif