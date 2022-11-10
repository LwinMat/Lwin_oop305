#include<iostream>
#include<string>
#include<iomanip>
#include "Van.h"

using namespace std;

namespace sdds
{
	Van::Van(std::istream& in)
	{
		auto trimSpace = [](string& line) {
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
			this->m_v_maker = trimSpace(singleLine);


			// EXTRACTING TYPE
			getline(in, singleLine, ',');
			string Type = trimSpace(singleLine);
			if (Type == "p") {
				this->m_v_type = "pickup";
			}
			else if (Type == "m") {
				this->m_v_type = "minibus";
			}
			else if (Type == "c") {
				this->m_v_type = "camper";
			}


			// EXTRACT PURPOSE
			getline(in, singleLine, ',');
			string Purpose = trimSpace(singleLine);
			if (Purpose == "d") {
				this->m_v_purpose = "delivery";
			}
			else if (Purpose == "p") {
				this->m_v_purpose = "passenger";
			}
			else if (Purpose == "c") {
				this->m_v_purpose = "camping";
			}


			// EXTRACT CONDITION
			getline(in, singleLine, ',');
			string Condition = trimSpace(singleLine);
			if (Condition == "n") {
				this->m_v_condition = "new";
			}
			else if (Condition == "u") {
				this->m_v_condition = "used";
			}
			else if (Condition == "b") {
				this->m_v_condition = "broken";
			}


			// EXTRACT TOP SPEED
			getline(in, singleLine, '\0');
			string Speed = trimSpace(singleLine);

			try {
				this->m_v_top_speed = stod(Speed);
			}
			catch (...) {
				cout << "Invalid Record" << endl;
			}


		}
		catch (const char* msg) {
			cout << msg << endl;
		}
	}
	std::string Van::condition() const
	{
		return this->m_v_condition;
	}
	double Van::topSpeed() const
	{
		return this->m_v_top_speed;
	}
	std::string Van::type() const
	{
		return this->m_v_type;
	}
	std::string Van::usage() const
	{
		return this->m_v_purpose;
	}
	void Van::display(std::ostream& out) const
	{
		out << "| " << setw(8) << right << this->m_v_maker;
		out << " | " << setw(12) << left << this->m_v_type;
		out << " | " << setw(12) << this->m_v_purpose;
		out << " | " << setw(6) << this->m_v_condition;
		out << " | " << setw(6) << fixed << setprecision(2) << this->m_v_top_speed;
		out << " |" << endl;
	}
}
