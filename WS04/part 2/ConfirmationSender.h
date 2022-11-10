#ifndef _SDDS_CONFIRMATIONSENDER_H_
#define _SDDS_CONFIRMATIONSENDER_H_

#include "Reservation.h"

namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_resCS={};
		size_t m_size = 0;
	public:
		ConfirmationSender();

		ConfirmationSender(const ConfirmationSender& srcR);
		ConfirmationSender& operator=(const ConfirmationSender& srcR);


		ConfirmationSender(ConfirmationSender&& srcR) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& srcR) noexcept;

		~ConfirmationSender();



		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& ostr, const ConfirmationSender &ConSend);
	};
}

#endif // !_SDDS_CONFIRMATIONSENDER_H_


