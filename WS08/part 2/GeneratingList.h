/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 11-18-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool validitySIN(const std::string& sin) {
			if (sin.length() == 0) {
				return false;
			}


			int num[9] = {};
			for (auto i = 0; i < 9; i++) {
				num[i] = sin[i] - '0';
			}

			int sin_multiply[9] = { 1,2,1,2,1,2,1,2,1 };
			int sin_check[9] = {};

			int total = 0;
			int sum = 0;
			int value = 0;

			for (auto i = 0; i < 9; i++) {
				sin_check[i] = num[i] * sin_multiply[i];

				if (sin_check[i] > 9) {
					value = 0;
					sum = 0;
					while (sin_check[i] != 0) {
						value = sin_check[i] % 10;
						sum = sum + value;
						sin_check[i] /= 10;
					}
					sin_check[i] = sum;
				}
			}

			for (auto j = 0; j < 9; j++) {
				total = total + sin_check[j];
			}

			if (total % 10 == 0) {
				return true;
			}
			else {
				return false;
			}


		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		//void operator+=(T& sp) {
		void operator+=(std::unique_ptr<T> &sp) {
			//this->list.push_back(std::move(sp));
			this->list.push_back(*sp);
		}

		
		

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* rp) {
			this->list.push_back(std::move(*rp));
		}
		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
