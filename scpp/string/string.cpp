#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdarg>
#include <cctype>
#include "string.h"

std::string scpp::to_lower(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

std::string scpp::to_upper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}

std::string scpp::ltrim(const std::string & input, const std::string& trims)
{
	std::string str = input;
    size_t pos = str.find_first_not_of(trims);
    if (pos != std::string::npos)
        str.erase(0, pos);
    else
        str.clear();
    return str;
}

std::string scpp::rtrim(const std::string & input, const std::string& trims)
{
	std::string str = input;
    size_t pos = str.find_last_not_of(trims);
    if (pos != std::string::npos)
        str.erase(pos + 1);
    else
        str.clear();
    return str;
}

std::string scpp::trim(const std::string & input, const std::string & trims)
{
	std::string str = ltrim(input, trims);
    return rtrim(str, trims);
}

std::vector<std::string> scpp::split(const std::string& input, const std::string& separator)
{
	std::vector<std::string> output;
    size_t last = 0;
	size_t index = input.find_first_of(separator, last);
    while (index != std::string::npos)
    {
		std::string str = input.substr(last, index - last);
        output.push_back(str);
        last = index + 1;
        index = input.find_first_of(separator, last);
    }
    if (index - last > 0)
    {
        output.push_back(input.substr(last , index - last));
    }
    return output;
}


std::string String::join(const std::vector<std::string> &input, const std::string & separator)
{
    std::ostringstream oss;
    for (auto it = input.begin(); it != input.end(); ++it)
    {
        if (it != input.begin())
        {
            oss << separator;
        }
        oss << *it;
    }
    return oss.str();
}

std::string String::join(const std::vector<std::string> &input, char separator)
{
	return join(input, std::string(1, separator));
}

bool String::has_prefix(const std::string & input, const std::string & prefix)
{
    if (input.size() < prefix.size())
    {
        return false;
    }
    return input.substr(0, prefix.size()) == prefix;
}

bool String::has_suffix(const std::string & input, const std::string & suffix)
{
    if (input.size() < suffix.size())
    {
        return false;
    }
    return input.substr(input.size() - suffix.size(), suffix.size()) == suffix;
}

std::string String::capitalize(const std::string & input)
{
	std::string str = input;
    if (str.empty())
    {
        return "";
    }
    char ch = input[0];
    if (islower(ch))
    {
        ch = (char)toupper(ch);
        std::replace(str.begin(), str.begin() + 1, str[0], ch);
    }
    return str;
}

std::string String::format(const char *format,...)
{
	std::string result;
    va_list arg_ptr;
    va_start(arg_ptr, format);
    int len = vsnprintf(nullptr, 0, format, arg_ptr);
    va_end(arg_ptr);
    if (len > 0)
    {
        char * buf = new char[len + 1];
        va_start(arg_ptr, format);
        vsnprintf(buf, len + 1, format, arg_ptr);
        va_end(arg_ptr);
        buf[len] = 0;
        result = buf;
        delete [] buf;
    }
    return result;
}

bool scpp::contains(std::string str, std::string substr) {
	return str.find(substr) != std::string::npos;
}