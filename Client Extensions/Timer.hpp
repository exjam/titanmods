#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <TRose\IT_MGR.h>
#include <TRose\DrawImpl.h>
#include <TRose\Game.h>

class Timer {
public:
	Timer();
	~Timer();

	void SetDuration(long seconds);
	long GetDuration();
	long GetRemaining();
	void Start();
	void Stop();
	void Start(int seconds);
	void Draw();

public:
	clock_t mStartTime;
	long mDuration;
};

//extern Timer* UwTimer;

#endif