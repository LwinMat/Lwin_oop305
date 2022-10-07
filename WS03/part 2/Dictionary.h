/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-02-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include<iostream>
#include <string>
#include<iomanip>


namespace sdds
{
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const;
		const std::string& getDefinition() const;
		Dictionary(const std::string& term, const std::string& definition);

		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
		friend std::ostream& operator<<(std::ostream& ostr, const Dictionary& dictionary);

		bool operator==(const Dictionary& dictionary) const;

		Dictionary();
		
	};

}

#endif // !SDDS_DICTIONARY_H

