/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_AUTOSHOP_H_
#define SDDS_AUTOSHOP_H_

/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<vector>
#include<list>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		//new member functions
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
				for (auto item : m_vehicles) {
					if (test(item) == true) {
						vehicles.push_back(item);
					}
				}
			
		}
	};
}

#endif // !SDDS_AUTOSHOP_H_
