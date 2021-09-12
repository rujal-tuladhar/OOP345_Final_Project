// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 7/25/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef _SDDS_UTILITIES_H
#define _SDDS_UTILITIES_H
#include<string>

namespace sdds
{
	class Utilities
	{
	private:

		size_t m_widthField = 1;
		static char m_delimiter;

	public:

		void setFieldWidth(size_t newWidth);

		size_t getFieldWidth() const;

		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);

		static char getDelimiter();
	};


}
#endif
