// Name: Song Joo
// Seneca Student ID: 171443211
// Seneca email: sjoo6@myseneca.ca
// Date of completion: Nov, 26 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include "Station.h"

namespace sdds {
	size_t Station::m_widthField = 0;
	unsigned Station::id_generator = 0;

	Station::Station(const std::string record)
	{
		Utilities extractor{};
		size_t nextPos{};
		bool more{};
		std::string num{};


		m_name = extractor.extractToken(record, nextPos, more);
		num = extractor.extractToken(record, nextPos, more);
		m_serialNumber = std::stoi(num);
		num = extractor.extractToken(record, nextPos, more);
		m_noOfItem = std::stoi(num);
		
		if (m_widthField < extractor.getFieldWidth()) {
			m_widthField = extractor.getFieldWidth();
		}

		m_desc = extractor.extractToken(record, nextPos, more);
		m_id = id_generator++;
	}

	const std::string& Station::getItemName() const
	{
		return m_name;
	}

	size_t Station::getNextSerialNumber()
	{
		return m_serialNumber++;
	}

	size_t Station::getQuantity() const
	{
		return m_noOfItem;
	}

	void Station::updateQuantity()
	{	
		if (m_noOfItem > 0) {
			m_noOfItem -= 1;
		}
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (!full) 
		{
			os.width(3);
			os.fill('0');
			os << m_id + 1 << " | ";
			os.width(m_widthField);
			os.fill(' ');
			os.setf(std::ios::left);
			os << m_name << " | ";
			os.unsetf(std::ios::left);
			os.width(6);
			os.fill('0');
			os << m_serialNumber << " | " << std::endl;
		}
		else 
		{
			os.width(3);
			os.fill('0');
			os << m_id + 1 << " | ";
			os.width(m_widthField);
			os.fill(' ');
			os.setf(std::ios::left);
			os << m_name << " | ";
			os.unsetf(std::ios::left);
			os.width(6);
			os.fill('0');
			os << m_serialNumber << " | ";
			os.width(4);
			os.fill(' ');
			os << m_noOfItem << " | ";
			os << m_desc << std::endl;
		}
	}
}