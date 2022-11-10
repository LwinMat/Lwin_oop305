/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 10-22-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include "SpellChecker.h"

using namespace std;

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{

		ifstream W_File(filename);

		if (!W_File.is_open()) {
			throw "Bad file name!";
		}
		else {

			string wordLine;
			string word;
			for (size_t i = 0; i < 6 && W_File; i++) {
				std::getline(W_File, wordLine);
				word = wordLine.substr(0, wordLine.find_first_of(' '));
				m_badWords[i] = word;

				wordLine.erase(0, wordLine.find_first_of(' '));
				word = wordLine.substr(wordLine.find_first_not_of(' '), wordLine.find_last_not_of(' '));
				m_goodWords[i] = word;

				m_wordModified[i] = 0;
			}
			W_File.close();
		}


	}
	void SpellChecker::operator()(std::string& text)
	{
		for (auto i = 0; i < 6; ++i) {
			
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				m_wordModified[i]++;
				
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;

		for (auto i = 0; i < 6; i++) {
			out << setw(15) << right << m_badWords[i] << ": " << m_wordModified[i] << " replacements" << endl;
		}
	}
}