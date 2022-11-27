// Name: Song Joo
// Seneca Student ID: 171443211
// Seneca email: sjoo6@myseneca.ca
// Date of completion: Nov, 26 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string record)
	{
		Utilities extractor{};
		size_t nextPos{};
		size_t itemPos{};
		bool more{};
		std::string temp{};


		m_name = extractor.extractToken(record, nextPos, more);
		m_product = extractor.extractToken(record, nextPos, more);

		itemPos = nextPos;
		while (more) {
			temp = extractor.extractToken(record, itemPos, more);
			m_cntItem += 1;
		}

		m_lstItem = new Item* [m_cntItem];

		for (size_t i = 0; i < m_cntItem; i++) {
			m_lstItem[i] = new Item(extractor.extractToken(record, nextPos, more));
		}

		if (m_widthField < extractor.getFieldWidth()) {
			m_widthField = extractor.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& src)
	{
		throw "ERROR: Cannot make copies.";
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept
	{
		*this = std::move(src);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept
	{
		if (this != &src)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_name = src.m_name;
			m_product = src.m_product;
			m_cntItem = src.m_cntItem;
			m_lstItem = src.m_lstItem;
			
			src.m_lstItem = nullptr;
			src.m_cntItem = 0;
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++) {
			delete m_lstItem[i];
		}

		delete[] m_lstItem;
	}

	bool CustomerOrder::isOrderFilled()const
	{
		bool filled = true;

		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_isFilled == false)
			{
				filled = false;
			}
		}
		return filled;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = true;

		for (size_t i = 0; i < m_cntItem; ++i) {
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
			{
				filled = false;
			}
		}
		return filled;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
			{
				if (station.getQuantity() >= 1)
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os << "    Filled " << m_name << ", ";
					os << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product;
					os << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
				}
			}
		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << "\n";

		for (size_t i = 0; i < m_cntItem; ++i) {
			os << "[";
			os << std::right << std::setw(6);
			os << std::setfill('0') << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os << std::left << std::setw(CustomerOrder::m_widthField);
			os << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";

			if (m_lstItem[i]->m_isFilled) {
				os << "FILLED" << "\n";
			}
			else {
				os << "TO BE FILLED" << "\n";
			}
		}
	}

}