#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_
#include<iostream>

namespace sdds
{
	class Book
	{
		std::string m_author = " ";
		std::string m_title = " ";
		std::string m_country = " ";
		size_t m_pub_year = 0;
		double m_price = 0;
		std::string m_description = " ";
	public:
		Book();
		const std::string& title();
		const std::string& country();
		const size_t& year();
		double& price();
		Book(const std::string& strBook);

		friend std::ostream& operator<<(std::ostream& ostr, const Book& book);
	};

}

#endif // !SDDS_BOOK_H_