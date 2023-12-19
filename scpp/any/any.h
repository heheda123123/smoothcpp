#pragma once

#include <ostream>
#include <string>

namespace scpp
{
    class Any
    {
    public:
        enum class Type
        {
            V_NULL,
            V_BOOL,
            V_INT,
            V_DOUBLE,
            V_STRING
        };

		Any();
		Any(bool any);
		Any(int any);
		Any(double any);
		Any(const char *any);
		Any(const std::string & any);

        Type type() const;
        bool is_null() const;
        bool is_bool() const;
        bool is_int() const;
        bool is_double() const;
        bool is_string() const;

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

		friend std::ostream & operator << (std::ostream & os, const Any & value)
        {
            switch (value.m_type) {
			case Any::Type::V_STRING:
                os << "type: string, value: "; break;
			case Any::Type::V_BOOL:
                os << "type: bool, value: "; break;
			case Any::Type::V_DOUBLE:
                os << "type: double, value: "; break;
			case Any::Type::V_NULL:
                os << "type: null, value: "; break;
			case Any::Type::V_INT:
                os << "type: int, value: "; break;
            }
            os << value.m_value;
            return os;
        }

    private:
        Type m_type;
        std::string m_value;
    };
    
}