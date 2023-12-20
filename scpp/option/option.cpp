#include <scpp/string/string.h>
#include <scpp/option/option.h>
#include <stdexcept>
#include <iostream>

using namespace scpp;

Option::Item::Item(std::string arg_key, Any::Type arg_type, bool required, std::string help_info, Any default_value, bool parsed, Any value)
    : arg_key(arg_key), arg_type(arg_type), required(required), help_info(help_info), default_value(default_value), parsed(parsed), value(value)
{   
}

Option::Option(const std::string& program_info): m_prog_info(program_info) {}

void Option::add(const std::string& key, Option::Type arg_type, const std::string& help_info, Any default_value) {
    Any::Type _type;
    switch (arg_type) {
    case Type::V_NUMBER: _type = Any::Type::V_NUMBER; break;
    case Type::V_BOOL: _type = Any::Type::V_BOOL; break;
    case Type::V_STRING: _type = Any::Type::V_STRING; break;
    }
    if (default_value != Any{} && _type != default_value.type()) throw std::logic_error{"default value type conflict"};
    m_options.emplace_back(key, _type, true, help_info, default_value);
}

void Option::add_opt(const std::string& key, Option::Type arg_type, const std::string& help_info, Any default_value) {
    Any::Type _type;
    switch (arg_type) {
    case Type::V_NUMBER: _type = Any::Type::V_NUMBER; break;
    case Type::V_BOOL: _type = Any::Type::V_BOOL; break;
    case Type::V_STRING: _type = Any::Type::V_STRING; break;
    }
    if (default_value != Any{} && _type != default_value.type()) throw std::logic_error{"default value type conflict"};
    m_options.emplace_back(key, _type, false, help_info, default_value);
}

void Option::parse(int argc, const char **argv) {
    std::vector<std::string> temp_arg;
    temp_arg.assign(argv + 1, argv + argc);
    for (auto it = temp_arg.cbegin(); it != temp_arg.cend(); ++it) {
        if (has_prefix((*it), "-")) {
            std::string arg_name = it->substr(1);
            for (auto &item : m_options) {
                if (arg_name == item.arg_key) {
                    item.parsed = true;
                    if (item.arg_type == Any::Type::V_BOOL) {
                        item.value = true;
                        break;
                    } else {
                        if (it + 1 == temp_arg.cend()) throw std::logic_error{"Not enough parameters provided"};
                        item.value = *(++it);
                        break;
                    }
                }
            }
        }
    }
    // Determine whether the analysis results meet the requirements
    for (auto &item : m_options) {
        // if no value provided and set default value
        if ((item.default_value != Any{}) && !item.parsed) {
            item.parsed = true;
            item.value = item.default_value;
        }
        if ((item.parsed == false) && (item.required == true)) {
            throw std::logic_error{"required arg not provided"};
        }
    }
}

Any Option::get(const std::string& key) {
    for (const auto &item : m_options) {
        if (item.arg_key == key) {
            return item.value;
        }
    }
    return Any{};
}

bool Option::has(const std::string& key) {
    for (const auto &item : m_options) {
        if (item.arg_key == key && item.parsed) {
            return true;
        }
    }
    return false;
}

void Option::helpinfo() {
    std::cout << m_prog_info << "\n";
    for (const auto &item : m_options) {
        std::cout << "\t" << item.arg_key << ": " << item.help_info << "\n";
    }
}