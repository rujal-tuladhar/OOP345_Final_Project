// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/25/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<utility>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include "CustomerOrder.h"
#include"Utilities.h"

using namespace std;
namespace sdds
{

	size_t CustomerOrder::m_widthField = 0u;



	CustomerOrder::CustomerOrder(const std::string &obj)
	{

		string the_obj = obj;
		bool the_value = false;
		size_t the_pos = 0;
		//creating a local object util
		Utilities util;

		this->m_name = util.extractToken(the_obj, the_pos, the_value);
		this->m_product = util.extractToken(the_obj, the_pos, the_value);


		//stating from the third delimeters there is items for us to work with and storing the item 
		//first calucalting the total number of items that we have
	
          	//this is the number of item we have 
			this->m_cntItem = (std::count(obj.begin(), obj.end(), util.getDelimiter())) - 1;

			//creating a dynamic allocation in the array of lstItem;
	
				m_lstItem = new Item * [m_cntItem];

				for (size_t i = 0; i < m_cntItem; i++)
				{
						m_lstItem[i] = new Item(util.extractToken(the_obj, the_pos, the_value));

				}
	

		//updating the width after comaring with the utilities width
		if (util.getFieldWidth() > this->m_widthField)
		{
			this->m_widthField = util.getFieldWidth();
		}


	}
	//move constructor
	CustomerOrder::CustomerOrder(CustomerOrder&& obj) noexcept
	{
		*this = move(obj);
	}
	//move assignment constructor
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj) noexcept
	{

		if (this != &obj)
		{
			if (m_lstItem)
			{
				for (size_t i = 0u; i < m_cntItem; i++)
				{
					delete this->m_lstItem[i];

				}

				delete[] m_lstItem;
			}
			
		
			m_widthField = obj.m_widthField;
			this->m_name = obj.m_name;
			obj.m_name = "";

			this->m_product = obj.m_product;
			obj.m_product = "";

			this->m_cntItem = obj.m_cntItem;
			obj.m_cntItem = 0;

			this->m_lstItem = obj.m_lstItem;
			obj.m_lstItem = nullptr;


		}
		return *this;


	}

	//destructor
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isFilled() const
	{
		bool value = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled == false)
			{
				value = false;
			}
		}

		return value;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool value = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == 0)
			{
				value = false;
				
			}
		}
		return value;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() > 0) {
					station.updateQuantity();

					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;

					os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
				else {
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}

			}

		}

	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product<<endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << setfill('0') << setw(6);
			os<< m_lstItem[i]->m_serialNumber;
			os << "] " << setw(this->m_widthField)<<setfill(' ') << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled == true)
			{
				os << "FILLED" << endl;
			}
			else
			{
				os << "TO BE FILLED" << endl;
			}
		}
		

	}




}
