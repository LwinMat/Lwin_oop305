/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 11-18-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"
#include<vector>
#include<memory>

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (auto i = 0u; i < emp.size(); i++) {
			for (auto j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {

					EmployeeWage* temp = new EmployeeWage(emp[i].name, sal[j].salary);
					try {
						temp->rangeValidator();
					}
					catch (...) {
						delete temp;
						throw;
					}

					if (activeEmp.validitySIN(emp[i].id)) {
						activeEmp += temp;
					}


					delete temp;
					
				}
			}
		}
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers
		
		for (auto i = 0u; i < emp.size(); i++) {
			for (auto j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {

					std::unique_ptr<EmployeeWage> temp(new EmployeeWage(emp[i].name, sal[j].salary));
					try {
						temp->rangeValidator();
					}
					catch (...) {
						throw;
					}
					
					if (activeEmp.validitySIN(emp[i].id)) {
						activeEmp += temp;
					}
					
				}
			}
		}

		return activeEmp;
	}
}