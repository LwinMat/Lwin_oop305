#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include<iostream>
#include <string>
#include<cstring>
#include<iomanip>

namespace sdds
{
	class Reservation
	{
		std::string m_reservation_id{};
		std::string m_name_on_reservation{};
		std::string m_email{};
		int m_number{};
		int m_day{};
		int m_hour{};
	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
	
		//queries
		std::string getId() const;
		std::string getName() const;
		std::string getEmail() const;
		int getNumber() const;
		int getDay() const;
		int getHour() const;
	};

	std::ostream& operator<<(std::ostream& os, Reservation& reservation);

}

#endif