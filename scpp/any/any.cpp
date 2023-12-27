#include <stdexcept>
#include <scpp/string/string.h>
#include <scpp/any/any.h>

using namespace scpp;

Any::~Any() {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_VECTOR*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_NULL) {
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
}

Any::Any(bool value) : m_type(Type::V_BOOL)
{
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = value ? "true" : "false";
}

Any::Any(int value) : m_type(Type::V_NUMBER)
{
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = std::to_string(value);
}

Any::Any(double value) : m_type(Type::V_NUMBER)
{
    m_value = new T_STRING;    
    *static_cast<T_STRING*>(m_value) = rtrim(std::to_string(value), "0");
}

Any::Any(const char *value) : m_type(Type::V_STRING)
{
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = value;
}

Any::Any(const std::string & value) : m_type(Type::V_STRING)
{
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = value;
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

bool Any::is_number() const
{
    return m_type == Type::V_NUMBER;
}

bool Any::is_string() const
{
    return m_type == Type::V_STRING;
}

bool Any::is_vector() const
{
    return m_type == Type::V_VECTOR;
}

bool Any::is_map() const
{
    return m_type == Type::V_MAP;
}

Any::Any(const Any & other)
{
    m_type = other.m_type;
    if (other.m_type == Type::V_VECTOR) {
        m_value = new T_VECTOR{*static_cast<T_VECTOR*>(other.m_value)};
    } else if (other.m_type == Type::V_MAP) {
        m_value = new T_MAP{*static_cast<T_MAP*>(other.m_value)};
    } else if (other.m_type == Type::V_NULL) {
        return;
    } else {
        m_value = new T_STRING{*static_cast<T_STRING*>(other.m_value)};
    }
}

Any & Any::operator = (const Any & other)
{
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else if (other.m_type == Type::V_NULL) {
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = other.m_type;
    if (other.m_type == Type::V_VECTOR) {
        m_value = new T_VECTOR{*static_cast<T_VECTOR*>(other.m_value)};
    } else if (other.m_type == Type::V_MAP) {
        m_value = new T_MAP{*static_cast<T_MAP*>(other.m_value)};
    } else if (other.m_type == Type::V_NULL) {
    } else {
        m_value = new T_STRING{*static_cast<T_STRING*>(other.m_value)};
    }
    return *this;
}

Any & Any::operator = (bool other) {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = Type::V_BOOL;
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = other ? "true" : "false";
    return *this;
}

Any & Any::operator = (int other) {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = Type::V_NUMBER;
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = std::to_string(other);
    return *this;
}
Any & Any::operator = (double other) {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = Type::V_NUMBER;
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = rtrim(std::to_string(other), "0");
    return *this;
}
Any & Any::operator = (const char *other) {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = Type::V_STRING;
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = other;
    return *this;
}

Any & Any::operator = (const std::string & other) {
    if (m_type == Type::V_VECTOR) {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    } else if (m_type == Type::V_MAP) {
        delete static_cast<T_MAP*>(m_value);
        m_value = nullptr;
    } else {
        delete static_cast<T_STRING*>(m_value);
        m_value = nullptr;
    }
    m_type = Type::V_STRING;
    m_value = new T_STRING;
    *static_cast<T_STRING*>(m_value) = other;
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
        throw std::logic_error{"cast to bool failed"};
    }
    return *static_cast<T_STRING*>(m_value) == "true" ? true : false;
}

Any::operator bool() const
{
    if (m_type != Type::V_BOOL) {
        throw std::logic_error{"cast to bool failed"};
    }
    return *static_cast<T_STRING*>(m_value) == "true" ? true : false;
}


Any::operator int()
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to number failed"};
    }
    return std::stoi(*static_cast<T_STRING*>(m_value));
}

Any::operator int() const
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to number failed"};
    }
    return std::stoi(*static_cast<T_STRING*>(m_value));
}

Any::operator double()
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to number failed"};
    }
    return std::stod(*static_cast<T_STRING*>(m_value));
}

Any::operator double() const
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to number failed"};
    }
    return std::stod(*static_cast<T_STRING*>(m_value));
}

Any::operator std::string()
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to string failed"};
    }
    return *static_cast<T_STRING*>(m_value);
}

Any::operator std::string() const
{
    if (m_type != Type::V_NUMBER && m_type != Type::V_STRING) {
        throw std::logic_error{"cast to string failed"};
    }
    return *static_cast<T_STRING*>(m_value);
}
