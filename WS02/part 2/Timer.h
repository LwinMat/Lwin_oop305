/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-25-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include<chrono>

namespace sdds
{
	class Timer
	{
		std::chrono::steady_clock::time_point start_time;
	public:

		void start();

		long long int stop();

	};
}

#endif // !SDDS_TIMER_H



