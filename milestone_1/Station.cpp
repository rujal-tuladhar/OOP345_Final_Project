// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/18/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include<iomanip>
#include<algorithm>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
	
	size_t Station::m_widthField = 0u;
	unsigned int Station::id_generator = 0u;



	Station::Station(const std::string& m_value)
	{
		
		
		string the_line;
		size_t pos = 0;
		bool more;
		//creating an local object from the utilicites class
		Utilities util;

		the_line = m_value;
		//we need to extract the value as name,sn, noOfitem, desc
		m_name = util.extractToken(the_line, pos, more);

	    m_sn = stoi(util.extractToken(the_line, pos, more));
		
        m_noOfitem = stoi(util.extractToken(the_line, pos, more));
		
		//changing the size of the field before extracting the description part
		if (Station::m_widthField < util.getFieldWidth())
		{
			Station::m_widthField = util.getFieldWidth();
		}

		m_desc = util.extractToken(the_line, pos, more);

		//the id is generated automatically with each call 
		m_id = ++id_generator;
		
	}
	const std::string& Station::getItemName() const
	{
		return this->m_name;
	}
	unsigned int Station::getNextSerialNumber()
	{
		return m_sn++;
		
	}
	unsigned int Station::getQuantity() const
	{
		return m_noOfitem;
	}
	void Station::updateQuantity()
	{
		if (this->m_noOfitem > 0)
		{
			--m_noOfitem;
		}
		else
			m_noOfitem = 0;
	}

	void Station::display(std::ostream& os, bool full) const
	{
		if (full == 0)
		{
			os << "[" << setw(3) << setfill('0')<<right << this->m_id;
			os << "] " << "Item: " << setw(15) <<setfill(' ') <<left<< this->m_name;
			os<< "[" << setw(6)<<setfill('0')<<right<<this->m_sn << "]";
		}
		else
			if (full == 1)
			{
				os << "[" << setw(3) << setfill('0') << right<< this->m_id;
				os << "] Item: " << setw(15)<<setfill(' ')<< left<<this->m_name << "[";
				os << setw(6) << setfill('0') << right<<this->m_sn << "] Quantity: ";
				os <<setw(15)<<setfill(' ')<<left<< this->m_noOfitem << "Description: ";
				os<< this->m_desc;
			}
		
		
		os << endl;


	}

	

	

}