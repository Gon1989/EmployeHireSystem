#pragma once

#include <iostream>
#include <vector>

#include "Employee.h"

///Added Database.h file to manage and add new employees
///

namespace Records {
	const int kFirstEmployeeNumber = 1;

	class Database {

	public:
		Database();
		Employee& addEmployee(const std::string& firstName, const std::string& lastName);

		Employee& getEmployee(int getEmployeeNumber);
		Employee& getEmployee(const std::string& firstName, const std::string& lastName);

		//functions that show and control data of employees being hired/fired
		void displayAll() const;
		void displayCurrent() const;
		void displayPrev() const;

	private:

		std::vector<Employee> mEmployees; //mEmployees = objects of Employee
		int mNextEmployee; //keeps tracks of the employee number assign to a new employee

	};

}




















