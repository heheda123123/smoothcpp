#include "any.h"
#include <sstream>
#include <stdexcept>

using namespace scpp;

Any::Any() : m_type(Type::V_NULL)
{
}

Any::Any(bool value) : m_type(Type::V_BOOL)
{
    m_value = value ? "true" : "false";
}

Any::Any(int value) : m_type(Type::V_INT)
{
    m_value = std::to_string(value);
}

Any::Any(double value) : m_type(Type::V_DOUBLE)
{
    m_value = std::to_string(value);
}

Any::Any(const char *value) : m_type(Type::V_STRING)
{
    m_value = value;
}

Any::Any(const std::string & value) : m_type(Type::V_STRING)
{
    m_value = value;
}

Any::Type Any::type() const
{
    return m_type;
}

bool Any::is_null() const
{
    return m_type == Type::V_NULL;
}

bool Any::is_bool() const
{
    return m_type == Type::V_BOOL;
}

bool Any::is_int() const
{
    return m_type == Type::V_INT;
}

bool Any::is_double() const
{
    return m_type == Type::V_DOUBLE;
}

bool Any::is_string() const
{
    return m_type == Type::V_STRING;
}

Any & Any::operator = (bool value)
{
    m_type = Type::V_BOOL;
    m_value = value ? "true" : "false";
    return *this;
}

Any & Any::operator = (int value)
{
    m_type = Type::V_INT;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (double value)
{
    m_type = Type::V_DOUBLE;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (const char *value)
{
    m_type = Type::V_STRING;
    m_value = value;
    return *this;
}

Any & Any::operator = (const std::string & value)
{
    m_type = Type::V_STRING;
    m_value = value;
    return *this;
}

Any & Any::operator = (const Any & value)
{
    if (this == &value)
    {
        return *this;
    }
    m_type = value.m_type;
    m_value = value.m_value;
    return *this;
}

bool Any::operator == (const Any & other)
{
    if (m_type != other.m_type)
    {
        return false;
    }
    return m_value == other.m_value;
}

bool Any::operator != (const Any & other)
{
    return !(m_value == other.m_value);
}

Any::operator bool()
{
    if (m_type != Type::V_BOOL) {
        throw std::logic_error{"not bool type"};
    }
    return m_value == "true";
}

Any::operator bool() const
{
    if (m_type != Type::V_BOOL) {
        throw std::logic_error{"not bool type"};
    }
    return m_value == "true";
}

Any::operator int()
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

Any::operator int() const
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

Any::operator double()
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

Any::operator double() const
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

Any::operator std::string()
{
    if (m_type != Type::V_STRING) {
        throw std::logic_error{"not string type"};
    }
    return m_value;
}

Any::operator std::string() const
{
    if (m_type != Type::V_STRING) {
        throw std::logic_error{"not string type"};
    }
    return m_value;
}