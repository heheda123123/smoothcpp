#pragma once

#include <ostream>
#include <string>
#include <vector>
#include <variant>
#include <map>
#include <scpp/string/string.h>

namespace scpp
{
    class Any
    {
	public:
		// strong type
        enum class Type
        {
            V_NULL,
            V_BOOL,
            V_NUMBER,
            V_STRING,
            V_VECTOR,
            V_MAP
		};

		using T_VECTOR = std::vector<Any>;
		using T_MAP = std::map<std::string, Any>;
		

		Any();
		~Any() {
			if (m_type == Type::V_VECTOR) {
				delete std::get<T_VECTOR*>(m_value);
			} else if (m_type == Type::V_MAP) {
				delete std::get<T_MAP*>(m_value);
			}
		}
        Any(bool any);
        // V_NUMBER
        Any(int any);
        Any(double any);
        // V_STRING
        Any(const char *any);
        Any(const std::string & any);
        // V_VECTOR
		Any(const T_VECTOR &any);
		// V_MAP
		Any(const T_MAP &any);


        Type type() const;
        bool is_null() const;
        bool is_bool() const;
        bool is_number() const;
		bool is_string() const;
		bool is_vector() const;
		bool is_map() const;


		Any & operator = (bool any);
		
		Any & operator = (int any);
        Any & operator = (double any);
        
        Any & operator = (const char *any);
        Any & operator = (const std::string & any);
        
		Any & operator = (const Any & any);
		
        bool operator == (const Any & other);
        bool operator != (const Any & other);

        operator bool();
        operator bool() const;

        operator int();
        operator int() const;
        operator double();
        operator double() const;

        operator std::string();
		operator std::string() const;

		operator T_VECTOR();
		operator T_VECTOR() const;

		operator T_MAP();
		operator T_MAP() const;

        friend std::ostream & operator << (std::ostream & os, const Any & value)
		{
			if (value.m_type == Type::V_VECTOR) {
				os << to_string(*std::get<T_VECTOR*>(value.m_value));
			} else if (value.m_type == Type::V_VECTOR) {
				os << to_string(*std::get<T_MAP*>(value.m_value));
			} else {
				os << std::get<std::string>(value.m_value);
			}
            return os;
		}

	private:
		Type m_type;
		std::variant<T_VECTOR*, T_MAP*, std::string> m_value;
    };
    
}