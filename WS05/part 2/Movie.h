#ifndef SDDS_MOVIE_H_
#define SDDS_MOVIE_H_
#include<iostream>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year_release;
		std::string m_description;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
}

#endif // !SDDS_MOVIE_H



