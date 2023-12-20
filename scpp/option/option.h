#pragma once
#include <vector>
#include <scpp/any/any.h>

namespace scpp {
    class Option {
    public:
        enum Type {
            V_BOOL,
            V_NUMBER,
            V_STRING
        };
        struct Item{
            std::string arg_key;
            Any::Type arg_type;
            bool required;
            std::string help_info;
            Any default_value;
            bool parsed;
            Any value;
            
            Item(std::string key, Any::Type arg_type, bool required, std::string help_info, Any default_value, bool parsed = false, Any value = Any{});
        };

        Option(const std::string & program_info="");
        void add(const std::string& key, Type arg_type, const std::string& help_info, Any default_value = Any{});
        void add_opt(const std::string& key, Type arg_type, const std::string& help_info, Any default_value = Any{});
        
        void parse(int argc, const char **argv);
        Any get(const std::string & key);
        bool has(const std::string & key);
        void helpinfo();

    private:
        std::string m_prog_info;
        std::vector<Item> m_options;
        std::vector<std::string> m_temp_arg;
    };
}