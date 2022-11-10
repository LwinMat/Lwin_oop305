/*
Name: Lwin Yonal Mateo Lopez
Email: lwinyonal@myseneca.ca
Student ID: 134710201
Date: 11-05-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<sstream>
#include "Vehicle.h"
#include "Van.h"
#include "Car.h"
#include "Utilities.h"
#include "Racecar.h"
#include "Luxuryvan.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		char vehicle_char{};
		in >> vehicle_char;
		std::string tempstr{};
		std::getline(in, tempstr);



		stringstream str(tempstr);


		if (vehicle_char == 'c' || vehicle_char == 'C') {
			Vehicle* vehicle = new Car(str);
			return vehicle;
		}
		else if (vehicle_char == 'v' || vehicle_char == 'V') {
			Vehicle* vehicle = new Van(str);
			return vehicle;
		}
		else if (vehicle_char == 'r' || vehicle_char == 'R') {
			Vehicle* vehicle = new Racecar(str);
			return vehicle;
		}
		else if (vehicle_char == 'l' || vehicle_char == 'L') {
			Vehicle* vehicle = new Luxuryvan(str);
			return vehicle;
		}
		else if (vehicle_char == 'i' || vehicle_char == 't') {
			std::string error{};
			error = "Unrecognized record type: [";
			error += vehicle_char;
			error += "]";
			throw error;
		}
		else {
			return nullptr;
		}
	}
}
