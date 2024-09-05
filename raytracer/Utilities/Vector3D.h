#ifndef __VECTOR_3D__
#define __VECTOR_3D__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include "Matrix.h"

class Normal;
class Point3D;

//----------------------------------------- class Vector3D

class Vector3D {
	public:
	
		double	x, y, z;

	public:
	
		Vector3D(void);											// default constructor
		Vector3D(double a);										// constructor
		Vector3D(double _x, double _y, double _z);				// constructor
		Vector3D(const Vector3D& v);							// copy constructor
		Vector3D(const Normal& n);								// constructs a vector from a Normal
		Vector3D(const Point3D& p);								// constructs a vector from a point
		Vector3D( const Point3D& StartP, const Point3D& EndP );	// constructs a vector from two points

		~Vector3D (void);										// destructor

		Vector3D& operator= (const Vector3D& rhs);				// assignment operator
		Vector3D& operator= (const Normal& rhs);				// assign a Normal to a vector
		Vector3D& operator= (const Point3D& rhs);				// assign a Point3D to a vector
		Vector3D operator- (void) const;						// unary minus
				
		double length(void);									// length
		
		double len_squared(void);								// square of the length
		Vector3D operator* (const double a) const;				// multiplication by a double on the right
		Vector3D operator/ (const double a) const;				// division by a double
		Vector3D operator+ (const Vector3D& v) const;			// addition
		Vector3D& operator+= (const Vector3D& v);				// compound addition
		Vector3D operator- (const Vector3D& v) const;			// subtraction
		double operator* (const Vector3D& b) const;				// dot product
		Vector3D operator^ (const Vector3D& v) const;			// cross product		

		Vector3D normalize() const;
		void normalizeThis(void); 								// convert vector to a unit vector
		
		Vector3D& 												// return a unit vector, and normalize the vector												
		hat(void);
};


// inlined member functions

// ------------------------------------------------------------------------ unary minus
// this does not change the current vector
// this allows ShadeRec objects to be declared as constant arguments in many shading
// functions that reverse the direction of a ray that's stored in the ShadeRec object

inline Vector3D 
Vector3D::operator- (void) const {
	return (Vector3D(-x, -y, -z));    
}


// ---------------------------------------------------------------------  len_squared
// the square of the length
inline double Vector3D::len_squared(void) {	
	return (x * x + y * y + z * z);
}


// ----------------------------------------------------------------------- operator*
// multiplication by a double on the right
inline Vector3D Vector3D::operator* (const double a) const {	
	return (Vector3D(x * a, y * a, z * a));	
}

// ----------------------------------------------------------------------- operator/
// division by a double
inline Vector3D Vector3D::operator/ (const double a) const {	
	return (Vector3D(x / a, y / a, z / a));	
}


// ----------------------------------------------------------------------- operator+
// addition
inline Vector3D Vector3D::operator+ (const Vector3D& v) const {
	return (Vector3D(x + v.x, y + v.y, z + v.z));
}


// ----------------------------------------------------------------------- operator-
// subtraction
inline Vector3D Vector3D::operator- (const Vector3D& v) const {
	return (Vector3D(x - v.x, y - v.y, z - v.z));
}


// ----------------------------------------------------------------------- operator*
// dot product
inline double Vector3D::operator* (const Vector3D& v) const {
	return (x * v.x + y * v.y + z * v.z);
} 


// ----------------------------------------------------------------------- operator^
// cross product
inline Vector3D Vector3D::operator^ (const Vector3D& v) const {
	return (Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}


// ---------------------------------------------------------------------  operator+=
// compound addition
inline Vector3D& Vector3D::operator+= (const Vector3D& v) {
	x += v.x; y += v.y; z += v.z;
	return (*this);
}


// inlined non-member function

// ----------------------------------------------------------------------- operator*
// multiplication by a double on the left
Vector3D operator* (const double a, const Vector3D& v);	// prototype

inline Vector3D  operator* (const double a, const Vector3D& v) {
	return (Vector3D(a * v.x, a * v.y, a * v.z));	
}


// non-inlined non-member function

// ----------------------------------------------------------------------- operator* 
// multiplication by a matrix on the left
Vector3D operator* (const Matrix& mat, const Vector3D& v);	// prototype


#endif



