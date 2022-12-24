/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-12-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<numeric>
#include "CrimeStatistics.h"

using namespace std;

namespace sdds
{
	CrimeStatistics::CrimeStatistics(const char* filename)
	{
		try {
			ifstream fileInfo(filename, ios_base::in);

			if (!fileInfo.is_open()) {
				throw std::string("File not Found!");
			}
			else {

				string lineBuffer{}; // record line of a file
				size_t position{};
				Crime tempCrime{};

				string province, district, crime, year, cases, resolved;
				while (getline(fileInfo, lineBuffer)) {


					province = lineBuffer.substr(position, 25);
					position += 25;

					size_t p_position1 = 0;
					while (province[0] == ' ') {
						p_position1++;
					}
					province.erase(0, p_position1);

					size_t theLen1 = province.length();
					while (province[theLen1 - 1] == ' ') {
						--theLen1;
					}
					province.erase(theLen1, province.length());

					tempCrime.province = province;




					district = lineBuffer.substr(position, 25);
					position += 25;

					size_t p_position2 = 0;
					while (district[0] == ' ') {
						p_position2++;
					}
					district.erase(0, p_position2);

					size_t theLen2 = district.length();
					while (district[theLen2 - 1] == ' ') {
						--theLen2;
					}
					district.erase(theLen2, district.length());

					tempCrime.district = district;
					



					crime = lineBuffer.substr(position, 25);
					position += 25;
					size_t p_position3 = 0;
					while (crime[0] == ' ') {
						p_position3++;
					}
					crime.erase(0, p_position3);

					size_t theLen3 = crime.length();
					while (crime[theLen3 - 1] == ' ') {
						--theLen3;
					}
					crime.erase(theLen3, crime.length());

					tempCrime.crime = crime;



					year = lineBuffer.substr(position, 5);
					position += 5;

					size_t p_position4 = 0;
					while (year[0] == ' ') {
						p_position4++;
					}
					year.erase(0, p_position4);

					size_t theLen4 = year.length();
					while (year[theLen4 - 1] == ' ') {
						--theLen4;
					}
					year.erase(theLen4, year.length());

					tempCrime.year = stoi(year);




					cases = lineBuffer.substr(position, 5);
					position += 5;
					size_t p_position5 = 0;
					while (cases[0] == ' ') {
						p_position5++;
					}
					cases.erase(0, p_position5);

					size_t theLen5 = cases.length();
					while (cases[theLen5 - 1] == ' ') {
						--theLen5;
					}
					cases.erase(theLen5, cases.length());

					tempCrime.number_of_cases = stoi(cases);




					resolved = lineBuffer.substr(position, 5);
					position += 5;

					size_t p_position6 = 0;
					while (resolved[0] == ' ') {
						p_position6++;
					}
					resolved.erase(0, p_position6);

					size_t theLen6 = resolved.length();
					while (resolved[theLen6 - 1] == ' ') {
						--theLen6;
					}
					resolved.erase(theLen6, resolved.length());

					tempCrime.m_resolved = stoi(resolved);


					this->crimeList.push_back(tempCrime);
					position = 0;
					tempCrime = {};
				}
				fileInfo.close();
			}
		}
		catch (std::string msg) {
			cout << msg << endl;
		}
		
	}
	void CrimeStatistics::display(std::ostream& out) const
	{
		std::for_each(crimeList.begin(), crimeList.end(), [&out](const Crime crime) { out << crime << endl;});


		auto total_cases = 0;
		auto total_resolved = 0;

		total_cases = std::accumulate(crimeList.begin(), crimeList.end(), total_cases, [](unsigned int num, const Crime& crime){ return crime.number_of_cases + num; });

		total_resolved = std::accumulate(crimeList.begin(), crimeList.end(), 0, [](unsigned int num, const Crime& crime) {return crime.m_resolved + num; });


		cout << "----------------------------------------------------------------------------------------" << endl;
		cout << "|                                                                 Total Crimes:  " << total_cases << " |" << endl;
		cout << "|                                                         Total Resolved Cases:  " << total_resolved << " |" << endl;

		
	}
	
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| ";
		out << left << setw(21) << theCrime.province;

		out << " | ";
		out << left << setw(15) << theCrime.district;
		
		out << " | ";
		out << left << setw(20) << theCrime.crime;

		out << " | ";
		out << right << setw(6) << theCrime.year;

		out << " | ";
		out << right << setw(4) << theCrime.number_of_cases;

		out << " | ";
		out << right << setw(3) << theCrime.m_resolved;
		out << " |";



		return out;
	}


	void CrimeStatistics::sort(std::string field)
	{

		if (field == "Province") {
			std::sort(this->crimeList.begin(), this->crimeList.end(), [field](Crime& a, Crime& b) { return (a.province < b.province); });
		}
		else if (field == "Crime") {
			std::sort(this->crimeList.begin(), this->crimeList.end(), [field](Crime& a, Crime& b) { return a.crime < b.crime; });
		}
		else if (field == "Cases") {
			std::sort(this->crimeList.begin(), this->crimeList.end(), [field](Crime& a, Crime& b) { return a.number_of_cases < b.number_of_cases; });
		}
		else if (field == "Resolved") {
			std::sort(this->crimeList.begin(), this->crimeList.end(), [field](Crime& a, Crime& b) { return a.m_resolved < b.m_resolved; });
		}
	}
	void CrimeStatistics::cleanList()
	{
		
		std::for_each(crimeList.begin(), crimeList.end(), [](Crime& crime) {
				if (crime.crime == "[None]") {
					crime.crime = "";
				}
			});
	}
	bool CrimeStatistics::inCollection(std::string crime) const
	{
		return std::any_of(crimeList.begin(), crimeList.end(), [crime](const Crime& c) {
			return c.crime == crime;
		});

	}
	std::list<Crime> CrimeStatistics::getListForProvince(std::string province) const
	{
		

		auto size = std::count_if(this->crimeList.begin(), this->crimeList.end(), [province](Crime c) { return c.province == province; });
		std::list<Crime> prov_list(size);

		std::copy_if(this->crimeList.begin(), this->crimeList.end()-1, prov_list.begin(), [province](Crime list) { return list.province == province; });

		return prov_list;
	}
}