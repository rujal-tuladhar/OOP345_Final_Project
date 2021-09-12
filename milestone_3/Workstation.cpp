// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 08/1/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#define _CRT_SECURE_NO_WARNINGS
#include "Workstation.h"
#include<iostream>

using namespace std;

namespace sdds
{
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};

	Workstation& Workstation::operator+=(CustomerOrder&& newOrders)
	{
		m_orders.push_back(std::move(newOrders));
		return *this;
	}

	//passing the argument to the base class of the string
	sdds::Workstation::Workstation(const std::string& value) :Station(value)
	{}

	void sdds::Workstation::fill(std::ostream& os)
	{

		if (!m_orders.empty())
		{
			m_orders.front().fillItem(*this,os);
		}

	}
	//the attempt to move_order
	bool Workstation::attemptToMoveOrder()
	{
		if (m_orders.size() > 0)
		{
			if (m_orders.front().isItemFilled(getItemName()) || getQuantity() <= 0) 
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders.front());
					m_orders.pop_front();
					return true;

				}
				else
				{
					if (m_orders.front().isFilled())
					{
						completed.push_back(move(m_orders.front()));
						m_orders.pop_front();
					}
					else
					{
						incomplete.push_back(move(m_orders.front()));
						m_orders.pop_front();
					}
					
					return true;
				}
			}
		}

		return false;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;

	}

	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << getItemName() << " --> " << m_pNextStation->getItemName() << endl;

		}
		else
		{
			os << getItemName() << " --> End of Line" << endl;
		}
	}



}
