#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdarg>
#include <cctype>
#include <memory>
#include <scpp/string/string.h>

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

std::string scpp::ltrim(std::string_view input, std::string_view trims)
{
    std::string str(input);
    size_t pos = str.find_first_not_of(trims);
    if (pos != std::string::npos)
        str.erase(0, pos);
    else
        str.clear();
    return str;
}

std::string scpp::rtrim(std::string_view input, std::string_view trims)
{
    std::string str(input);
    size_t pos = str.find_last_not_of(trims);
    if (pos != std::string::npos)
        str.erase(pos + 1);
    else
        str.clear();
    return str;
}

std::string scpp::trim(std::string_view input, std::string_view trims)
{
    std::string str = ltrim(input, trims);
    return rtrim(str, trims);
}

std::vector<std::string> scpp::split_str(const std::string &input, const std::string &separator) {
    std::vector<std::string> tokens;
    size_t start = 0, end;

    while ((end = input.find(separator, start)) != std::string::npos) {
        if (end != start) {
            tokens.push_back(input.substr(start, end - start));
        }
        start = end + separator.length();
    }

    if (start < input.length()) {
        tokens.push_back(input.substr(start));
    }

    return tokens;
}

std::vector<std::string> scpp::split_chars(const std::string & input, const std::string & separator)
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
        output.push_back(input.substr(last, index - last));
    }
    return output;
}


std::string scpp::join(const std::vector<std::string> &input, std::string_view separator)
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


bool scpp::has_prefix(std::string_view input, std::string_view prefix)
{
    if (input.size() < prefix.size())
    {
        return false;
    }
    return input.substr(0, prefix.size()) == prefix;
}

bool scpp::has_suffix(std::string_view input, std::string_view suffix)
{
    if (input.size() < suffix.size())
    {
        return false;
    }
    return input.substr(input.size() - suffix.size(), suffix.size()) == suffix;
}

bool scpp::contains(std::string_view str, std::string_view substr) {
    return str.find(substr) != std::string::npos;
}

std::string scpp::format(const char *format,...)
{
    std::string result;
    va_list arg_ptr;
    va_start(arg_ptr, format);
    int len = vsnprintf(nullptr, 0, format, arg_ptr);
    va_end(arg_ptr);
    if (len > 0)
    {
        auto buf = std::make_unique<char[]>(len + 1);
        va_start(arg_ptr, format);
        vsnprintf(buf.get(), len + 1, format, arg_ptr);
        va_end(arg_ptr);
        buf[len] = 0;
        result = buf.get();
    }
    return result;
}

