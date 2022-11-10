/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LUXURYVAN_H_
#define SDDS_LUXURYVAN_H_
#include "Van.h"

namespace sdds
{
	class Luxuryvan : public Van
	{
		std::string l_m_consumption{};
	public:
		Luxuryvan(std::istream& in);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}

#endif // !