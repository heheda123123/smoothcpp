#pragma once

#include <vector>
#include <string>

namespace scpp
{
	std::string to_lower(std::string input);
	std::string to_upper(std::string input);
	
	std::string ltrim(const std::string& input, const std::string& trims = " ");
	std::string rtrim(const std::string& input, const std::string& trims = " ");
	std::string trim(const std::string& input, const std::string& trims = " ");
	
	std::vector<std::string> split(const std::string& input, const std::string& separator = " ");
	
	std::string join(const std::vector<std::string> &input, const std::string & separator);
	std::string join(const std::vector<std::string> &input, char separator);
	
	bool has_prefix(const std::string & input, const std::string & prefix);
	bool has_suffix(const std::string & input, const std::string & suffix);
	bool contains(std::string_view str, std::string_view substr);
	
	std::string capitalize(const std::string & input);
	std::string format(const char *format,...);

	
}