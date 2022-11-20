// Name: Song Joo
// Seneca Student ID: 171443211
// Seneca email: sjoo6@myseneca.ca
// Date of completion: Nov, 19 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "string"

namespace sdds {
	class Utilities {
		size_t m_widthField = 1;
	public:
		static char m_delimiter; //separates the tokens in any given std::string object
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const; 
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};
	void trim(std::string& res);
}


#endif