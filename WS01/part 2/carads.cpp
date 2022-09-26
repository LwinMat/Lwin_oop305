/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-16-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctype.h>

#include<string>
#include<cstring>
#include "carads.h"

using namespace std;


// the global variables declared from carads.h with 'extern' are and always defined in cpp file
double g_taxrate = 0;
double g_discount = 0;

namespace sdds
{

	void listArgs(int argc, char** argv)
	{
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (auto i = 0; i < argc; i++) {
			cout << "  " << i + 1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n\n";
	}
	
	Cars::Cars()
	{
		delete[] m_brand;
		m_brand = nullptr;
		m_model[0] = '\0';
		m_manufacture_year = 0;
		m_price = 0;
		m_status = 'U';
		m_promotion_discount = false;
	}
	void Cars::read(std::istream& is)
	{
		// TODO: insert return statement here


		if (is)
		{
			char getStatus{};
			string getBrand;
			string getModel;
			int getManufactureYear = 0;
			double getPrice = 0;
			char discount_answer{ 'N' };
			char delim{ '\0' };

			is >> getStatus >> delim;
			
			getline(is, getBrand, ',');
			getline(is, getModel, ',');

			is >> getManufactureYear >> delim;

			is >> getPrice >> delim;

			
			is >> discount_answer;

			if (!is) {
				is.clear();
				//Car();'=
				this->clear();
			}
			else {
				m_status = getStatus;
				delete[] m_brand;
				m_brand = new char[getBrand.length() + 1];
				strcpy(m_brand, getBrand.c_str());

				strcpy(m_model, getModel.c_str());

				m_manufacture_year = getManufactureYear;

				m_price = getPrice;

				m_promotion_discount = (discount_answer == 'Y') ? true : false;
			}

			//m_promotion_discount = (discount_answer == 'Y') ? true : false;
			is.ignore();



		}
	}
	void Cars::display(bool reset) const
	{
		static int Counter = 0;
		if (reset == true) {

			Counter = 0;
		}

		cout.width(2);
		cout.setf(ios::left);
		cout << ++Counter;
		cout.unsetf(ios::left);
		cout << ". ";

		if (!(strlen(this->m_brand) > 0))
		{
			cout << "no car";
		}
		else
		{
			cout.width(10);
			cout.setf(ios::left);
			cout << m_brand;
			cout.unsetf(ios::left);


			cout << "| ";
			cout.width(15);
			cout.setf(ios::left);
			cout << m_model;
			cout.unsetf(ios::left);



			cout << "| ";
			cout << m_manufacture_year;
			cout << " | ";



			cout.setf(ios::right);
			cout.width(11);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_price * (1 + g_taxrate);
			cout.unsetf(ios::fixed);
			cout.unsetf(ios::right);


			if (m_promotion_discount == true) {
				cout << "|";
				cout.width(12);
				cout.setf(ios::right);
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << m_price * (1 + g_taxrate) * (1 - g_discount);
				cout.unsetf(ios::fixed);
				cout.unsetf(ios::right);

			}
			else if (m_promotion_discount == false) {
				cout << "|";
			}
		}
		cout << endl;

	}
	char Cars::getStatus() const
	{
		return m_status;
	}
	void Cars::clear()
	{
		delete[] m_brand;
		m_brand = nullptr;
		m_model[0] = '\0';
		m_manufacture_year = 0;
		m_price = 0;
		m_status = 'U';
		m_promotion_discount = false;
	}
	Cars::Cars(const Cars& otherCar)
	{
		this->m_brand = nullptr;
		*this = otherCar;
	}
	Cars& Cars::operator=(const Cars& otherCar)
	{
		// TODO: insert return statement here
		if (this != &otherCar) {
			delete[] this->m_brand;
			this->m_brand = nullptr;

			this->m_brand = new char[strlen(otherCar.m_brand) + 1];
			strcpy(this->m_brand, otherCar.m_brand);


			strcpy(m_model, otherCar.m_model);
			m_manufacture_year = otherCar.m_manufacture_year;
			m_price = otherCar.m_price;
			m_status = otherCar.m_status;
			m_promotion_discount = otherCar.m_promotion_discount;
		}

		return *this;
	}
	Cars::~Cars()
	{
		delete[] m_brand;
		m_brand = nullptr;
		m_model[0] = '\0';
		m_manufacture_year = 0;
		m_price = 0;
		m_status = 'U';
		m_promotion_discount = false;
	}

	Cars::operator bool() const
	{
		return this->m_status == 'N';
	}


	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}

	void operator>>(const Cars& car1, Cars& car2) {
		car2 = car1;
	}
}