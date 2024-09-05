#ifndef __SAMPLER__
#define __SAMPLER__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include <vector>

#include "Point2D.h"
#include "Point3D.h"
#include "Maths.h"

class Sampler {	
    public:
        Sampler(void);
        Sampler(const int num);
        Sampler(const int num, const int num_sets);
        Sampler(const int num, const double fdiff);
        Sampler(const Sampler& s);
        Sampler& operator= (const Sampler& rhs);
        virtual Sampler* clone(void) const = 0;
        virtual ~Sampler(void);

        void set_num_sets(const int np);
        virtual void generate_samples(void) = 0;	// generate sample patterns in a unit square
        bool test_tolerance( const RGBColor* L );
        int get_num_samples(void);
        double get_min_size(void);
        double get_min_fdiff(void);
        void set_ray_color( const double m, const double n, const RGBColor& L );
        void set_ray_flag( const double m, const double n );
        RGBColor get_ray_color( const double m, const double n );
        int get_ray_flag( const double m, const double n );
        void zero_ray( void );
        int get_N(void);

        void shuffle_x_coordinates(void);
        void shuffle_y_coordinates(void);
        void setup_shuffled_indices(void);
        void map_samples_to_unit_disk(void);
        void map_samples_to_hemisphere(const double p);
        void map_samples_to_sphere(void);

        // the following functions are not const because they change count and jump
        Point2D sample_unit_square(void);	// get next sample on unit square
        Point2D sample_unit_disk(void);		// get next sample on unit disk
        Point3D sample_hemisphere(void);	// get next sample on unit hemisphere
        Point3D sample_sphere(void);		// get next sample on unit sphere
        Point2D sample_one_set(void);		// only used to set up a vector noise table
                                                // this is not discussed in the book, but see the
                                                // file LatticeNoise.cpp in Chapter 31

    protected:
        int 			num_samples;     	// the number of sample points in a set
        int 			num_sets;		// the number of sample sets
        std::vector<Point2D>	samples;		// sample points on a unit square
        std::vector<int>	shuffled_indices;	// shuffled samples array indices
        std::vector<Point2D>	disk_samples;		// sample points on a unit disk
        std::vector<Point3D> 	hemisphere_samples;	// sample points on a unit hemisphere
        std::vector<Point3D> 	sphere_samples;		// sample points on a unit sphere
        unsigned long 		count;			// the current number of sample points used
        int 			jump;			// random index jump
        int 			sub_division_level;	// 
        double			minimum_size;		//
        double			tolerance;		//
        int			N;			// 
        std::vector<int>	ray_flag;
        std::vector<RGBColor>	ray_color;
};

// ------------------------------------------------------------------- get_N
inline int Sampler::get_N(void) {
	return (N);
}

// ------------------------------------------------------------------- get_num_samples
inline int Sampler::get_num_samples(void) {
	return (num_samples);
}

// ------------------------------------------------------------------- get_min_size
inline double Sampler::get_min_size(void) {
	return (minimum_size);
}

// ------------------------------------------------------------------- get_min_size
inline double Sampler::get_min_fdiff(void) {
	return (tolerance);
}

// ------------------------------------------------------------------- set_ray_color
inline void Sampler::set_ray_color(const double m, const double n, const RGBColor& L) {
	ray_color[(int)((N-1)*m*N) + (int)((N-1)*n)] = L;
}

// ------------------------------------------------------------------- set_ray_flag
inline void Sampler::set_ray_flag(const double m, const double n) {
	ray_flag[(int)((N-1)*m*N) + (int)((N-1)*n)] = 1;
}

// ------------------------------------------------------------------- get_ray_color
inline RGBColor Sampler::get_ray_color(const double m, const double n) {
	return( ray_color[(int)((N-1)*m*N) + (int)((N-1)*n)] );
}

// ------------------------------------------------------------------- get_ray_flag
inline int Sampler::get_ray_flag(const double m, const double n) {
	return( ray_flag[(int)((N-1)*m*N) + (int)((N-1)*n)] );
}

// ------------------------------------------------------------------- zero_ray_color
inline void Sampler::zero_ray(void) {
	for (int i = 0; i<N*N; i ++) {
		ray_color[i] = RGBColor(0,0,0);
		ray_flag[i] = 0;
	}
}

// ------------------------------------------------------------------- test_tolerance
inline bool Sampler::test_tolerance( const RGBColor* L ) {

    double diff1 = L[0].Luminance() - L[1].Luminance();
    double diff2 = L[1].Luminance() - L[2].Luminance();
    double diff3 = L[2].Luminance() - L[3].Luminance();
    double diff4 = L[3].Luminance() - L[0].Luminance();
	//double diff5 = L[0].Luminance() - L[2].Luminance();
	//double diff6 = L[1].Luminance() - L[3].Luminance();
    double averageDiff = abs(diff1) + abs(diff2) + abs(diff3) + abs(diff4);// + abs(diff5) + abs(diff6);
    averageDiff = averageDiff / 4;

	if (averageDiff < tolerance)
		return (false);
	else
		return (true);
};

#endif

