
#include "Clock.h"

Clock::Clock(bool format_24)
{
	time_t seconds = time(0);
	localTime = localtime(&seconds);
	d_hours = 0;
	d_secs = 0;
	d_mins = 0;
	this->format_24 = format_24;
}

void Clock::addHours(int hours)
{
	d_hours += hours;
}

void Clock::addMinutes(int mins)
{
	d_mins += mins;
}

void Clock::addSeconds(int secs)
{
	d_secs += secs;
}

void Clock::resetClock()
{
	d_hours = 0;
	d_secs = 0;
	d_mins = 0;
}

void Clock::displayTime(ostream& out)
{
	int seconds = 0, minutes = 0, hours = 0;
	seconds = localTime->tm_sec + d_secs;
	minutes += (seconds / 60);
	seconds = seconds % 60;

	minutes += localTime->tm_min + d_mins;
	hours += minutes / 60;
	minutes = minutes % 60;

	hours = (hours + localTime->tm_hour + d_hours) % 24;


	string timestr = "";
	out << setw(2) << setfill('0') << (format_24 ? hours : (hours % 12)) << ":";
	out << setw(2) << setfill('0') << minutes << ":";
	out << setw(2) << setfill('0') << seconds << " ";
	if (!format_24)
	{
		if (hours > 12)
		{
			out << "PM";
		}
		else
		{
			out << "AM";
		}
	}
}