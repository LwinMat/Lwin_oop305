/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VAN_H_
#define SDDS_VAN_H_

#include "Vehicle.h"

namespace sdds
{
	class Van : public Vehicle
	{
		std::string m_v_maker;
		std::string m_v_type;
		std::string m_v_condition;
		std::string m_v_purpose;
		double m_v_top_speed;
	public:
		Van(std::istream& in);
		std::string condition() const;
		virtual double topSpeed() const;
		virtual std::string type() const;
		virtual std::string usage() const;
		virtual void display(std::ostream& out) const;
		void eraseSpaces(std::string& str);
	};
}

#endif // !SDDS_VAN_H_


