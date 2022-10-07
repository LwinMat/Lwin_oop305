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

}