// Name: Song Joo
// Seneca Student ID: 171443211
// Seneca email: sjoo6@myseneca.ca
// Date of completion: Nov, 19 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include "Utilities.h"
#include "string"

namespace sdds {
	class Station {
		int m_id{};
		std::string m_name{};
		std::string m_desc{};
		size_t m_serialNumber{};
		size_t m_noOfItem{};
		static size_t m_widthField;
		static unsigned id_generator;
	public:
		Station(const std::string);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}


#endif