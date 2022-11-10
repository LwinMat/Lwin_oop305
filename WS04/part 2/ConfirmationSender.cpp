/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-08-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include<iostream>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		this->m_resCS = nullptr;
		this->m_size = 0;
	}


	// copy resources
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& srcR)
	{
		this->m_resCS = nullptr;
		*this = srcR;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& srcR)
	{
		if (this != &srcR) {
			this->m_size = srcR.m_size;

			this->m_resCS = new const Reservation*[srcR.m_size];

			for (size_t i = 0; i < this->m_size; i++) {
				this->m_resCS[i] = srcR.m_resCS[i];
			}
		}

		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& srcR) noexcept
	{
		*this = std::move(srcR);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& srcR) noexcept
	{
		if (this != &srcR) {
			delete[] this->m_resCS;

			this->m_size = srcR.m_size;
			this->m_resCS = srcR.m_resCS;

			srcR.m_resCS = nullptr;
			srcR.m_size = 0;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] this->m_resCS;
		this->m_size = 0;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		//bool Res_not_exist = true;

		const Reservation** TempCS = nullptr;

		for (size_t i = 0; i < this->m_size; ++i) {
			if (this->m_resCS[i] == &res) {
				return *this;
			}
		}

		TempCS = new const Reservation * [this->m_size + 1];

		for (size_t i = 0; i < this->m_size; ++i) {
			TempCS[i] = this->m_resCS[i];
		}
		TempCS[this->m_size] = &res;
		this->m_size++;
		delete[] this->m_resCS;
		this->m_resCS = TempCS;

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (size_t i = 0; i < this->m_size; ++i) {
			if (this->m_resCS[i] == &res) {
				this->m_resCS[i] = nullptr;
			}
		}

		return *this;
	}


	std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender& ConSend)
	{
		// TODO: insert return statement here

		ostr << "--------------------------" << endl;
		ostr << "Confirmations to Send" << endl;
		ostr << "--------------------------" << endl;

		if (ConSend.m_size == 0) {
			ostr << "There are no confirmations to send!" << endl;
		}
		else {
			for (size_t i = 0; i < ConSend.m_size; i++) {
				if (ConSend.m_resCS[i] != nullptr) {
					ostr << *ConSend.m_resCS[i];
				}
			}

		}
		ostr << "--------------------------" << endl;

		return ostr;
	}

}