#include "option.h"
#include <scpp/string/string.h>
#include <stdexcept>
#include <iostream>

using namespace scpp;

Option::Item::Item(std::string arg_key, Any default_value, Any::Type arg_type, bool required, std::string help_info, bool parsed, Any value)
    : arg_key(arg_key), default_value(default_value), arg_type(arg_type), required(required), help_info(help_info), parsed(parsed), value(value)
{   
}

Option::Option(std::string_view program_info): m_prog_info(program_info) {}

void Option::add(const std::string& key, Any default_value, Type arg_type, bool required, const std::string& help_info) {
    Any::Type type;
    switch (arg_type) {
    case Type::V_BOOL: type = Any::Type::V_BOOL; break;
    case Type::V_INT: type = Any::Type::V_INT; break;
    case Type::V_DOUBLE: type = Any::Type::V_DOUBLE; break;
    case Type::V_STRING: type = Any::Type::V_STRING; break;
    }
    
    m_options.emplace_back(key, default_value, type, required, help_info, false, "");
}

void Option::parse(int argc, const char **argv) {
    std::vector<std::string> temp_arg;
    temp_arg.assign(argv + 1, argv + argc - 1);
    // for each m_options item.arg_key find in temp_arg
    for (auto it = temp_arg.cbegin(); it != temp_arg.cend(); ++it) {
        if (has_prefix((*it), "-")) {
            std::string arg_name = it->substr(1);
            for (auto &item : m_options) {
                if (arg_name == item.arg_key) {
                    item.parsed = true;
                    if (item.arg_type == Any::Type::V_BOOL) {
                        if (has_prefix(*(it + 1), "-")) throw std::logic_error{"wrong arg pass"};
                        item.value = true;
                    }
                    switch (item.arg_type) {
                    case Any::Type::V_STRING: item.value = *(it + 1); ++it; break;
                    case Any::Type::V_INT: item.value = std::stoi(*(it + 1)); ++it; break;
                    case Any::Type::V_DOUBLE: item.value = std::stod(*(it + 1)); ++it; break;
                    default: break;
                    }
                }
            }
        }
    }
    for (auto &item : m_options) {
        if (item.default_value != Any{}) {
            item.parsed = true;
            item.value = item.default_value;
        }
        if (item.parsed == false && item.required == true) {
            throw std::logic_error{"required arg not pass"};
        }
    }
}

Any Option::get(std::string_view key) {
    for (const auto &item : m_options) {
        if (item.arg_key == key) {
            return item.value;
        }
    }
    return Any{};
}

bool Option::has(std::string_view key) {
    for (const auto &item : m_options) {
        if (item.arg_key == key) {
            return true;
        }
    }
    return false;
}

void Option::helpinfo() {
    std::cout << m_prog_info << "\n";
    for (const auto &item : m_options) {
        std::cout << item.arg_key << ": " << item.help_info << "\n";
    }
}