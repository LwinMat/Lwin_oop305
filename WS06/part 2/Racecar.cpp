/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include<string>
#include"Car.h"
#include "Racecar.h"

using namespace std;

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		in >> this->m_booster;
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() + (this->m_booster * Car::topSpeed());
	}
}