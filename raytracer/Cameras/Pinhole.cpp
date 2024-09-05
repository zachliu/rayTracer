// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.

// This file contains the definition of the Pinhole class
#include "Constants.h" 
#include "Point3D.h"
#include "Vector3D.h"
#include "Pinhole.h"
#include "RGBColor.h"

// ----------------------------------------------------------------------------- default constructor
Pinhole::Pinhole(void) : Camera(), d(500), zoom(1.0)
{}

// ----------------------------------------------------------------------------- copy constructor
Pinhole::Pinhole(const Pinhole& c) : Camera(c), d(c.d), zoom(c.zoom)
{}

// ----------------------------------------------------------------------------- clone
Camera* Pinhole::clone(void) const {
	return ( new Pinhole(*this) );
}

// ----------------------------------------------------------------------------- assignment operator
Pinhole& Pinhole::operator= (const Pinhole& rhs) { 	
	if (this == &rhs)
		return (*this);
		
	Camera::operator= (rhs);

	d 		= rhs.d;
	zoom	= rhs.zoom;

	return (*this);
}

// ----------------------------------------------------------------------------- destructor
Pinhole::~Pinhole(void) {}	

// ----------------------------------------------------------------------------- get_direction
Vector3D Pinhole::get_direction( const Point2D& p ) const {
	Vector3D dir = p.x * u + p.y * v - d * w;
	dir.normalizeThis();
	
	return(dir);
}

// ----------------------------------------------------------------------------- render_scene
void Pinhole::render_scene( const World& w ) {
	RGBColor	L;
	ViewPlane	vp(w.vp);	 								
	Ray			ray;
	int 		depth = 0;
	Point2D		sp;		// sample point in [0, 1] x [0, 1] 
	Point2D 	pp;		// sample point on a pixel
	int n = (int)sqrt((double)vp.sampler_ptr->get_num_samples());
	//int r, c, i, j;
	int r, c;
	rpp = 0;	// use for calculating ray per pixel	
	int loopTotal = (int)(vp.vres * vp.hres / 46.00);
	int loopCounter = 1;

	vp.hs /= zoom;
	vp.vs /= zoom;
	ray.o = eye;
	int max_N = vp.sampler_ptr->get_N()*vp.sampler_ptr->get_N() - 4;
	printf("|" );
	if (vp.adap_sampler) {
		for ( r = 0, y = vp.vres; r < vp.vres; y--, r++ ) {	// up (vres = height or y)
			for ( c = 0, x = 0; c < vp.hres; x++, c++ ) {	// across (hres = width or x)
				if ( loopCounter > loopTotal ) {
					printf("-" ); loopCounter = 1;
				}
				vp.sampler_ptr->zero_ray();
				// adaptive super-sampler
				L = adaptiveSS( w, vp, ray, y, x, depth, .5 );
				L = w.set_color(r, c, L);
				w.buffer[3*c]   = (unsigned char)(L.r * 255);
				w.buffer[3*c+1] = (unsigned char)(L.g * 255);
				w.buffer[3*c+2] = (unsigned char)(L.b * 255);
				//if (rpp > 90)
				//	int shit = 1;
				w.rpp_int[3*c]   = (unsigned char)(((rpp-4) / max_N) * 255);
				w.rpp_int[3*c+1] = (unsigned char)(((rpp-4) / max_N) * 255);
				w.rpp_int[3*c+2] = (unsigned char)(((rpp-4) / max_N) * 255);
				loopCounter ++;
				rpp = 0;
			}
			w.myTIFFwrite( w.outfile, w.buffer, r );
			w.myTIFFwrite( w.outfile_int, w.rpp_int, r );
		}
	}
	else {
		for ( r = 0, y = vp.vres; r < vp.vres; y--, r++ ) {	// up (vres = height or y)
			for ( c = 0, x = 0; c < vp.hres; x++, c++ ) {	// across (hres = width or x)
				if ( loopCounter > loopTotal ) {
					printf("-" ); loopCounter = 1;
				}
				// non-adaptive super-samplers
				L = non_adaptiveSS( w, vp, ray, y, x, depth );
				L = w.set_color(r, c, L);
				w.buffer[3*c]   = (unsigned char)(L.r * 255);
				w.buffer[3*c+1] = (unsigned char)(L.g * 255);
				w.buffer[3*c+2] = (unsigned char)(L.b * 255);
				loopCounter ++;
			}
			w.myTIFFwrite( w.outfile, w.buffer, r );
		}
	}
	printf("|\n" );
}

// ----------------------------------------------------------------------------- non_adaptiveSS
RGBColor Pinhole::non_adaptiveSS( const World& w, const ViewPlane& vp, Ray& ray, int i, int j, int depth ) {
	RGBColor	L = black;
	Point2D		sp;		// sample point in [0, 1] x [0, 1] 
	Point2D 	pp;		// sample point on a pixel

	for (int k = 0; k < vp.sampler_ptr->get_num_samples(); k++) {	
		sp = vp.sampler_ptr->sample_unit_square();
		pp.x = vp.hs * (j - 0.5 * vp.hres + sp.x);
		pp.y = vp.vs * (i - 0.5 * vp.vres + sp.y);
		ray.d = get_direction( pp );
		L += w.tracer_ptr->trace_ray( ray, depth );        
	}
	L /= vp.sampler_ptr->get_num_samples();
	L *= exposure_time;
	return (L);
}

