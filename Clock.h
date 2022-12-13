#pragma once
#ifndef CLOCK_H_
#define CLOCK_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Clock
{
private:
	struct tm* localTime;
	int d_hours;
	int d_mins;
	int d_secs;
	bool format_24;
public:
	Clock(bool format_24);
	void addHours(int hours);
	void addMinutes(int mins);
	void addSeconds(int secs);
	void resetClock();
	void displayTime(ostream& out);
};