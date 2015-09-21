#include "Timer.h"

long int Current_Clock() {
	#ifdef __MACH__ // OS X does not have clock_gettime, use clock_get_time
		/* Get the timebase info */
		mach_timebase_info_data_t info;
		mach_timebase_info(&info);

		uint64_t t_now = mach_absolute_time();

		/* Convert to nanoseconds */
		t_now *= info.numer;
		t_now /= info.denom;

		return t_now;
	#else
		return std::clock();
	#endif
}