#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include<iomanip>
#include "Reservation.h"

using namespace std;

namespace sdds
{
	Reservation::Reservation()
	{
		this->m_reservation_id[0]={};
		this->m_name_on_reservation = " ";
		this->m_email = " ";
		this->m_number = 0;
		this->m_day = 0;
		this->m_hour = 0;
	}
	void Reservation::update(int day, int time)
	{
		if ((day > 1 || day < 28) && (time > 1 || time < 24)) {
			this->m_day = day;
			this->m_hour = time;
		}
	}
	Reservation::Reservation(const std::string& res)
	{
		

		size_t start = 0;
		auto end = res.find(':');
		this->m_reservation_id = res.substr(start, end-start);

		int i = 0;
		while (this->m_reservation_id[i] == ' ')
			++i;
		this->m_reservation_id.erase(0, i);


		size_t SizeR = this->m_reservation_id.length();
		while (this->m_reservation_id[SizeR-1] == ' ') {
			--SizeR;
		}
		this->m_reservation_id.erase(SizeR, this->m_reservation_id.length());





		start = end + 1;
		end = res.find(',', start);
		this->m_name_on_reservation = res.substr(start, end - start);

		int j = 0;
		while (this->m_name_on_reservation[j] == ' ')
		++j;
		this->m_name_on_reservation.erase(0, j);

		size_t SizeN = this->m_name_on_reservation.length();
		while (this->m_name_on_reservation[SizeN - 1] == ' ') {
			--SizeN;
		}
		this->m_name_on_reservation.erase(SizeN, this->m_name_on_reservation.length());





		start = end + 1;
		end = res.find(',', start);
		this->m_email = res.substr(start, end - start);

		int k = 0;
		while (this->m_email[k] == ' ')
		++k;
		this->m_email.erase(0, k);

		size_t SizeEm = this->m_email.length();
		while (this->m_email[SizeEm - 1] == ' ') {
			--SizeEm;
		}
		this->m_email.erase(SizeEm, this->m_email.length());



		start = end + 1;
		end = res.find(',', start);
		string numPple = res.substr(start, end - start);
		this->m_number = stoi(numPple);

		start = end + 1;
		end = res.find(',', start);
		string day = res.substr(start, end - start);
		this->m_day = stoi(day);


		start = end + 1;
		end = res.find(',', start);
		string hour = res.substr(start, end - start);
		this->m_hour = stoi(hour);


	}

	std::string Reservation::getId() const
	{
		return this->m_reservation_id;
	}

	std::string Reservation::getName() const
	{
		return this->m_name_on_reservation;
	}

	std::string Reservation::getEmail() const
	{
		return this->m_email;
	}

	int Reservation::getNumber() const
	{
		return this->m_number;
	}

	int Reservation::getDay() const
	{
		return this->m_day;
	}

	int Reservation::getHour() const
	{
		return this->m_hour;
	}



	std::ostream& operator<<(std::ostream& os, Reservation& reservation)
	{
		//os << "operator<< not implemented yet\n";
		//os << setw(10) << right << reservation.;

		os << "Reservation " << right << setw(10) << reservation.getId() << ": " << setw(20) << reservation.getName();
		os << "  " << left << setw(20) << '<' + reservation.getEmail() + '>';
		os << "    ";
		if (reservation.getHour() >= 6 && reservation.getHour() <= 9) {
			os << "Breakfast";
		}
		else if (reservation.getHour() >= 11 && reservation.getHour() <= 15) {
			os << "Lunch";
		}
		else if (reservation.getHour() >= 17 && reservation.getHour() <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << reservation.getDay() << " @ " << reservation.getHour() << ":00 for " << reservation.getNumber() << (reservation.getNumber() == 1 ? " person." : " people.");
		os << endl;

		return os;
		
	}
}