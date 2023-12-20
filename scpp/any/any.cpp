#include "any.h"
#include <sstream>
#include <stdexcept>
#include <scpp/string/string.h>

using namespace scpp;

Any::Any() : m_type(Type::V_NULL)
{
}

Any::Any(bool value) : m_type(Type::V_BOOL)
{
    m_value = value ? "true" : "false";
}

Any::Any(short value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(unsigned short value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(int value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(unsigned int value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(long value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(unsigned long value) : m_type(Type::V_NUMBER)
{
    m_value = std::to_string(value);
}

Any::Any(float value) : m_type(Type::V_NUMBER)
{
    m_value = rtrim(std::to_string(value), "0");
}

Any::Any(double value) : m_type(Type::V_NUMBER)
{
    m_value = rtrim(std::to_string(value), "0");
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

bool Any::is_number() const
{
    return m_type == Type::V_NUMBER;
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

Any & Any::operator = (short value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (unsigned short value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (int value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (unsigned int value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (long value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (unsigned long value)
{
    m_type = Type::V_NUMBER;
    m_value = std::to_string(value);
    return *this;
}

Any & Any::operator = (float value)
{
    m_type = Type::V_NUMBER;
    m_value = rtrim(std::to_string(value), "0");

    return *this;
}


Any & Any::operator = (double value)
{
    m_type = Type::V_NUMBER;
    m_value = rtrim(std::to_string(value), "0");
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
    switch (m_type) {
    case Type::V_NULL:
        return false;
    case Type::V_BOOL:
        return m_value == "true" ? true : false;
    case Type::V_NUMBER:
        return m_value == "0" ? false : true;
    case Type::V_STRING:
        return m_value == "" ? false : true;
    }
    return false;
}

Any::operator bool() const
{
    switch (m_type) {
    case Type::V_NULL:
        return false;
    case Type::V_BOOL:
        return m_value == "true" ? true : false;
    case Type::V_NUMBER:
        return m_value == "0" ? false : true;
    case Type::V_STRING:
        return m_value == "" ? false : true;
    }
    return false;
}

Any::operator short()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator short() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator unsigned short()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator unsigned short() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator int()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator int() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator unsigned int()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator unsigned int() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoi(m_value);
        case Type::V_STRING:
            return std::stoi(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator long()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stol(m_value);
        case Type::V_STRING:
            return std::stol(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator long() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stol(m_value);
        case Type::V_STRING:
            return std::stol(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }


    return 0;
}

Any::operator unsigned long()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoul(m_value);
        case Type::V_STRING:
            return std::stoul(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator unsigned long() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stoul(m_value);
        case Type::V_STRING:
            return std::stoul(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator float()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stof(m_value);
        case Type::V_STRING:
            return std::stof(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator float() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stof(m_value);
        case Type::V_STRING:
            return std::stof(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator double()
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stod(m_value);
        case Type::V_STRING:
            return std::stod(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
}

Any::operator double() const
{
    try {
        switch (m_type) {
        case Type::V_NULL:
            return 0;
        case Type::V_BOOL:
            return m_value == "true" ? 1 : 0;
        case Type::V_NUMBER:
            return std::stod(m_value);
        case Type::V_STRING:
            return std::stod(m_value);
        }
    } catch (const std::invalid_argument& e) {
        return 0;
    }

    return 0;
    
}

Any::operator std::string()
{
    switch (m_type) {
    case Type::V_NULL:
        return "";
    case Type::V_BOOL:
        return m_value;
    case Type::V_NUMBER:
        return m_value;
    case Type::V_STRING:
        return m_value;
    }
    return 0;
}

Any::operator std::string() const
{
    switch (m_type) {
    case Type::V_NULL:
        return "";
    case Type::V_BOOL:
        return m_value;
    case Type::V_NUMBER:
        return m_value;
    case Type::V_STRING:
        return m_value;
    }
    return 0;
}