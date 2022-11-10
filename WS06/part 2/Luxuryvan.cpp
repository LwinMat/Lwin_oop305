/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include "Van.h"
#include "Luxuryvan.h"

using namespace std;

namespace sdds
{
	Luxuryvan::Luxuryvan(std::istream& in) : Van(in)
	{
		std::string line;
		in >> line;

		if (line == "e") {
			this->l_m_consumption = "electric";
		}
		else if (line == "g") {
			throw std::string("Invalid record!");
		}

	}
	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		out << " electric van  *";
	}
	std::string Luxuryvan::consumption() const
	{
		return this->l_m_consumption;
	}
}
