#include<iostream>

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
		}
	}
	
}