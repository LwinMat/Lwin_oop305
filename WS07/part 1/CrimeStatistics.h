#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include<iostream>
#include<vector>

namespace sdds
{
	// defining a struct
	struct Crime
	{
		std::string province = {""};
		std::string district = {""};
		std::string crime = {""};
		size_t number_of_cases = 0u;
		size_t year = 0u;
		size_t m_resolved = 0u;
	};
	
	class CrimeStatistics
	{
		std::vector<Crime> crimeList;
		unsigned int size = 0u;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const;
		
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif