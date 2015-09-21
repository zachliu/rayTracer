#ifndef __TRANSPARENT__
#define __TRANSPARENT__

#include "Matte.h"
#include "PerfectTransmitter.h"
#include "PerfectSpecular.h"

class Transparent: public Matte {
	public:
		Transparent(void);
		Transparent(const Transparent& tm);
		Transparent& operator= (const Transparent& rhs);
		virtual Transparent* clone(void) const;
		~Transparent(void);

		void set_kr(const double k);
		void set_kt(const double k);
		void set_ior(const double i);
		void set_ct(const RGBColor& c);
		void set_ct(const double r, const double g, const double b);
		void set_ct(const double c);
		void set_cr(const RGBColor& c);
		void set_cr(const double r, const double g, const double b);
		void set_cr(const double c);
		virtual RGBColor shade(ShadeRec& sr);

	private:
		PerfectSpecular*	reflective_brdf;
		PerfectTransmitter*	specular_btdf;

};

// -------------------------------------------------------------- set_kr
inline void Transparent::set_kr(const double k) {
	reflective_brdf->set_kr(k);
}

// -------------------------------------------------------------- set_kt
inline void Transparent::set_kt(const double k) {
	specular_btdf->set_kt(k);
}

// -------------------------------------------------------------- set_ior
inline void Transparent::set_ior(const double i) {
	specular_btdf->set_ior(i);
}

// -------------------------------------------------------------- set_ct
inline void Transparent::set_ct(const RGBColor& c) {
	specular_btdf->set_ct(c);
}

// ---------------------------------------------------------------- set_ct
inline void Transparent::set_ct(const double r, const double g, const double b) {
	specular_btdf->set_ct(r, g, b);
}

// ---------------------------------------------------------------- set_ct
inline void	Transparent::set_ct(const double c) {
	specular_btdf->set_ct(c);
}

// -------------------------------------------------------------- set_cr
inline void Transparent::set_cr(const RGBColor& c) {
	reflective_brdf->set_cr(c);
}

// ---------------------------------------------------------------- set_cr
inline void Transparent::set_cr(const double r, const double g, const double b) {
	reflective_brdf->set_cr(r, g, b);
}

// ---------------------------------------------------------------- set_cr
inline void	Transparent::set_cr(const double c) {
	reflective_brdf->set_cr(c);
}
#endif