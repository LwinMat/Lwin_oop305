#ifndef SDDS_VAN_H_
#define SDDS_VAN_H_

#include "Vehicle.h"

namespace sdds
{
	class Van : public Vehicle
	{
		std::string m_v_maker = {" "};
		std::string m_v_type = {" "};
		std::string m_v_condition = {" "};
		std::string m_v_purpose = {" "};
		double m_v_top_speed = 0.0;
	public:
		Van(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream& out) const;
	};
}

#endif // !SDDS_VAN_H_


