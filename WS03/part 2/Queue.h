/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-02-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include<iostream>
#include "Dictionary.h"

namespace sdds
{
	template <typename T, unsigned int CAPACITY>
	class Queue
	{
		T Cap[CAPACITY];
		unsigned int count;
		static T dummy; 
	public:
		Queue() :count{ 0 } {}
		virtual bool push(const T& item) {
			bool moved = false;
			
			if (count < CAPACITY) {
				Cap[count++] = item;
				moved = true;
			}

			return moved;
		}
		T pop() {
			T result = Cap[0];

			for (unsigned int i = 0; i < count-1; i++) {
				Cap[i] = Cap[i + 1];
			}
			count--;

			return result;
		}
		unsigned int size() const {
			return count;
		}
		void display(std::ostream& out = std::cout) const {
			out << "----------------------\n";
			out << "| Dictionary Content |\n";
			out << "----------------------\n";

			for (unsigned int i = 0; i < count; i++) {
				out << Cap[i] << std::endl;
			}
			out << "----------------------" << std::endl;
		}
		T operator[](unsigned int index) const {
			return index < count ? Cap[index] : dummy;
		}

		virtual ~Queue(){};
	};

	template <typename T, unsigned int CAPACITY>
	T Queue<T, CAPACITY>::dummy{};


	

}

#endif // !SDDS_QUEUE_H
