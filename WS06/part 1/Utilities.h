#ifndef SDDS_UTILITIES_H_
#define SDDS_UTILITIES_H_
#include<iostream>
#include"Vehicle.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif // !SDDS_UTILITIES_H_


