#include "profile.h"

LogDuration::~LogDuration() {
	auto finish = std::chrono::steady_clock::now();
	auto dur = finish - start;
	std::cerr << message
			<< std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
			<< " ms" << std::endl;
}
