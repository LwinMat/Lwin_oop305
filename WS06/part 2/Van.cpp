/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include<string>
#include<iomanip>
#include "Van.h"

using namespace std;

namespace sdds
{
	Van::Van(std::istream& in)
	{
		string  wordLine;

		getline(in, wordLine, ',');
		getline(in, this->m_v_maker, ',');
		eraseSpaces(m_v_maker);

		getline(in, wordLine, ',');
		eraseSpaces(wordLine);
		if (wordLine[0] == 'p' || wordLine[0] == 'm' || wordLine[0] == 'c') {
			this->m_v_type = wordLine[0];
		}
		else
		{
			throw std::string("Invalid record!");
		}

		getline(in, wordLine, ',');
		eraseSpaces(wordLine);
		if (wordLine[0] == 'd' || wordLine[0] == 'p' || wordLine[0] == 'c') {
			this->m_v_purpose = wordLine[0];
		}
		else
		{
			throw std::string("Invalid record!");
		}

		getline(in, wordLine, ',');
		eraseSpaces(wordLine);
		if (wordLine == "") {
			this->m_v_condition = "n";
		}
		else if (wordLine[0] == 'n' || wordLine[0] == 'u' || wordLine[0] == 'b') {
			this->m_v_condition = wordLine[0];
		}
		else
		{
			throw std::string("Invalid record!");
		}

		getline(in, wordLine, ',');
		eraseSpaces(wordLine);
		this->m_v_top_speed = stod(wordLine);

	}
	std::string Van::condition() const
	{
		if (this->m_v_condition == "n") {
			return "new";
		}
		else if (this->m_v_condition == "u") {
			return "used";
		}
		else {
			return "broken";
		}
	}
	double Van::topSpeed() const
	{
		return this->m_v_top_speed;
	}
	std::string Van::type() const
	{
		//return this->m_v_type;
		if (this->m_v_type == "p")
		{
			return "pickup";
		}
		else if (this->m_v_type == "m")
		{
			return "mini-bus";
		}
		else
		{
			return "camper";
		}
	}
	std::string Van::usage() const
	{
		if (this->m_v_purpose == "d")
		{
			return "delivery";
		}
		else if (this->m_v_purpose == "p")
		{
			return "passenger";
		}
		else
		{
			return "camping";
		}
	}
	void Van::display(std::ostream& out) const
	{
		out << "| " << setw(8) << right << this->m_v_maker;
		out << " | " << setw(12) << left << type();
		out << " | " << setw(12) << usage();
		out << " | " << setw(6) << condition();
		out << " | " << setw(6) << fixed << setprecision(2) << topSpeed();
		out << " |";
	}
	void Van::eraseSpaces(std::string& str)
	{
		if (str.find_first_not_of(' ') == string::npos)
		{
			str = "";
			return;
		}
		size_t first = str.find_first_not_of(' ');
		size_t end = str.find_last_not_of(' ');
		str = str.substr(first, end - first + 1);
	}
}
