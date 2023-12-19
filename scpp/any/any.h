#pragma once

#include <ostream>
#include <string>

namespace scpp
{
    class any
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

        any();
        any(bool any);
        any(int any);
        any(double any);
        any(const char *any);
        any(const std::string & any);
        ~any() = default;

        Type type() const;
        bool is_null() const;
        bool is_bool() const;
        bool is_int() const;
        bool is_double() const;
        bool is_string() const;

        any & operator = (bool any);
        any & operator = (int any);
        any & operator = (double any);
        any & operator = (const char *any);
        any & operator = (const std::string & any);
        any & operator = (const any & any);

        bool operator == (const any & other);
        bool operator != (const any & other);

        operator bool();
        operator bool() const;

        operator int();
        operator int() const;

        operator double();
        operator double() const;

        operator std::string();
        operator std::string() const;

        friend std::ostream & operator << (std::ostream & os, const any & value)
        {
            switch (value.m_type) {
            case any::Type::V_STRING:
                os << "type: string, value: "; break;
            case any::Type::V_BOOL:
                os << "type: bool, value: "; break;
            case any::Type::V_DOUBLE:
                os << "type: double, value: "; break;
            case any::Type::V_NULL:
                os << "type: null, value: "; break;
            case any::Type::V_INT:
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