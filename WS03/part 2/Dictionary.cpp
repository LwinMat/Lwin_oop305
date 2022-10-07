/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-02-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include<iostream>
#include<string.h>
#include "Dictionary.h"
#include "Queue.h"

using namespace std;

namespace sdds
{
		const string& Dictionary::getTerm() const {
			return m_term;
		}
		const string& Dictionary::getDefinition() const {
			return m_definition;
		}
		Dictionary::Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition }{}

		std::ostream& operator<<(std::ostream& ostr, const Dictionary& dictionary)
		{
			ostr << right << setw(20) << dictionary.getTerm() << ": " << dictionary.getDefinition();
			return ostr;
		}

		bool Dictionary::operator==(const Dictionary& dictionary) const
		{
			if (this->m_term == dictionary.m_term) {
				return true;
			}
			else {
				return false;
			}
		}


		Dictionary::Dictionary() {
			this->m_definition = "";
			this->m_term = "";
		}

		template <>
		Dictionary Queue<Dictionary, 100u>::dummy{ "Empty Item", "Empty Substitute" };

}