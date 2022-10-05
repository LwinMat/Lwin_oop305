/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-25-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include<chrono>
#include<iomanip>
#include "Timer.h"

using namespace std;

namespace sdds
{
	void Timer::start()
	{
		start_time = chrono::steady_clock::now();
	}
	long long int Timer::stop()
	{

		chrono::steady_clock::time_point stop_time;
			
			
		stop_time = chrono::steady_clock::now();
		
		auto diff = chrono::duration_cast<std::chrono::nanoseconds>(stop_time - start_time);
		
		return diff.count();
		
	}
}
