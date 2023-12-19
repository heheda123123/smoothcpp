#include "any.h"
#include <sstream>
#include <stdexcept>

using namespace scpp;

any::any() : m_type(Type::V_NULL)
{
}

any::any(bool value) : m_type(Type::V_BOOL)
{
    m_value = value ? "true" : "false";
}

any::any(int value) : m_type(Type::V_INT)
{
    m_value = std::to_string(value);
}

any::any(double value) : m_type(Type::V_DOUBLE)
{
    m_value = std::to_string(value);
}

any::any(const char *value) : m_type(Type::V_STRING)
{
    m_value = value;
}

any::any(const std::string & value) : m_type(Type::V_STRING)
{
    m_value = value;
}

any::Type any::type() const
{
    return m_type;
}

bool any::is_null() const
{
    return m_type == Type::V_NULL;
}

bool any::is_bool() const
{
    return m_type == Type::V_BOOL;
}

bool any::is_int() const
{
    return m_type == Type::V_INT;
}

bool any::is_double() const
{
    return m_type == Type::V_DOUBLE;
}

bool any::is_string() const
{
    return m_type == Type::V_STRING;
}

any & any::operator = (bool value)
{
    m_type = Type::V_BOOL;
    m_value = value ? "true" : "false";
    return *this;
}

any & any::operator = (int value)
{
    m_type = Type::V_INT;
    m_value = std::to_string(value);
    return *this;
}

any & any::operator = (double value)
{
    m_type = Type::V_DOUBLE;
    m_value = std::to_string(value);
    return *this;
}

any & any::operator = (const char * value)
{
    m_type = Type::V_STRING;
    m_value = value;
    return *this;
}

any & any::operator = (const std::string & value)
{
    m_type = Type::V_STRING;
    m_value = value;
    return *this;
}

any & any::operator = (const any & value)
{
    if (this == &value)
    {
        return *this;
    }
    m_type = value.m_type;
    m_value = value.m_value;
    return *this;
}

bool any::operator == (const any & other)
{
    if (m_type != other.m_type)
    {
        return false;
    }
    return m_value == other.m_value;
}

bool any::operator != (const any & other)
{
    return !(m_value == other.m_value);
}

any::operator bool()
{
    if (m_type != Type::V_BOOL) {
        throw std::logic_error{"not bool type"};
    }
    return m_value == "true";
}

any::operator bool() const
{
    if (m_type != Type::V_BOOL) {
        throw std::logic_error{"not bool type"};
    }
    return m_value == "true";
}

any::operator int()
{
    if (m_type != Type::V_INT) {
        throw std::logic_error{"not int type"};
    }
    int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

any::operator int() const
{
    if (m_type != Type::V_INT) {
        throw std::logic_error{"not int type"};
    }
    int value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

any::operator double()
{
    if (m_type != Type::V_DOUBLE) {
        throw std::logic_error{"not double type"};
    }
    double value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

any::operator double() const
{
    if (m_type != Type::V_DOUBLE) {
        throw std::logic_error{"not double type"};
    }
    double value;
    std::stringstream ss;
    ss << m_value;
    ss >> value;
    return value;
}

any::operator std::string()
{
    if (m_type != Type::V_STRING) {
        throw std::logic_error{"not string type"};
    }
    return m_value;
}

any::operator std::string() const
{
    if (m_type != Type::V_STRING) {
        throw std::logic_error{"not string type"};
    }
    return m_value;
}