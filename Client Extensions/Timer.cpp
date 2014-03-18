#include "main.h"
#include "Timer.hpp"

Timer* gUwTimer;

Timer::Timer(){ 
	mStartTime = clock();
	mDuration = 0;
}
Timer::~Timer() { }

void Timer::SetDuration(long seconds){
	mDuration = seconds * 1000;
}

long Timer::GetDuration(){
	return mDuration / 1000;
}

long Timer::GetRemaining(){
	return (mStartTime + mDuration) - clock();
}

void Timer::Start(){
	mStartTime = clock();
}

void Timer::Start(int seconds){
	mDuration = seconds * 1000;
	mStartTime = clock();
}

void Timer::Stop(){
	mDuration = 0;
}

void Timer::Draw(){
	long remaining = GetRemaining();
	if(remaining <= 0) return;

	int minutes = ((remaining / 1000) / 60) % 60;
	int seconds = (remaining / 1000) % 60;

	int timer = 690;
	int minutes1 = (minutes / 10);
	int minutes2 = (minutes % 10);
	int seconds1 = (seconds / 10);
	int seconds2 = (seconds % 10);

	int x = (getScreenHeight() / 2);
	int y = getScreenWidth() - 100;

	ResetTransform(0, 0);
	DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + minutes1, 0xFFFFFFFF);
	x += 16;

	ResetTransform(0, 0);
	DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + minutes2, 0xFFFFFFFF);
	x += 16;

	ResetTransform(0, 0);
	DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + 10, 0xFFFFFFFF);
	x += 9;

	ResetTransform(0, 0);
	DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + seconds1, 0xFFFFFFFF);
	x += 16;

	ResetTransform(0, 0);
	DrawImpl::Instance()->Draw2D(x, y, IMAGE_RES_UI, timer + seconds2, 0xFFFFFFFF);
}