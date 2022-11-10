/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-08-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string>
#include<utility>
#include "Restaurant.h"

using namespace std;

namespace sdds
{
	Restaurant::Restaurant()
	{
		for (size_t i = 0; i < this->rest_Count; i++) {
			delete this->pReservation[i];
		}
		this->pReservation = nullptr;
		this->rest_Count = 0;
	}

	Restaurant::Restaurant(const Reservation* reservation[], size_t cnt)
	{
		this->rest_Count = cnt;
		this->pReservation = new Reservation*[this->rest_Count];

		for (size_t i = 0; i < this->rest_Count; ++i) {
			this->pReservation[i] = new Reservation(*reservation[i]);
		}
		
	}


	// copy resources
	Restaurant::Restaurant(const Restaurant& srcR)
	{
		this->pReservation = nullptr;
		*this = srcR;
	}

	Restaurant& Restaurant::operator=(const Restaurant& srcR)
	{
		if (this != &srcR) {
			
			for (size_t i = 0; i < this->rest_Count; i++) {
				delete this->pReservation[i];
			}
			delete[] this->pReservation;

			this->rest_Count = srcR.rest_Count;

			this->pReservation = new Reservation*[srcR.rest_Count];

			for (size_t i = 0; i < srcR.rest_Count; ++i) {
				this->pReservation[i] = new Reservation(*srcR.pReservation[i]);
			}

		}

		return *this;
	}


	// moving resources
	Restaurant::Restaurant(Restaurant&& srcR) noexcept
	{
		*this = std::move(srcR);
	}

	Restaurant& Restaurant::operator=(Restaurant&& srcR) noexcept
	{
		if (this != &srcR) {
			delete[] this->pReservation;
			this->pReservation = srcR.pReservation;
			this->rest_Count = srcR.rest_Count;

			srcR.pReservation = nullptr;
			srcR.rest_Count = 0;
		}
		return *this;
	}



	size_t Restaurant::size()
	{
		return this->rest_Count;
	}


	std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest)
	{
		static size_t COUNT = 0;
		COUNT++;

		ostr << "--------------------------" << endl;
		ostr << "Fancy Restaurant (" << COUNT << ")" << endl;
		ostr << "--------------------------" << endl;

		if (rest.pReservation == nullptr) {
			ostr << "This restaurant is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < rest.rest_Count; i++) {
				if (rest.pReservation[i] != nullptr) {
					ostr << *rest.pReservation[i];
				}
			}
			
		}
		ostr << "--------------------------" << endl;

		return ostr;
	}

	Restaurant::~Restaurant() {
		for (size_t i = 0; i < this->rest_Count; i++) {
			delete this->pReservation[i];
		}
		delete[] this->pReservation;

		this->rest_Count = 0;
	};
	
}