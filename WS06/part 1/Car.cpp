#include<iostream>
#include<string>
#include<iomanip>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(std::istream& in)
	{
		auto eraseSpace = [](string& line) {
			bool doneWithSpaces = false;

			while (doneWithSpaces == false) {
				if (line[0] == ' ') {
					line.erase(0, line.find_first_not_of(' '));
				}
				else if (line[line.length() - 1] == ' ') {
					line.erase(line.find_last_not_of(' ') + 1);
				}
				else {
					doneWithSpaces = true;
				}
			}

			return line;
		};


		try {
			string singleLine = " ";

			// EXTRACTING MAKER
			getline(in, singleLine, ',');
			this->m_maker = eraseSpace(singleLine);


			// EXTRACTING CONDITION
			getline(in, singleLine, ',');
			string singleChar = eraseSpace(singleLine);
			if (singleChar == "n") {
				this->m_condition = "new";
			}
			else if (singleChar == "u") {
				this->m_condition = "used";
			}
			else if (singleChar == "b") {
				this->m_condition = "broken";
			}


			// EXTRACTING TOP SPEED
			getline(in, singleLine, '\0');
			string Speed = eraseSpace(singleLine);

			try {
				this->m_top_speed = stod(Speed);
			}
			catch (...) {
				cout << "invalid record" << endl;
			}

		}
		catch (const char* msg) {
			cout << msg << endl;
		}



	}



	string Car::condition() const
	{
		return this->m_condition;
	}

	double Car::topSpeed() const
	{
		return this->m_top_speed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| " << setw(10) << right << this->m_maker;
		out << " | " << setw(6) << left << this->m_condition;
		out << " | " << setw(6) << setprecision(2) << fixed << this->m_top_speed;
		out << " |" << endl;
	}


}