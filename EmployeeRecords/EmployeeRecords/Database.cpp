#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records {
	Database::Database() : mNextEmployee(kFirstEmployeeNumber){} //constructor and set default values
	//we increment mNextEmployee so every employee has its own disctintive number

	Employee& Database::addEmployee(const string& firstName, const string& lastName) { //creates a new employee object
		//fills information and add it to the vector
		Employee theEmployee;
		theEmployee.setFirstName(firstName);
		theEmployee.setLastName(lastName);
		theEmployee.setEmployeeNumber(mNextEmployee);
		theEmployee.hire();
		//add to vector
		mEmployees.push_back(theEmployee);
		return mEmployees[mEmployees.size() - 1];
	}

	//function to check if the information is correct of the employee
	Employee& Database::getEmployee(int employeeNumber) {
		for (auto& e : mEmployees) { //loops thru the employees inside the mEmplyees, 
			if (e.getEmployeeNumber() == employeeNumber) { //check if all employes match the data we pass in to the function
				return e;
			}
		}
		throw runtime_error("Not Employee Found"); //if not, we throw the information that no match is found
	}

	Employee& Database::getEmployee(const string& firstName, const string& lastName) {
		for (auto& employee : mEmployees) {
			if (employee.getFirstName() == firstName &&
				employee.getLastName() == lastName) {
				return employee;
			}
		}
		throw runtime_error("No employee found.");
	}


	//function to display information
	void Database::displayAll() const {
		for (const auto& employee : mEmployees) {
			employee.display();
		}

	}

	void Database::displayCurrent() const {
		for (const auto& employee : mEmployees) {
			if (employee.getHired()) {
				employee.display();
			}
		}
	}

	void Database::displayPrev() const {
		for (const auto& employee : mEmployees) {
			if (!employee.getHired())
				employee.display();
		}
	}

	




}



