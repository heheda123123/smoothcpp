#pragma once
#include <string>
#include <chrono>

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

        int year() const;
        int month() const;
        int day() const;
        int hour() const;
        int minute() const;
        int second() const;
        int week() const;
        double seconds() const;
        
        // use milliseconds
        long long operator -(const Time &other) const;

        // because implement use strftime, should ensure format end with 00
        // so use std::string as parameter
        std::string format(const std::string & format = "%Y-%m-%d %H:%M:%S") const;

        static void sleep(int milliseconds);

        void show() const;
        long long elapse() const;
        void reset();

    private:
        void get_local_time(struct tm * tm, const time_t * ticks);

    private:
        decltype(std::chrono::system_clock::now())m_now = std::chrono::system_clock::now();

        struct tm m_now_tm = {0};
    };
}