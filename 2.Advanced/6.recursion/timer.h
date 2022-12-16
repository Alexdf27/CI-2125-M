///
/// vsl_timer.h
///

#pragma once

#include <ctime>

class Timer {
public:
	Timer()
  : start_(clock())
  {}

	inline double restart()	{
		double result = double(clock() - start_)/double(CLOCKS_PER_SEC);
		start_ = clock();
		return result;
	}

	inline double elapsed() {
		return double(clock() - start_)/double(CLOCKS_PER_SEC);
	}

private:
	clock_t start_;
};
