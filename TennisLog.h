/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-25-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include<string>
#include<iomanip>
#include<utility>

namespace sdds
{
	struct TennisMatch
	{
		std::string Tournament_ID = " ";
		std::string Tournament_Name = " ";
		int Match_ID = 0;
		std::string Winner = " ";
		std::string Loser = " ";
	};

	class TennisLog
	{
		// this module contains two struct/class
		TennisMatch* TM = nullptr;
		size_t countRecord = 0;
	public:
		// default constructor
		TennisLog();

		// read from file
		TennisLog(const char* filename);

		void addMatch(const TennisMatch& match);

		TennisLog findMatches(std::string PlayerName) const;

		TennisMatch operator[](size_t index) const;

		operator size_t() const;


		// RULE OF FIVE

		// COPY constructor
		TennisLog(const TennisLog& src);

		// MOVE constructor
		TennisLog(TennisLog&& src) noexcept;

		// COPY ASSIGNMENT operator
		TennisLog& operator=(const TennisLog& src);

		// MOVE ASSIGNMENT operator
		TennisLog& operator=(TennisLog&& src) noexcept;

		// Destructor
		~TennisLog();
	};


	std::ostream& operator<<(std::ostream& os, const TennisMatch& tennisMatch);


}



#endif // !TENNISLOG_H_


