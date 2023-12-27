#pragma once

#include <string>
#include <vector>
#include <map>
#include <scpp/string/string.h>
#include <algorithm>

namespace scpp
{
    class Any
    {
    public:
        // strong types but intuitive special case with 
        // string <-> number
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
        using T_STRING = std::string;   // for other types

        Any(): m_type(Type::V_NULL), m_value(nullptr) {}
        ~Any();
        Any(bool other);
        Any(int other);
        Any(double other);
        Any(const char *other);
        Any(const std::string & other);

        template<typename T>
        Any(const std::vector<T> &other) : m_type(Type::V_VECTOR) {
            m_value = new T_VECTOR;
            std::transform(other.begin(), other.end(), std::back_inserter(*static_cast<T_VECTOR*>(m_value)), [](const auto &i) {return Any(i);});
        }

        template<typename T>
        Any(const std::map<std::string, T> &other): m_type(Type::V_MAP) {
            m_value = new T_MAP;
            std::transform(other.begin(), other.end(), std::inserter(*static_cast<T_MAP*>(m_value), static_cast<T_MAP*>(m_value)->begin()),
                [](const auto &val) {std::string one = val.first; return std::make_pair(one, Any(val.second));});
        }

        Any(const Any& other);
        Any & operator = (const Any & other);

        Any & operator = (bool other);
        Any & operator = (int other);
        Any & operator = (double other);
        Any & operator = (const char *other);
        Any & operator = (const std::string & other);

        template<typename T>
        Any & operator = (const std::vector<T> &other) {
            if (m_type == Type::V_VECTOR) {
                delete static_cast<T_STRING*>(m_value);
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
            m_type = Type::V_VECTOR;
            m_value = new T_VECTOR;
            std::transform(other.begin(), other.end(), std::back_inserter(*static_cast<T_VECTOR*>(m_value)), [](const auto &i) {return Any(i);});
            return *this;
        }

        template<typename T>
        Any & operator = (const std::map<std::string, T> &other) {
            if (m_type == Type::V_VECTOR) {
                delete static_cast<T_STRING*>(m_value);
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
            m_type = Type::V_MAP;
            m_value = new T_MAP;
            std::transform(other.begin(), other.end(), std::inserter(*static_cast<T_MAP*>(m_value), static_cast<T_MAP*>(m_value)->begin()),
                [](const auto &val) {return std::make_pair(val.first, Any(val.second));});
            return *this;

        }


        Type type() const;
        bool is_null() const;
        bool is_bool() const;
        bool is_number() const;
        bool is_string() const;
        bool is_vector() const;
        bool is_map() const;


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

        template<typename T>
        operator std::vector<T>() {
            if (m_type != Type::V_VECTOR) {
                throw std::logic_error{"cast to vector failed"};
            }
            std::vector<T> res;
            std::transform(static_cast<T_VECTOR*>(m_value)->begin(), static_cast<T_VECTOR*>(m_value)->end(), std::back_inserter(res), [](const auto &i) {return T(i);});
            return res;
        }

        template<typename T>
        operator std::vector<T>() const {
            if (m_type != Type::V_VECTOR) {
                throw std::logic_error{"cast to vector failed"};
            }
            std::vector<T> res;
            std::transform(static_cast<T_VECTOR*>(m_value)->begin(), static_cast<T_VECTOR*>(m_value)->end(), std::back_inserter(res), [](const auto &i) {return T(i);});
            return res;
        }

        template<typename T>
        operator std::map<std::string, T>() {
            if (m_type != Type::V_MAP) {
                throw std::logic_error{"cast to map failed"};
            }
            std::map<std::string, T> res;
            std::transform(static_cast<T_MAP*>(m_value)->begin(), static_cast<T_MAP*>(m_value)->end(), std::inserter(res, res.begin()),
                [](const auto &val) {return std::make_pair(val.first, T(val.second));});
            return res;
        }

        template<typename T>
        operator std::map<std::string, T>() const {
            if (m_type != Type::V_MAP) {
                throw std::logic_error{"cast to map failed"};
            }
            std::map<std::string, T> res;
            std::transform(static_cast<T_MAP*>(m_value)->begin(), static_cast<T_MAP*>(m_value)->end(), std::inserter(res, res.begin()),
                [](const auto &val) {return std::make_pair(val.first, T(val.second));});
            return res;
        }

    private:
        Type m_type = Any::Type::V_NULL;
        void *m_value = nullptr;
    };

}