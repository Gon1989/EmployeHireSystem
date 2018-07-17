#pragma once
#include <string>

namespace Records {
	const int kDefaultStartingSalary = 30000;

	class Employee {

	public:
		Employee(); //constructor
		void promote(int raiseAmount = 1000);
		void demote(int lowerAmount = 1000);
		void hire(); //hire the employee
		void fire(); //delete the employee from records
		void display() const; //display information

		//getters
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		int getEmployeeNumber() const;
		int getSalary() const;
		bool getHired() const;

		//setters
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setEmployeeNumber(int employeeNumber);
		void setSalary(int newSalary);

	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool mHired;

	};


}












