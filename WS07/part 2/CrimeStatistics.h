/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-12-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include<iostream>
#include<list>
#include<vector>

namespace sdds
{
	// defining a struct
	struct Crime
	{
		std::string province = {""};
		std::string district = {""};
		std::string crime = {""};
		unsigned int number_of_cases = 0;
		unsigned int year = 0;
		unsigned int m_resolved = 0;
	};
	
	class CrimeStatistics
	{
		std::vector<Crime> crimeList;
		unsigned int size = 0u;
	public:
		CrimeStatistics(const char* filename);
		void display(std::ostream& out) const; // changes


		void sort(std::string field);
		void cleanList();
		bool inCollection(std::string crime) const;
		std::list<Crime> getListForProvince(std::string province) const;
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif