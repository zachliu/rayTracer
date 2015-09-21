#ifndef __CONSTANTS__
#define __CONSTANTS__


// 	Copyright (C) Kevin Suffern 2000-2007.
//	This C++ code is for non-commercial purposes only.
//	This C++ code is licensed under the GNU General Public License Version 2.
//	See the file COPYING.txt for the full license.


#include <stdlib.h>             // for RAND_MAX
#include "RGBColor.h"

const double 	PI 		= 3.1415926535897932384;
const double 	TWO_PI 		= 6.2831853071795864769;
const double 	PI_ON_180 	= 0.0174532925199432957;
const double 	invPI 		= 0.3183098861837906715;
const double 	invTWO_PI 	= 0.1591549430918953358;

const double 	kEpsilon 	= 0.0001; 
const double	kHugeValue	= 1.0E10;

const RGBColor	black(0.0);			// black
const RGBColor	white(1.0);			//white
const RGBColor	red(1.0, 0.0, 0.0);		// red
const RGBColor	yellow(1, 1, 0);		// yellow
const RGBColor	brown(0.71, 0.40, 0.16);	// brown
const RGBColor	darkGreen(0.0, 0.41, 0.41);	// darkGreen
const RGBColor	orange(1, 0.75, 0);		// orange
const RGBColor	green(0, 0.6, 0.3);		// green
const RGBColor	lightGreen(0.65, 1, 0.30);	// light green
const RGBColor	darkYellow(0.61, 0.61, 0);	// dark yellow
const RGBColor	lightPurple(0.65, 0.3, 1);	// light purple
const RGBColor	darkPurple(0.5, 0, 1);		// dark purple
const RGBColor	grey(0.25);			// grey

const double 	invRAND_MAX = 1.0 / (double)RAND_MAX;

const double	MAX_ADAPATIVE = 0.49;
const double	EPSILON = 10E-3;

#endif
