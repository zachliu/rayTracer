//header guard at start of header file
#ifndef Timer_H
#define Timer_H

#ifdef __MACH__
#include <mach/mach_time.h>
#define MY_TIMER_CONST 1000000000
#else
#include <ctime>
#endif

long int Current_Clock();

//End guard at bottom of header file
#endif