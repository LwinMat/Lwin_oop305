#ifndef _SDDS_RESTAURANT_H_
#define _SDDS_RESTAURANT_H_

#include"Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation** pReservation = { nullptr };
		size_t rest_Count = 0;
	public:
		// default constructor
		Restaurant();

		Restaurant(const Reservation* reservation[], size_t cnt);


		Restaurant(const Restaurant& srcR);
		Restaurant& operator=(const Restaurant& srcR);


		Restaurant(Restaurant&& srcR) noexcept;
		Restaurant& operator=(Restaurant&& srcR) noexcept;

		~Restaurant();

		size_t size();

		friend std::ostream& operator<<(std::ostream& ostr, const Restaurant& rest);

	};

	
}

#endif // !_SDDS_RESTAURANT_H