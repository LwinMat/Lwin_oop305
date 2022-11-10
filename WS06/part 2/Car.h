/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker = { " " };
		std::string m_condition = { " " };
		double m_top_speed = {};
	public:
		Car(std::istream& in);
		std::string condition() const;
		virtual double topSpeed() const;
		virtual void display(std::ostream& out) const;
		void eraseSpaces(std::string& str);
	};
}

#endif // !SDDS_CAR_H_

