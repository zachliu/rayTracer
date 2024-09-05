#include "PerfectTransmitter.h"
#include "Maths.h"

PerfectTransmitter::PerfectTransmitter()
	:	kt(1.0), 
		ior(1.0), 
		ct(1.0)
{}

// ---------------------------------------------------------------------- clone
PerfectTransmitter* PerfectTransmitter::clone(void) const {
	return (new PerfectTransmitter(*this));
}	

PerfectTransmitter::~PerfectTransmitter()
{}

bool PerfectTransmitter::tir(const ShadeRec &sr) const {
	Vector3D wo(-sr.ray.d);
	double cos_thetai = sr.normal * wo;
	double eta = ior;
	if(cos_thetai < 0.0)
		eta = 1.0 / eta;

	return (1.0 - (1.0 - cos_thetai * cos_thetai) /(eta * eta) < 0.0);
}

RGBColor PerfectTransmitter::f(const ShadeRec &sr, const Vector3D &wt, const Vector3D &wo) const {
	return RGBColor();
}

RGBColor PerfectTransmitter::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wt) const {
	Normal n(sr.normal);
	double cos_theta_i = n * wo;	// wo is the inverse eye ray direction 
	double eta = ior;
	
	if(cos_theta_i < 0.0) {
		cos_theta_i *= -1;
		n = -n;
		eta = 1.0 / eta;
	}

	double temp = 1.0 - (1.0 - cos_theta_i * cos_theta_i) / ( eta * eta );
	double cos_theta2 = sqrt(temp);
	wt = -wo / eta - (cos_theta2 - cos_theta_i / eta) * n;

	return ( kt / (eta * eta) * ct / std::abs(sr.normal * wt) );
}

RGBColor PerfectTransmitter::sample_f(const ShadeRec &sr, const Vector3D &wo, Vector3D &wt, double &pdf) const {
	return RGBColor();
}

RGBColor PerfectTransmitter::rho(const ShadeRec &sr, const Vector3D &wo) const {
	return RGBColor();
}