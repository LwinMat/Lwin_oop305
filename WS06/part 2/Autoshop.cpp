/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Autoshop.h"

using namespace std;

namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		this->m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{

		for (auto it = this->m_vehicles.begin(); it != this->m_vehicles.end(); it++) {
			(*it)->display(out);
			cout << endl;
		}
	}

	Autoshop::~Autoshop()
	{
		for (auto it = this->m_vehicles.begin(); it != this->m_vehicles.end(); it++) {
			if (*it != nullptr) {
				delete* it;
			}
		}
	}
	
}