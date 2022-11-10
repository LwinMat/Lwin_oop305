// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include<string>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	std::size_t count = 0;
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"

		std::ifstream the_file(argv[1]);
		if (!the_file) {
			std::cerr << "Unable to read file " << argv[1] << std::endl;
			exit(AppErrors::CannotOpenFile);
		}
		else {
			std::string strBook;
			do {
				std::getline(the_file, strBook);

				if (strBook[0] != '#') {
					library[count++] = strBook;
				}
				
			} while (count < 7);
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto fixPriceOfBook = [&](sdds::Book& b) { 
		if (b.country() == "US") {
			b.price() *= usdToCadRate;
		}
		else if (b.country() == "UK" && (b.year() > 1990 && b.year() < 1999)) {
			b.price() *= gbpToCadRate;
		}

		return b.price();
	};



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (auto i = 0; i < count; i++) {
		std::cout << library[i];
	}


	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (auto& book : library) {
		fixPriceOfBook(book);
	}


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (auto i = 0; i < count; i++) {
		std::cout << library[i];
	}


	std::cout << "-----------------------------------------\n";

	return 0;
}
