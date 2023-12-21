#include <stdexcept>
#include <scpp/string/string.h>
#include <scpp/any/any.h>

using namespace scpp;

Any::Any() : m_type(Type::V_NULL)
{
}

Any::Any(bool value) : m_type(Type::V_BOOL)
{
	std::get<std::string>(m_value) = value ? "true" : "false";
}

Any::Any(int value) : m_type(Type::V_NUMBER)
{
	std::get<std::string>(m_value) = std::to_string(value);
}

Any::Any(double value) : m_type(Type::V_NUMBER)
{
	std::get<std::string>(m_value) = rtrim(std::to_string(value), "0");
}

Any::Any(const char *value) : m_type(Type::V_STRING)
{
	std::get<std::string>(m_value) = value;
}

Any::Any(const std::string & value) : m_type(Type::V_STRING)
{
	std::get<std::string>(m_value) = value;
}

Any::Any(const T_VECTOR &any) : m_type(Type::V_VECTOR) {
	std::get<T_VECTOR*>(m_value) = new T_VECTOR(any);
}

Any::Any(const T_MAP &any): m_type(Type::V_MAP) {
	std::get<T_MAP*>(m_value) = new T_MAP(any);
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

Any & Any::operator = (bool value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	m_type = Type::V_BOOL;
	std::get<std::string>(m_value) = value ? "true" : "false";
	return *this;
}

Any & Any::operator = (int value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	m_type = Type::V_NUMBER;
	std::get<std::string>(m_value) = std::to_string(value);
	return *this;
}

Any & Any::operator = (double value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	m_type = Type::V_NUMBER;
	std::get<std::string>(m_value) = rtrim(std::to_string(value), "0");
	return *this;
}

Any & Any::operator = (const char *value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	m_type = Type::V_STRING;
	std::get<std::string>(m_value) = value;
	return *this;
}

Any & Any::operator = (const std::string & value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	m_type = Type::V_STRING;
	std::get<std::string>(m_value) = value;
	return *this;
}

Any & Any::operator = (const Any & value)
{
	if (m_type == Type::V_VECTOR) {
		delete std::get<T_VECTOR*>(m_value);
	} else if (m_type == Type::V_MAP) {
		delete std::get<T_MAP*>(m_value);
	}
	if (value.m_type == Type::V_VECTOR) {
		std::get<T_VECTOR*>(m_value) = new T_VECTOR(*std::get<T_VECTOR*>(value.m_value));
	} else if (value.m_type == Type::V_MAP) {
		std::get<T_MAP*>(m_value) = new T_MAP(*std::get<T_MAP*>(value.m_value));
	} else {
		m_type = value.m_type;
		std::get<std::string>(m_value) = std::get<std::string>(value.m_value);
	}
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
	if (std::get<std::string>(m_value) == "true") {
		return true;
	} else {
		return false;
	}
}

Any::operator bool() const
{
	if (m_type != Type::V_BOOL) {
		throw std::logic_error{"cast to bool failed"};
	}
	if (std::get<std::string>(m_value) == "true") {
		return true;
	} else {
		return false;
	}
}


Any::operator int()
{
	if (m_type != Type::V_NUMBER) {
		throw std::logic_error{"cast to number failed"};
	}
	return std::stoi(std::get<std::string>(m_value));
}

Any::operator int() const
{
	if (m_type != Type::V_NUMBER) {
		throw std::logic_error{"cast to number failed"};
	}
	return std::stoi(std::get<std::string>(m_value));
}

Any::operator double()
{
	if (m_type != Type::V_NUMBER) {
		throw std::logic_error{"cast to number failed"};
	}
	return std::stod(std::get<std::string>(m_value));
}

Any::operator double() const
{
	if (m_type != Type::V_NUMBER) {
		throw std::logic_error{"cast to number failed"};
	}
	return std::stod(std::get<std::string>(m_value));
}

Any::operator std::string()
{
	if (m_type != Type::V_STRING) {
		throw std::logic_error{"cast to string failed"};
	}
	return std::get<std::string>(m_value);
}

Any::operator std::string() const
{
	if (m_type != Type::V_STRING) {
		throw std::logic_error{"cast to string failed"};
	}
	return std::get<std::string>(m_value);
}

Any::operator T_VECTOR() {
	if (m_type != Type::V_VECTOR) {
		throw std::logic_error{"cast to vector failed"};
	}
	return *std::get<T_VECTOR*>(m_value);
}
Any::operator T_VECTOR() const {
	if (m_type != Type::V_VECTOR) {
		throw std::logic_error{"cast to vector failed"};
	}
	return *std::get<T_VECTOR*>(m_value);
}

Any::operator T_MAP() {
	if (m_type != Type::V_MAP) {
		throw std::logic_error{"cast to map failed"};
	}
	return *std::get<T_MAP*>(m_value);
}
Any::operator T_MAP() const {
	if (m_type != Type::V_MAP) {
		throw std::logic_error{"cast to map failed"};
	}
	return *std::get<T_MAP*>(m_value);
}