#include <iostream>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <thread>
#include <scpp/time/time.h>

using namespace scpp;

Time::Time() {
    auto t_now = std::chrono::system_clock::to_time_t(m_now);
    get_local_time(&this->m_now_tm, &t_now);
}

long long Time::elapse() const {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(now - m_now).count();
}

void Time::reset() {
    m_now = std::chrono::system_clock::now();
    auto t_now = std::chrono::system_clock::to_time_t(m_now);
    get_local_time(&this->m_now_tm, &t_now);
}

int Time::year() const
{
    return m_now_tm.tm_year + 1900;
}

int Time::month() const
{
    return m_now_tm.tm_mon + 1;
}

int Time::day() const
{
    return m_now_tm.tm_mday;
}

int Time::hour() const
{
    return m_now_tm.tm_hour;
}

int Time::minute() const
{
    return m_now_tm.tm_min;
}

int Time::second() const
{
    return m_now_tm.tm_sec;
}

int Time::week() const
{
    return m_now_tm.tm_wday;
}

double Time::seconds() const
{
    return m_now_tm.tm_sec;
}

long long Time::operator-(const Time &other) const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(this->m_now - other.m_now).count();
}

std::string Time::format(const std::string& format) const
{
    std::stringstream ss;
    ss << std::put_time(&m_now_tm, format.c_str());
    return ss.str();
}

void Time::show() const
{
    std::cout << format() << std::endl;
}

void Time::get_local_time(struct tm * tm, const time_t * ticks)
{
#ifdef _WIN32
    localtime_s(tm, ticks);
#else
    localtime_r(ticks, tm);
#endif
}


void Time::sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds{milliseconds});
}