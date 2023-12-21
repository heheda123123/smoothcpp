#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdarg>
#include <cctype>
#include <memory>
#include <scpp/string/string.h>
#include <iomanip>
#include <iostream>
#include <regex> 


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

std::string scpp::ltrim(const std::string& input, const std::string& trims)
{
    std::string str(input);
    size_t pos = str.find_first_not_of(trims);
    if (pos != std::string::npos)
        str.erase(0, pos);
    else
        str.clear();
    return str;
}

std::string scpp::rtrim(const std::string& input, const std::string& trims)
{
    std::string str(input);
    size_t pos = str.find_last_not_of(trims);
    if (pos != std::string::npos)
        str.erase(pos + 1);
    else
        str.clear();
    return str;
}

std::string scpp::trim(const std::string & input, const std::string& trims)
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


std::string scpp::join(const std::vector<std::string> &input, const std::string & separator)
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


bool scpp::has_prefix(const std::string & input, const std::string & prefix)
{
    if (input.size() < prefix.size())
    {
        return false;
    }
    return input.substr(0, prefix.size()) == prefix;
}

bool scpp::has_suffix(const std::string & input, const std::string & suffix)
{
    if (input.size() < suffix.size())
    {
        return false;
    }
    return input.substr(input.size() - suffix.size(), suffix.size()) == suffix;
}

bool scpp::contains(const std::string & str, const std::string & substr) {
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

void scpp::hexdump(const std::string& str) {
    int count = 0;
    for (unsigned char c : str) {
        if (count % 16 == 0) {
            if (count != 0) {
                std::cout << "  " << std::string(16, ' ') << "  ";
                for (int i = count - 16; i < count; ++i) {
                    if (isprint(str[i])) {
                        std::cout << str[i];
                    } else {
                        std::cout << ".";
                    }
                }
                std::cout << std::endl;
            }
            std::cout << "  ";
        }
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
        ++count;
    }
    if (count % 16 != 0) {
        int spaces = (16 - (count % 16)) * 3;
        if (count % 16 <= 8) {
            spaces += 2;
        }
        std::cout << std::string(spaces, ' ');
    }
    std::cout << "  " << std::string(16 - (count % 16), ' ') << "  ";
    for (int i = count - (count % 16); i < count; ++i) {
        if (isprint(str[i])) {
            std::cout << str[i];
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

bool scpp::is_digit(std::string str) {
    std::regex pattern("\\d+(\\.\\d+)?");
    if (regex_match(str, pattern)) {
        return true;
    } else {
        return false;
    }
}

std::vector<scpp::Any> scpp::str2vec(const std::string& str) {
    if (!has_prefix(str, "[") || !has_suffix(str, "]")) {
        throw std::logic_error{"not to_string(vector)"};
    }
    std::string input = str.substr(1).substr(0, str.size() - 1);
    std::vector<scpp::Any> result;
    auto vinput = split_str(input, ",");
    for (const auto &i : vinput) {
        std::string item = trim(i);
        if (item == "") {
            result.push_back("");
        } else if (item == "true") {
            result.push_back(Any{true});
        } else if (has_prefix(item, "\"") || has_prefix(item, "'")) {
            item = item.substr(1).substr(0, str.size() - 1);
            result.push_back(item);
        } else if (is_digit(item)) {
            double num = stod(item);
            result.push_back(num);
        } else if (has_prefix(item, "[")) {
            result += str2vec(item);
        }
    }
}

std::map<std::string, scpp::Any> scpp::str2map(const std::string& str) {
    // 
}


#ifdef _WIN32
std::wstring scpp::ansi2unicode(std::string_view ansiStr, unsigned int codePage) {
    std::wstring unicodeStr;
    int iSizeUtf8 =
        MultiByteToWideChar(codePage, 0, ansiStr.data(), -1, nullptr, 0);

    auto putf8Buf = std::make_unique<WCHAR[]>(iSizeUtf8);

    int ret = MultiByteToWideChar(codePage, 0, ansiStr.data(), -1,
                                  putf8Buf.get(), iSizeUtf8);
    if (ret == 0) {
        throw std::runtime_error("MultiByteToWideChar");
    }

    unicodeStr.assign(putf8Buf.get(), iSizeUtf8);
    return unicodeStr;
}

std::string scpp::unicode2ansi(std::wstring_view unicodeStr, unsigned int codePage) {
    std::string ansiStr;
    int iSizeLocal = WideCharToMultiByte(codePage, 0, unicodeStr.data(), -1,
                                         nullptr, 0, nullptr, nullptr);

    auto szpLocal = std::make_unique<char[]>(iSizeLocal);

    int ret = WideCharToMultiByte(codePage, 0, unicodeStr.data(), -1,
                                  szpLocal.get(), iSizeLocal, nullptr, nullptr);
    if (ret == 0)
        throw std::runtime_error("WideCharToMultiByte");

    ansiStr.assign(szpLocal.get(), iSizeLocal);

    return ansiStr;
}

std::string scpp::gbk2utf8(std::string_view gbkStr) {
    std::wstring unicodeStr = ansi2unicode(gbkStr);

    return unicode2ansi(unicodeStr, CP_UTF8);
}

std::string scpp::utf82gbk(std::string_view utf8Str) {
    std::wstring unicodeStr = ansi2unicode(utf8Str, CP_UTF8);

    return unicode2ansi(unicodeStr);
}

#endif