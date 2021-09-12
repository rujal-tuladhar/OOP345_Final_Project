// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/25/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef _SDDS_CUSTOMER_ORDER_H
#define _SDDS_CUSTOMER_ORDER_H


#include<string>
#include"Station.h"
namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
		std::string m_name;
		std::string m_product;
		size_t m_cntItem = 0u;
		Item** m_lstItem = nullptr;
		static size_t m_widthField;

	public:
		CustomerOrder() {};
		CustomerOrder(const std::string& obj);

		//since we dot allow the copy operation to occur we do this in our code
		CustomerOrder(const CustomerOrder& obj) { throw"copy constructor not allowed"; }
		//the copy assignment is delted and not used
		CustomerOrder& operator =(const CustomerOrder& obj) = delete;

		//move construtor
		CustomerOrder(CustomerOrder&& obj)	noexcept;

		//move assignmnen constructor
		CustomerOrder& operator =(CustomerOrder&& obj) noexcept;

		~CustomerOrder();

		bool isFilled() const;

		bool isItemFilled(const std::string& itemName)const;

		void fillItem(Station& station, std::ostream& os);


		void display(std::ostream& os)const;


	};

}

#endif