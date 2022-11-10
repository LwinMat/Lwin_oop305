/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RACECAR_H_
#define SDDS_RACECAR_H_

#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster {};
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif 