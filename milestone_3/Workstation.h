// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 08/1/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H


#include<deque>
#include<string>
#include"Station.h"
#include"CustomerOrder.h"
namespace sdds
{
	//this is availabel to other translation unit as well
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;

	class Workstation:public Station
	{

		private:
			std::deque<CustomerOrder> m_orders;
			Workstation* m_pNextStation=nullptr;

	public:
		//the workstation cannot be copied or moved
		Workstation(const Workstation& obj) = delete;
		Workstation& operator =(const Workstation& obj) = delete;
		Workstation(Workstation&& obj) noexcept = delete;
		Workstation& operator = (const Workstation&& obj) noexcept = delete;

		Workstation& operator +=(CustomerOrder&& newOrders);
		Workstation(const std::string &value);
		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station = nullptr);
		Workstation* getNextStation() const;
		void display(std::ostream& os)const;


	

	};

}

#endif // !SDDS_WORKSTATION_H