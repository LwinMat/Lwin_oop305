/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-22-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<iomanip>
#include "Movie.h"

using namespace std;

namespace sdds
{
	Movie::Movie()
	{
		this->m_description = " ";
		this->m_title = " ";
		this->m_year_release = 0;
	}
	const std::string& Movie::title() const
	{
		return this->m_title;
	}
	Movie::Movie(const std::string& strMovie)
	{
		size_t start = 0;
		size_t end = strMovie.find(',');
		this->m_title = strMovie.substr(start, end-start);

		int i = 0;
		while (this->m_title[i] == ' ') {
			++i;
		}
		this->m_title.erase(0, i);

		size_t SizeTitle = this->m_title.length();
		while (this->m_title[SizeTitle - 1] == ' ') {
			--SizeTitle;
		}
		this->m_title.erase(SizeTitle, this->m_title.length());



		start = end + 1;
		end = strMovie.find(',', start);
		string Year = strMovie.substr(start, end - start);
		this->m_year_release = stoi(Year);


		/*start = end + 1;
		end = strMovie.find(',', start);
		this->m_description = strMovie.substr(start);

		int j = 0;
		while (this->m_description[j] == ' ')
		{
			++j;
		}
		this->m_description.erase(0, j);*/

		start = end + 1;
		end = strMovie.find('\0', start);
		this->m_description = strMovie.substr(start, end - start);

		int j = 0;
		while (this->m_description[j] == ' ') {
			++j;
		}
		this->m_description.erase(0, j);
	}
	std::ostream& operator<<(std::ostream& os, const Movie& movie)
	{
		os << setw(40) << movie.m_title << " | ";
		os << setw(4) << movie.m_year_release << " | ";
		os << movie.m_description << endl;

		return os;
	}
}