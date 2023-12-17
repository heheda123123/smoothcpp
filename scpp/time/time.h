#pragma once
#include <string>

#include <ctime>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif

namespace scpp
{
	class Time
	{
	public:
		Time();
		~Time() = default;

		int year() const;
		int month() const;
		int day() const;
		int hour() const;
		int minute() const;
		int second() const;
		int week() const;

		double seconds() const;
		double milliseconds() const;
		double operator -(const Time & other) const;

		// because implement use strftime, should ensure format end with 00
		// so use std::string as parameter
		std::string format(const std::string & format) const;

		static void sleep(int milliseconds);

		void show() const;

	private:
		void get_local_time(struct tm * tm, const time_t * ticks);
		void get_time_of_day(struct timeval * tv);

	private:
		struct tm m_tm = {0};
		int m_sec = 0;
		int m_usec = 0;
	};
}