// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

#include "Adaptive.h"

// ---------------------------------------------------------------- default constructor
	
Adaptive::Adaptive(void) : Sampler()
{}


// ---------------------------------------------------------------- constructor

Adaptive::Adaptive(const int num, const double fdiff) : Sampler(num,fdiff) {
	generate_samples();
}


// ---------------------------------------------------------------- copy constructor

Adaptive::Adaptive(const Adaptive& u) : Sampler(u) {
	generate_samples();
}

// ---------------------------------------------------------------- assignment operator

Adaptive& 
Adaptive::operator= (const Adaptive& rhs) {
	if (this == &rhs)
		return (*this);
		
	Sampler::operator= (rhs);

	return (*this);
}

// ---------------------------------------------------------------- clone

Adaptive*										
Adaptive::clone(void) const {
	return (new Adaptive(*this));
}

// ---------------------------------------------------------------- destructor			

Adaptive::~Adaptive(void) {}


// ---------------------------------------------------------------- generate_samples
void Adaptive::generate_samples(void) {
	minimum_size = 1/pow(2,(double)sub_division_level) - kEpsilon;
	N = (int)pow(2,(double)sub_division_level) + 1;
	for (int i = 0; i<N*N; i ++) {
		ray_color.push_back(RGBColor(0,0,0));
		ray_flag.push_back(0);
	}
}
