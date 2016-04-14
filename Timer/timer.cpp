#include "timer.h"


#include <sstream>
#include <iostream>

Timer::Timer(){
	mElapsed_time	= 0.0;
	mTime_start		= 0.0;
	mTime_end		= 0.0;
}

Timer::~Timer(){}

//initialize timer(set the elapsed time to 0)
void Timer::Init(){
	mElapsed_time = 0.0;
	mTime_start = 0.0;
	mTime_end = 0.0;
}

//start the timer(also set the elapsed time to 0)
void Timer::Start(){
	mTime_end = mTime_start = GetTickCount();
	mElapsed_time = 0.0;
}

//Restart the tiemr(do not reset the elapsed time)
void Timer::ReStart(){
	mTime_end = mTime_start = GetTickCount();
}

//stop the timer 
void Timer::Stop(){
	mTime_end = GetTickCount();
	//since when restart we also add the original time
	mElapsed_time += (mTime_end - mTime_start)/1e3;

	if (mTime_end < mTime_start){
		std::cerr << " error: mTime_end is smaller than mTime_start. timer.cpp line 39" << std::endl;
	}
}

//get the elapsed time in seconds 
double Timer::GetElapsedTime(){
	return mElapsed_time;
}

//get the elapsed time in seconds in a string
std::string Timer::GetElapsedTimeAsString(){
	// parse elapsed time into string stream
	std::ostringstream s;

	// get the elapsed minutes and seconds
	double elapsed_minutes = (mElapsed_time < 60) ? 0.0 : floor(mElapsed_time / 60);
	double elapsed_seconds = mElapsed_time - floor(mElapsed_time / 60) * 60;
	s << elapsed_minutes << " minutes " << elapsed_seconds << " seconds ";
	return s.str();
}