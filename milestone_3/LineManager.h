// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 8/01/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINE_MANAGER_H
#define SDDS_LINE_MANAGER_H
#include"Workstation.h"
#include<vector>

namespace sdds
{

	class LineManager
	{
	private:
		std::vector<Workstation*> activeLine;
		size_t m_cntCustomerOrder;
		Workstation* m_firstStation;


	public:
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);

		void linkStations();
		bool run(std::ostream& os);

		void display(std::ostream& os) const;


	};


}

#endif // !SDDS_LINE_MANAGER_H
