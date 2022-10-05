/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-25-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<utility>
#include "TennisLog.h"


using namespace std;

namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const TennisMatch& tennisMatch)
	{
		// TODO: insert return statement here

		if (tennisMatch.Loser == " " && tennisMatch.Match_ID == 0 && tennisMatch.Tournament_ID == " " && tennisMatch.Tournament_Name == " " && tennisMatch.Winner == " ") {
			//cout << "Empty Match" << endl;
			cout << "Empty Match";
		}
		else {
			os.fill('.');

			// this format displays TOURNAMENT ID
			os << right << setw(20) << "Tourney ID" << " : " << left << setw(30) << tennisMatch.Tournament_ID << '\n';
			
			// this format displays MATCH ID
			os << right << setw(20) << "Match ID" << " : " << left << setw(30) << tennisMatch.Match_ID << '\n';

			// this format displays TOURNAMENT NAME
			os << right << setw(20) << "Tourney" << " : " << left << setw(30) << tennisMatch.Tournament_Name << '\n';


			//this format displays WINNER
			os << right << setw(20) << "Winner" << " : " << left << setw(30) << tennisMatch.Winner << '\n';

			
			//this format dislays LOSER
			os << right << setw(20) << "Loser" << " : " << left << setw(30) << tennisMatch.Loser << '\n';

			os.fill(' ');

		}

		return os;
	}
	TennisLog::TennisLog()
	{
		delete this->TM;
		TM = nullptr;
		countRecord = 0;
	}
	TennisLog::TennisLog(const char* filename)
	{
		std::ifstream fname;
		
		fname.open(filename);
		

		if (!fname.is_open()) {
			cout << "Could not open file\n";
		}
		else {
			// a string variable to get headline
			string head_line{};
			

			getline(fname, head_line, '\n');

			// a loop to count the records
			this->countRecord = 0;
			while (fname) {
				this->countRecord += 1;
				getline(fname, head_line, '\n');
			}
			this->countRecord--;
			
			this->TM = new TennisMatch[this->countRecord];

			fname.clear();
			fname.seekg(0);

			// a loop to count the records
			size_t i = 0;
			getline(fname, head_line, '\n');
			while (i < this->countRecord) {
				
				getline(fname, this->TM[i].Tournament_ID, ',');
				getline(fname, this->TM[i].Tournament_Name, ',');
				fname >> this->TM[i].Match_ID;
				fname.ignore();
				getline(fname, this->TM[i].Winner, ',');
				getline(fname, this->TM[i].Loser, '\n');

				i++;
			}
			fname.close();
		}
	}


	void TennisLog::addMatch(const TennisMatch& match) {
		
		TennisMatch* newArray = nullptr;
		newArray = new TennisMatch[countRecord + 1];

		size_t i = 0;
		for (i = 0; i < countRecord; ++i) {
			newArray[i] = this->TM[i];
		}
	
		newArray[countRecord] = match;

		delete [] this->TM;
		this->TM = newArray;

		countRecord += 1;
	}
		

		
	TennisLog TennisLog::findMatches(std::string PlayerName) const {
		TennisLog result;
		size_t i = 0;
		for (i = 0; i < this->countRecord; i++) {
			if (this->TM[i].Winner == PlayerName || this->TM[i].Loser == PlayerName) {
				result.addMatch(this->TM[i]);
			}
		}
		return result;
	}

	TennisMatch TennisLog::operator[](size_t index) const {
		TennisMatch temp;

		if (index < countRecord)
		{
			temp = this->TM[index];
		}
		
		return temp;
	}

	TennisLog::operator size_t() const
	{
		return this->countRecord;
	}

	TennisLog::TennisLog(const TennisLog& src)
	{
		this->TM = nullptr;
		*this = src;
	}

	TennisLog::TennisLog(TennisLog&& src) noexcept
	{
		*this = std::move(src);
	}

	TennisLog& TennisLog::operator=(const TennisLog& src)
	{
		// TODO: insert return statement here
		if (this != &src) {
			delete[] this->TM;

			this->countRecord = src.countRecord;

			// deep copy
			this->TM = new TennisMatch[src.countRecord];
			size_t i = 0;
			for (i = 0; i < src.countRecord; i++) {
				this->TM[i] = src.TM[i];
			}
			
		}
		return *this;
	}

	TennisLog& TennisLog::operator=(TennisLog&& src) noexcept
	{
		// TODO: insert return statement here
		if (this != &src) {
			delete[] this->TM;
			this->TM = nullptr;

			this->countRecord = src.countRecord;

			// deep copy
			this->TM = src.TM;
			src.TM = nullptr;
			src.countRecord = 0;
		
		}
		return *this;
	}

	TennisLog::~TennisLog()
	{
		this->countRecord = 0;
		delete [] this->TM;
		this->TM = nullptr;
	}
	
}


