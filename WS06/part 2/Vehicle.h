/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

namespace sdds
{
	class Vehicle
	{
	public:
		virtual double topSpeed() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual std::string condition() const = 0;
		virtual ~Vehicle() {};
	};
}

#endif
