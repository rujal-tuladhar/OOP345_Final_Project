// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/25/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include<string>
namespace sdds {

	class Station
	{
	private:

		int m_id = 0;
		std::string m_name = "";
		std::string m_desc = "";
		unsigned int m_sn = 0u;
		unsigned int m_noOfitem = 0u;
		static size_t m_widthField;
		static unsigned int id_generator;

	public:


		Station(const std::string& m_value);

		const std::string& getItemName() const;

		unsigned int getNextSerialNumber();

		unsigned int getQuantity() const;

		void updateQuantity();

		void display(std::ostream& os, bool full)const;




	};





}


#endif // !SDDS_STATION_H


