#ifndef _CARADS_H_
#define _CARADS_H_

//extern double g_taxrate;

//extern double g_discount;


extern double g_taxrate;
extern double g_discount;


namespace sdds
{
	
	// global function
	void listArgs(int argc, char** argv);

	// CLASS MODULE
	class Cars
	{
		char m_brand[11]{};
		char m_model[16]{};
		int m_manufacture_year{};
		double m_price{};
		char m_status{};
		bool m_promotion_discount{};
	public:
		Cars();
		void read(std::istream& is);
		void display(bool reset) const;
		char getStatus() const;
	};
}

#endif // !_CARADS_H_
