#include "CustomerOrder.h"

namespace sdds {
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder(const std::string)
	{
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

		}

		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{

	}

	bool CustomerOrder::isOrderFilled()const
	{
		return false;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		return false;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
	}

	void CustomerOrder::display(std::ostream& os) const
	{
	}

}