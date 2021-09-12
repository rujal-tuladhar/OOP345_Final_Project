// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/25/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Utilities.h"
using namespace std;


namespace sdds
{
	//no need to mention that static in ths section
	char Utilities::m_delimiter = ' ';
	//the width_field is already defined

	//sets the field recive at the parameter
	void sdds::Utilities::setFieldWidth(size_t newWidth)
	{
		this->m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return this->m_widthField;
	}
	//string to extract the token from the str
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{

		string token;
		size_t pos = next_pos;
		next_pos = str.find(m_delimiter, pos);

		if (pos == next_pos) {
			more = false;
			throw "Error no token found";
		}
		else if (next_pos == string::npos)

		{
			token = str.substr(pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = false;
		}
		else 
		{ 
			token = str.substr(pos, next_pos - pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = true;
		}
		
		next_pos++;

		
		return token;


	}
	//gets the delimeter in the parameter as recieved

	void Utilities::setDelimiter(char newDelimiter)
	{

		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

}
