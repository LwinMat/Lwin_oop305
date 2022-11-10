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
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(std::istream& in)
	{
		std::string WordLine{};

		// extracting maker
		in.ignore(10, ',');
		getline(in, this->m_maker, ',');
		eraseSpaces(m_maker);


		// extractig condition
		getline(in, WordLine, ',');
		eraseSpaces(WordLine);
		if (WordLine == "" || WordLine == " ") {
			this->m_condition = "n";
		}
		else if (WordLine[0] == 'n' || WordLine[0] == 'u' || WordLine[0] == 'b') {
			this->m_condition = WordLine[0];
		}
		else {
			throw std::string("Invalid record!");
		}


		// extracting speed
		getline(in, WordLine, ',');
		eraseSpaces(WordLine);

		if (!isdigit(WordLine[0])) {
			throw std::string("Invalid record!");
		}
		else {
			this->m_top_speed = stod(WordLine);
		}

	}



	string Car::condition() const
	{
		if (this->m_condition == "n") {
			return "new";
		}
		else if (this->m_condition == "u") {
			return "used";
		}
		else {
			return "broken";
		}
	}

	double Car::topSpeed() const
	{
		return this->m_top_speed;
	}

	void Car::display(std::ostream& out) const
	{
		
		
			out << "| " << setw(10) << right << this->m_maker;
			out << " | " << setw(6) << left << condition();
			out << " | " << setw(6) << setprecision(2) << fixed << topSpeed();
			out << " |";
	
		
	}

	void Car::eraseSpaces(std::string& str)
	{
		if (str.find_first_not_of(' ') == string::npos)
		{
			str = "";
			return;
		}
		size_t ind = str.find_first_not_of(' ');
		size_t end = str.find_last_not_of(' ');
		str = str.substr(ind, end - ind + 1);
		

	}


} 