// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/18/2021
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
	
		string token = str;
		//removing any space in front of the token string
		token.erase(0, next_pos);

		size_t delim = token.find(m_delimiter, 0);
		if (delim != string::npos)
		{
			token = str.substr(next_pos, delim);
		}

			if (token != "")
			{

				next_pos += token.length() + 1;
				//check if the second position after the delimeters is not the same
				if (next_pos != str.length() + 1)
				{
					more = true;
				}
				else
					more = false;
			}
			else 
			{
				more = false;
				throw "no string in between";
			}

			if (this->m_widthField < token.length())
			{
				this->m_widthField = token.length();
			}
		
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
