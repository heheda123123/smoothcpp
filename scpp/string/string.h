#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace scpp
{
    std::string to_lower(std::string input);
    std::string to_upper(std::string input);

    std::string ltrim(std::string_view input, std::string_view trims = " ");
    std::string rtrim(std::string_view input, std::string_view trims = " ");
    std::string trim(std::string_view input, std::string_view trims = " ");

    std::vector<std::string> split_str(const std::string & input, const std::string & separator = " ");
    std::vector<std::string> split_chars(const std::string & input, const std::string & separator = " ");

    std::string join(const std::vector<std::string> &input, std::string_view separator);

    bool has_prefix(std::string_view input, std::string_view prefix);
    bool has_suffix(std::string_view input, std::string_view suffix);
    bool contains(std::string_view str, std::string_view substr);

    std::string format(const char *format,...);

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

    template<typename T1, typename T2>
    std::string to_string(const std::map<T1, T2> m) {
        std::stringstream ss;
        ss << "[";
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
                ss << ":";
                if (std::is_same<T2, std::string>::value)
                    ss << "\"" << it->second << "\"";
                else
                    ss << it->second;
            }
        }
        ss << "]";
        return ss.str();
    }
}