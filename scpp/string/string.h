#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <unordered_map>
#include <set>

#ifdef _WIN32
#include <windows.h>
#endif

namespace scpp
{
    std::string to_lower(std::string input);
    std::string to_upper(std::string input);

    std::string ltrim(const std::string & input, const std::string & trims = " ");
    std::string rtrim(const std::string & input, const std::string & trims = " ");
    std::string trim(const std::string & input, const std::string & trims = " ");

    std::vector<std::string> split_str(const std::string & input, const std::string & separator = " ");
    std::vector<std::string> split_chars(const std::string & input, const std::string & separator = " ");

    std::string join(const std::vector<std::string> &input, const std::string & separator);

    bool has_prefix(const std::string & input, const std::string & prefix);
    bool has_suffix(const std::string & input, const std::string & suffix);
    bool contains(const std::string & str, const std::string & substr);

    std::string format(const char *format,...);

    void hexdump(const std::string& str);

    bool is_digit(std::string str);

    template<typename T>
    std::string to_string(const std::vector<T> v) {
        std::stringstream ss;
        ss << "[";
        for (auto it = v.cbegin(); it != v.cend(); ++it) {
            if (it == v.cbegin()) {
                if (std::is_same<T, std::string>::value)
                    ss << "\"" << *it << "\"";
                else
                    ss << *it;
            } else {
                if (std::is_same<T, std::string>::value)
                    ss << ", " << "\"" << *it << "\"";
                else
                    ss << ", " << *it;
            }
        }
        ss << "]";
        return ss.str();
    }

    template<typename T>
    std::string to_string(const std::list<T> v) {
        std::stringstream ss;
        ss << "[";
        for (auto it = v.cbegin(); it != v.cend(); ++it) {
            if (it == v.cbegin()) {
                if (std::is_same<T, std::string>::value)
                    ss << "\"" << *it << "\"";
                else
                    ss << *it;
            } else {
                if (std::is_same<T, std::string>::value)
                    ss << ", " << "\"" << *it << "\"";
                else
                    ss << ", " << *it;
            }
        }
        ss << "]";
        return ss.str();
    }

    template<typename T1, typename T2>
    std::string to_string(const std::map<T1, T2> m) {
        std::stringstream ss;
        ss << "{";
        for (auto it = m.cbegin(); it != m.cend(); ++it) {
            if (it == m.cbegin()) {
                if (std::is_same<T1, std::string>::value)
                    ss << "\"" << it->first << "\"";
                else
                    ss << it->first;
                ss << ": ";
                if (std::is_same<T2, std::string>::value)
                    ss << "\"" << it->second << "\"";
                else
                    ss << it->second;
            } else {
                if (std::is_same<T1, std::string>::value)
                    ss << ", " << "\"" << it->first << "\"";
                else
                    ss << ", " << it->first;
                ss << ": ";
                if (std::is_same<T2, std::string>::value)
                    ss << "\"" << it->second << "\"";
                else
                    ss << it->second;
            }
        }
        ss << "}";
        return ss.str();
    }

    template<typename T1, typename T2>
    std::string to_string(const std::unordered_map<T1, T2> m) {
        std::stringstream ss;
        ss << "{";
        for (auto it = m.cbegin(); it != m.cend(); ++it) {
            if (it == m.cbegin()) {
                if (std::is_same<T1, std::string>::value)
                    ss << "\"" << it->first << "\"";
                else
                    ss << it->first;
                ss << ": ";
                if (std::is_same<T2, std::string>::value)
                    ss << "\"" << it->second << "\"";
                else
                    ss << it->second;
            } else {
                if (std::is_same<T1, std::string>::value)
                    ss << ", " << "\"" << it->first << "\"";
                else
                    ss << ", " << it->first;
                ss << ": ";
                if (std::is_same<T2, std::string>::value)
                    ss << "\"" << it->second << "\"";
                else
                    ss << it->second;
            }
        }
        ss << "}";
        return ss.str();
    }

    template<typename T>
    std::string to_string(const std::set<T> v) {
        std::stringstream ss;
        ss << "{";
        for (auto it = v.cbegin(); it != v.cend(); ++it) {
            if (it == v.cbegin()) {
                if (std::is_same<T, std::string>::value)
                    ss << "\"" << *it << "\"";
                else
                    ss << *it;
            } else {
                if (std::is_same<T, std::string>::value)
                    ss << ", " << "\"" << *it << "\"";
                else
                    ss << ", " << *it;
            }
        }
        ss << "}";
        return ss.str();
    }

#ifdef _WIN32
    std::wstring ansi2unicode(std::string_view ansiStr, unsigned int codePage = CP_ACP);
    std::string unicode2ansi(std::wstring_view unicodeStr, unsigned int codePage = CP_ACP);
    std::string gbk2utf8(std::string_view gbkStr);
    std::string utf82gbk(std::string_view utf8Str);
#endif
}