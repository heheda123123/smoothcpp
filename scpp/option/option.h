#pragma once
#include <string_view>
#include <vector>
#include <scpp/any/any.h>

namespace scpp {
	class Option {
	public:
		struct Item{
			std::string arg_key;
			Any default_value;
			Any::Type arg_type;
			bool required;
			std::string help_info;
			bool parsed;
			Any value;
			Item(std::string key, Any default_value, Any::Type arg_type, bool required, std::string help_info, bool parsed, Any value);
		};
		enum class Type
		{
			V_BOOL,
			V_INT,
			V_DOUBLE,
			V_STRING
		};
		Option(std::string_view program_info="");
		void add(const std::string& key, Any default_value, Type arg_type, bool required, const std::string& help_info);
		void parse(int argc, const char **argv);
		Any get(std::string_view key);
		bool has(std::string_view key);
		void helpinfo();

		Type T_BOOL = Type::V_BOOL;
		Type T_INT = Type::V_INT;
		Type T_DOUBLE = Type::V_DOUBLE;
		Type T_STRING = Type::V_STRING;
	private:
		std::string m_prog_info;
		std::vector<Item> m_options;
		std::vector<std::string> m_temp_arg;

	};
}