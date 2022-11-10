/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-22-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include "Book.h"

using namespace std;

namespace sdds
{
	Book::Book()
	{
		m_author = " ";
		m_title = " ";
		m_country = " ";
		m_pub_year = 0;
		m_price = 0;
		m_description = " ";
	}

	/*const std::string& Book::author() const
	{
		return this->m_author;
	}*/
	
	const std::string& Book::title() const
	{
		return this->m_title;
	}
	const std::string& Book::country() const
	{
		return this->m_country;
	}
	const size_t& Book::year() const
	{
		return this->m_pub_year;
	}
	double& Book::price()
	{
		return this->m_price;
	}
	const std::string& Book::description() const
	{
		return this->m_description;
	}
	Book::Book(const std::string& strBook)
	{

		// extracting author
		size_t start = 0;
		auto end = strBook.find(',');
		this->m_author = strBook.substr(start, end - start);

		int i = 0;
		while (this->m_author[i] == ' ') {
			++i;
		}
		this->m_author.erase(0, i);


		size_t sizeA = this->m_author.length();
		while (this->m_author[sizeA - 1] == ' ') {
			--sizeA;
		}
		this->m_author.erase(sizeA, this->m_author.length());



		// extracting title
		start = end + 1;
		end = strBook.find(',', start);
		this->m_title = strBook.substr(start, end - start);

		int j = 0;
		while (this->m_title[j] == ' ') {
			++j;
		}
		this->m_title.erase(0, j);

		size_t sizeT = this->m_title.length();
		while (this->m_title[sizeT - 1] == ' ') {
			--sizeT;
		}
		this->m_title.erase(sizeT, this->m_title.length());



		// extracting country
		start = end + 1;
		end = strBook.find(',', start);
		this->m_country = strBook.substr(start, end - start);

		int k = 0;
		while (this->m_country[k] == ' ') {
			++k;
		}
		this->m_country.erase(0, k);

		size_t sizeC = this->m_country.length();
		while (this->m_country[sizeC - 1] == ' ') {
			--sizeC;
		}
		this->m_country.erase(sizeC, this->m_country.length());



		// extracting price
		start = end + 1;
		end = strBook.find(',', start);
		string Price = strBook.substr(start, end - start);
		this->m_price = stod(Price);



		// extracting year
		start = end + 1;
		end = strBook.find(',', start);
		string Year = strBook.substr(start, end - start);
		this->m_pub_year = stoi(Year);



		// extracting description
		start = end + 1;
		end = strBook.find('\0', start);
		this->m_description = strBook.substr(start, end - start);

		int l = 0;
		while (this->m_description[l] == ' ') {
			++l;
		}
		this->m_description.erase(0, l);

		
	}
	std::ostream& operator<<(std::ostream& ostr, const Book& book)
	{
		ostr << setw(20) << book.m_author << " | ";
		ostr << setw(22) << book.m_title << " | ";
		ostr << setw(5) << book.m_country << " | ";
		ostr << setw(4) << book.m_pub_year << " | ";
		ostr << setw(6) << setprecision(2) << fixed << book.m_price << " | ";
		ostr << setw(6) << book.m_description << endl;

		return ostr;
	}
}
