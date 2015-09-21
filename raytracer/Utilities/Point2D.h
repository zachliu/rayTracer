#ifndef __POINT_2D__
#define __POINT_2D__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


// 2D points are used to store sample points

class Point2D {	
	public:
	
		double x, y;
				
	public:
	
		Point2D(void);										
		Point2D(const double arg);							
		Point2D(const double x1, const double y1);			
		Point2D(const Point2D& p); 						
		~Point2D(void);									

		Point2D& 											
		operator= (const Point2D& rhs);
		
		Point2D							
		operator* (const double a);
};


// multiplication by a double on the right

inline Point2D
Point2D::operator* (const double a) {
	return (Point2D(x * a, y * a));
}

#endif


