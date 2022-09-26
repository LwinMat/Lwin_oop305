/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 09-16-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/




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
		char *m_brand = nullptr;
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


		// additional member function
		void clear();


		// RULE OF 3
		Cars(const Cars& otherCar);
		Cars& operator=(const Cars& otherCar);
		~Cars();


		//Conversion
		operator bool() const;

	};

	std::istream& operator>>(std::istream& is, Cars& car);

	void operator>>(const Cars& car1, Cars& car2);
}

#endif // !_CARADS_H_
