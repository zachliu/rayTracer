#ifndef __CAMERA__
#define __CAMERA__

// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// This file contains the declaration of the base class Camera
// There is no view plane distance because the fisheye and panoramic cameras don't use it

#include "Point3D.h"
#include "Vector3D.h"

class World;  // can't #include "World" here because World contains a camera pointer

//--------------------------------------------------------------------- class Camera

class Camera {
    public:

        Camera();   							// default constructor

        Camera(const Camera& camera);			// copy constructor

        virtual Camera*	clone(void) const = 0;	// virtual copy constructor

        virtual ~Camera();

        virtual void render_scene(const World& w) = 0;

        void set_eye(const Point3D& p);
        void set_eye(const double x, const double y, const double z);
        void set_lookat(const Point3D& p);
        void set_lookat(const double x, const double y, const double z);
        void set_up_vector(const Vector3D& u);
        void set_up_vector(const double x, const double y, const double z);
        void set_roll(const double ra);
        void set_exposure_time(const double exposure);
        void compute_uvw(void);

    protected:		

        Point3D			eye;				// eye point
        Point3D			lookat; 			// lookat point
        double			ra;					// roll angle
        Vector3D		u, v, w;			// orthonormal basis vectors
        Vector3D		up;					// up vector
        double			exposure_time;

        Camera& operator= (const Camera& camera);	// assignment operator
};


// inlined access functions

// ----------------------------------------------------------------- set_eye
inline void Camera::set_eye(const Point3D& p) {
    eye = p;
}


// ----------------------------------------------------------------- set_eye
inline void Camera::set_eye(const double x, const double y, const double z) {
    eye.x = x; eye.y = y; eye.z = z;
}


// ----------------------------------------------------------------- set_lookat
inline void Camera::set_lookat(const Point3D& p) {
    lookat = p;
}


// ----------------------------------------------------------------- set_lookat
inline void Camera::set_lookat(const double x, const double y, const double z) {
    lookat.x = x; lookat.y = y; lookat.z = z;
}


// ----------------------------------------------------------------- set_up_vector
inline void Camera::set_up_vector(const Vector3D& u) {
    up = u;
}


// ----------------------------------------------------------------- set_up_vector
inline void Camera::set_up_vector(const double x, const double y, const double z) {
    up.x = x; up.y = y; up.z = z;
}


// ----------------------------------------------------------------- set_roll
inline void Camera::set_roll(const double r) { 
    ra = r;
}


// ----------------------------------------------------------------- set_exposure_time
inline void Camera::set_exposure_time(const double exposure) {
    exposure_time = exposure;
}


#endif
