// This file contains the definition the ViewPlane class

#include "ViewPlane.h"
	
// ---------------------------------------------------------------- default constructor	
						
ViewPlane::ViewPlane(void)							
    : 	hres(400), 
        vres(400),
        hs(1.0),
        vs(1.0),
        adap_sampler(false),
        num_samples(1),
        sampler_ptr(),
        max_depth(0),
        gamma(1.0),
        inv_gamma(1.0),
        show_out_of_gamut(false)
{}


// ---------------------------------------------------------------- copy constructor

ViewPlane::ViewPlane(const ViewPlane& vp)   
    :  	hres(vp.hres),  
        vres(vp.vres), 
        hs(vp.hs),
        vs(vp.vs),
        adap_sampler(vp.adap_sampler),
        num_samples(vp.sampler_ptr->get_num_samples()),
        sampler_ptr(vp.sampler_ptr),
        max_depth(vp.max_depth),
        gamma(vp.gamma),
        inv_gamma(vp.inv_gamma),
        show_out_of_gamut(vp.show_out_of_gamut)
{}


// ---------------------------------------------------------------- assignment operator

ViewPlane& 
ViewPlane::operator= (const ViewPlane& rhs) {
    if (this == &rhs)
        return (*this);
		
    hres 		= rhs.hres;
    vres 		= rhs.vres;
    hs			= rhs.hs;
    vs			= rhs.vs;
    adap_sampler	= rhs.adap_sampler;
    num_samples		= rhs.num_samples;
    sampler_ptr		= rhs.sampler_ptr;
    max_depth		= rhs.max_depth;
    gamma		= rhs.gamma;
    inv_gamma		= rhs.inv_gamma;
    show_out_of_gamut	= rhs.show_out_of_gamut;

    return (*this);
}


// -------------------------------------------------------------- destructor
ViewPlane::~ViewPlane(void) {}