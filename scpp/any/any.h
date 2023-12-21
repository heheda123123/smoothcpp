#pragma once

#include <ostream>
#include <string>
#include <vector>

namespace scpp
{
    class Any
    {
    public:
        enum class Type
        {
            V_NULL,
            V_BOOL,
            V_NUMBER,
            V_STRING,
            V_VECTOR,
            V_MAP
        };

        Any();
        Any(bool any);
        // V_NUMBER
        Any(short any);
        Any(unsigned short any);
        Any(int any);
        Any(unsigned int any);
        Any(long any);
        Any(unsigned long any);
        Any(float any);
        Any(double any);
        // V_STRING
        Any(const char *any);
        Any(const std::string & any);
        // V_VECTOR
        Any(const std::vector<Any> v);
        // V_MAP

        Type type() const;
        bool is_null() const;
        bool is_bool() const;
        bool is_number() const;
        bool is_string() const;

        Any & operator = (bool any);
        Any & operator = (short any);
        Any & operator = (unsigned short any);
        Any & operator = (int any);
        Any & operator = (unsigned int any);
        Any & operator = (long any);
        Any & operator = (unsigned long any);
        Any & operator = (float any);
        Any & operator = (double any);
        
        Any & operator = (const char *any);
        Any & operator = (const std::string & any);
        
        Any & operator = (const Any & any);
        bool operator == (const Any & other);
        bool operator != (const Any & other);

        operator bool();
        operator bool() const;

        operator short();
        operator short() const;
        operator unsigned short();
        operator unsigned short() const;
        operator int();
        operator int() const;
        operator unsigned int();
        operator unsigned int() const;
        operator long();
        operator long() const;
        operator unsigned long();
        operator unsigned long() const;
        operator float();
        operator float() const;
        operator double();
        operator double() const;

        operator std::string();
        operator std::string() const;

        friend std::ostream & operator << (std::ostream & os, const Any & value)
        { 
            os << value.m_value;
            return os;
        }

    private:
        Type m_type;
        std::string m_value;
    };
    
}