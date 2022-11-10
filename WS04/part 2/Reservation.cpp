/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-08-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
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
		this->m_reservation_id = " ";
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

	


	std::ostream& operator<<(std::ostream& os, const Reservation& reservation)
	{
		//os << "operator<< not implemented yet\n";
		//os << setw(10) << right << reservation.;

		os << "Reservation " << right << setw(10) << reservation.m_reservation_id << ": " << setw(20) << reservation.m_name_on_reservation;
		os << "  " << left << setw(20) << '<' + reservation.m_email + '>';
		os << "    ";
		if (reservation.m_hour >= 6 && reservation.m_hour <= 9) {
			os << "Breakfast";
		}
		else if (reservation.m_hour >= 11 && reservation.m_hour <= 15) {
			os << "Lunch";
		}
		else if (reservation.m_hour >= 17 && reservation.m_hour <= 21) {
			os << "Dinner";
		}
		else {
			os << "Drinks";
		}

		os << " on day " << reservation.m_day << " @ " << reservation.m_hour << ":00 for " << reservation.m_number << (reservation.m_number == 1 ? " person." : " people.");
		os << endl;

		return os;
		
	}
}