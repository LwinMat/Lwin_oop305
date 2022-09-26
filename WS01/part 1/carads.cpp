#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctype.h>
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
			cout << "  " << i+1 << ": " << argv[i] << endl;
		}
		cout << "--------------------------\n\n";
	}
	Cars::Cars()
	{
		m_brand[0] = '\n';
		m_model[0] = '\n';
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
			char delim{'\0'};

			is >> m_status >> delim;
			is.getline(m_brand, 11, ',');
			is.getline(m_model, 16, ',');

			is >> m_manufacture_year >> delim;

			is >> m_price >> delim;

			char discount_answer{'N'};
			is >> discount_answer;

			m_promotion_discount = (discount_answer == 'Y') ? true : false;
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
			else if(m_promotion_discount == false){
				cout << "|";
			}
		}
		cout << endl;

	}
	char Cars::getStatus() const
	{
		return m_status;
	}
}