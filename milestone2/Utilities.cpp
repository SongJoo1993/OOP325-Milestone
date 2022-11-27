// Name: Song Joo
// Seneca Student ID: 171443211
// Seneca email: sjoo6@myseneca.ca
// Date of completion: Nov, 26 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		more = false;
		std::string token{};
		size_t pos = str.find(m_delimiter, next_pos);
		token = str.substr(next_pos, pos - next_pos);
		if (pos == next_pos) {
			throw("ERROR: No token.");
		}
		else if (pos != std::string::npos) {
			next_pos = pos + 1;
			more = true;
		}
		if (getFieldWidth() < token.length()) {
			setFieldWidth(token.length());
		}
		trim(token);
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
	void trim(std::string& res)
	{
		std::string whitespaces(" \t");
		res.erase(0, res.find_first_not_of(whitespaces));
		res.erase(res.find_last_not_of(whitespaces) + 1);
	}
}
