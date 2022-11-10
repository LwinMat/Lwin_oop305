
#include<iostream>
#include<sstream>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		string line = "";
		char type = '\0';
		char comma = '\0';

		getline(in, line);
		line.erase(0, line.find_first_not_of(' '));


		stringstream strIn(line);
		strIn >> type >> comma;

		if (strIn) {
			switch (type) {
				case 'C':
				case 'c':
					return new Car(strIn);
					break;
				case 'v':
				case 'V':
					return new Van(strIn);
					break;
				default:
					line = type;
					throw "Unrecognize record type: [" + line + "]";
			}
		}

		return nullptr;
	}
}
