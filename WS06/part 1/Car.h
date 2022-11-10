#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_

#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_maker = { " " };
		std::string m_condition = { " " };
		double m_top_speed = {0.0};
	public:
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif // !SDDS_CAR_H_

