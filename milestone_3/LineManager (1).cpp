// Name:Rujal Tuladhar
// Seneca Student ID: 154594188
// Seneca email: rtuladhar@myseneca.ca
// Date of completion: 8/01/2021
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include"Utilities.h"
#include<fstream>
#include<algorithm>


using namespace std;
namespace sdds
{
	sdds::LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		size_t next_pos = 0;
		Utilities util;
		string the_line;
		string first_str;
		string next_str;
		bool more;

		Workstation* first_column= nullptr;
		Workstation* second_column =nullptr;


		ifstream the_file(file);

		if (!the_file)
		{
			throw "Error while opening the file";
		}
		else
			 
		{
			while (std::getline(the_file, the_line))
			{
				if (!the_line.empty())
				{
					//extract the first_column
					first_str = util.extractToken(the_line, next_pos, more);

					first_column = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {return stations->getItemName() == first_str; });

					activeLine.push_back(first_column);
					//if the second column present
					if (more)

					{
						next_str = util.extractToken(the_line, next_pos, more);

						second_column = *find_if(stations.begin(), stations.end(), [&](Workstation* stations) {return stations->getItemName() == next_str; });
						//pointing to the next adress

						first_column->setNextStation(second_column);
					}
				}
				//for the first station;
			}


			m_firstStation = activeLine.front();
		}
		the_file.close();
		m_cntCustomerOrder = pending.size();
				
	}
			
	

	void LineManager::linkStations()
	{
		vector<Workstation*>temp;
		Workstation* stn = m_firstStation;

		while (stn != nullptr)
		{
			temp.push_back(stn);
			stn = stn->getNextStation();
		}

		//passsing the vector container after to the activeLine container after reordering
		activeLine = temp;
	}

	bool LineManager::run(std::ostream& os)
	{
		static size_t counter = 0;
		

		os << "Line Manager Iteration: " << ++counter << endl;
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
		}

		for (auto value : activeLine)
		{
			value->fill(os);
		}
		for (auto value : activeLine)
		{
			value->attemptToMoveOrder();

		}
		//calcalting the customer order after moving from the container
		if ( m_cntCustomerOrder == completed.size() + incomplete.size())
		{
			return true;
		}else
		return false;

	}

	void LineManager::display(std::ostream& os) const
	{
		for_each(activeLine.begin(), activeLine.end(), [&os](Workstation* w_ptr) {w_ptr->display(os); });
	}

}
