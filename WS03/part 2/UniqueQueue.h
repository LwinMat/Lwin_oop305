/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-02-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include<iostream>
#include<cmath>
#include "Queue.h"

namespace sdds
{
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
		bool push(const T& item) {
			if (this->size() < 100) {
				for (auto i = 0u; i < this->size(); i++) {
					if ((*this)[i] == item) {
						return false;
					}
				}
				return sdds::Queue<T, 100>::push(item);
			}
			return false;
		}

		// empty body constructor
		~UniqueQueue() {}
	};

	

	// specialization
	template<>
	bool UniqueQueue<double>::push(const double& item) {
		if (this->size() < 100) {
			for (auto i = 0u; i < this->size(); i++) {
				if (std::fabs((*this)[i] - item) < 0.003) {
					return false;
				}
			}
			return sdds::Queue<double, 100>::push(item);
		}
		return false;
	}

	
}


#endif