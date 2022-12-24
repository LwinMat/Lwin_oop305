#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		EmployeeWage* temp;
		for (auto i = 0u; i < emp.size(); i++) {
			for (auto j = 0u; j < sal.size(); j++) {
				if (emp[i].id == sal[j].id) {
					
					temp = new EmployeeWage(emp[i].name, sal[j].salary);
					temp->rangeValidator();
					activeEmp += temp;
					
					delete temp;
					temp = nullptr;
				}
			}
		}
		
		
		return activeEmp;
	}
}