#ifndef SDDS_SPELLCHECKER_H_
#define SDDS_SPELLCHECKER_H_
#include<iostream>

namespace sdds
{
	class SpellChecker
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int m_wordModified[6];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SDDS_SPELLCHECKER_H_