// ----------------------------------------------------------------------------- adaptiveSS
RGBColor Pinhole::adaptiveSS( const World& w, const ViewPlane& vp, Ray& ray, double i, double j, int depth, double size ) {
	double fHalfSize = 0.5 * size;
	Point2D 	pp;		// sample point on a pixel
	RGBColor	L;
	RGBColor*	Lc;
	RGBColor	LCenter;
	double		m, n;
    int			dx[4] = { -1, 1,  1, -1 };
    int			dy[4] = {  1, 1, -1, -1 };

	Lc = new RGBColor [4];

	for ( int k=0; k<4; k++ ) {
		m =   j - x + dx[k] * size + .5;
		n = -(i - y + dy[k] * size) + .5;
		if ( vp.sampler_ptr->get_ray_flag(m, n) == 0 ) {
			pp.x = vp.hs * (j - 0.5 * vp.hres + 0.5 + dx[k] * size);
			pp.y = vp.vs * (i - 0.5 * vp.vres + 0.5 + dy[k] * size);
			ray.d = get_direction( pp );
			Lc[k] = w.tracer_ptr->trace_ray( ray, depth );
			L += Lc[k];
			rpp = rpp + 1;
			vp.sampler_ptr->set_ray_flag(m, n);
			vp.sampler_ptr->set_ray_color(m, n, Lc[k]);
		}
		else {
			L += vp.sampler_ptr->get_ray_color(m, n);
		}
	}

	L /= 4;

	//if (size < MAX_ADAPATIVE)
	if ( size < vp.sampler_ptr->get_min_size() ) {
		return L;
	}

	//if ( fDiff > vp.sampler_ptr->get_min_fdiff() ) {
	if ( vp.sampler_ptr->test_tolerance( Lc ) ) {
		RGBColor newL;
		newL += adaptiveSS( w, vp, ray, i - fHalfSize, j + fHalfSize, depth, fHalfSize );
		newL += adaptiveSS( w, vp, ray, i + fHalfSize, j + fHalfSize, depth, fHalfSize );
		newL += adaptiveSS( w, vp, ray, i + fHalfSize, j - fHalfSize, depth, fHalfSize );
		newL += adaptiveSS( w, vp, ray, i - fHalfSize, j - fHalfSize, depth, fHalfSize );
		newL /= 4;
		return newL;
	}
	else {
		return L;
	}
}

//// ----------------------------------------------------------------------------- adaptiveSS
//RGBColor Pinhole::adaptiveSS( const World& w, const ViewPlane& vp, Ray& ray, double i, double j, int depth, double size ) {
//	double fHalfSize = 0.5 * size;
//	Point2D 	pp;		// sample point on a pixel
//	RGBColor	L;
//	RGBColor*	Lc;
//	RGBColor	LCenter;
//	double		m, n;
//    int			dx[4] = {0, 1, 0, 1};
//    int			dy[4] = {0, 0, 1, 1};
//
//	Lc = new RGBColor [4];
//
//	for ( int k=0; k<4; k++ ) {
//		m = j - x + dx[k] * size;
//		n = i - y + dy[k] * size;
//		if ( vp.sampler_ptr->get_ray_flag(m, n) == 0 ) {
//			pp.x = vp.hs * (j - 0.5 * vp.hres + 0.5 + dx[k] * size);
//			pp.y = vp.vs * (i - 0.5 * vp.vres + 0.5 + dy[k] * size);
//			ray.d = get_direction( pp );
//			Lc[k] = w.tracer_ptr->trace_ray( ray, depth );
//			L += Lc[k];
//			rpp = rpp + 1;
//			vp.sampler_ptr->set_ray_flag(m, n);
//			vp.sampler_ptr->set_ray_color(m, n, Lc[k]);
//		}
//		else {
//			L += vp.sampler_ptr->get_ray_color(m, n);
//		}
//	}
//
//	L /= 4;
//
//	//if (size < MAX_ADAPATIVE)
//	if ( size < vp.sampler_ptr->get_min_size() ) {
//		return L;
//	}
//
//	m = j + fHalfSize - x;
//	n = i + fHalfSize - y;
//	if ( vp.sampler_ptr->get_ray_flag(m, n) == 0 ) {
//		pp.x = vp.hs * (j - 0.5 * vp.hres + 0.5 + fHalfSize);
//		pp.y = vp.vs * (i - 0.5 * vp.vres + 0.5 + fHalfSize);
//		ray.d = get_direction( pp );
//		LCenter = w.tracer_ptr->trace_ray( ray, depth ); rpp = rpp + 1;
//		vp.sampler_ptr->set_ray_flag(m, n);
//		vp.sampler_ptr->set_ray_color(m, n, LCenter);
//	}
//	else {
//		LCenter += vp.sampler_ptr->get_ray_color(m, n);
//	}
//
//	double fDiff = L.GetSquaredColorDistance( LCenter );
//
//	//if ( fDiff > vp.sampler_ptr->get_min_fdiff() ) {
//	if ( vp.sampler_ptr->test_tolerance( Lc ) ) {
//		RGBColor newL;
//		newL += adaptiveSS( w, vp, ray, i,             j,             depth, fHalfSize );
//		newL += adaptiveSS( w, vp, ray, i + fHalfSize, j,             depth, fHalfSize );
//		newL += adaptiveSS( w, vp, ray, i,             j + fHalfSize, depth, fHalfSize );
//		newL += adaptiveSS( w, vp, ray, i + fHalfSize, j + fHalfSize, depth, fHalfSize );
//		newL /= 4;
//		return newL;
//	}
//	else {
//		return L;
//	}
//}