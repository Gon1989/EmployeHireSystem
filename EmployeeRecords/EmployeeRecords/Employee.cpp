
#include <iostream>
#include "Employee.h"

using namespace std;


namespace Records {

	
	//set constructor variables immediatly
	Employee::Employee() : mFirstName(""), mLastName(""), mEmployeeNumber(-1), mSalary(kDefaultStartingSalary), mHired(false) {
	}
	
	//function to promote
	void Employee::promote(int raiseAmount) {
		setSalary(getSalary() + raiseAmount); //call set salary and set the new value
	}

	//function to demote employees
	void Employee::demote(int lowerAmount) {
		setSalary(getSalary() - lowerAmount); //call set salary and set the new value

	}

	//function to hire 
	void Employee::hire() {
		mHired = true;
	}

	//function to fire
	void Employee::fire() {
		mHired = false;
	}

	//function to display all information
	void Employee::display() const {
		cout << "Employee: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-----------------" << endl;
		if (mHired) { //check if is hired to display info
			cout << "Current Employee." << endl;
		}
		else {
			cout << "Not an Employee." << endl;
		}
		cout << "Employe Number: "<< getEmployeeNumber() << endl; //display employee number
		cout << "Salary: $" <<getSalary() << endl; //display salary
		cout << endl;
	}

	// Getters and setters
	void Employee::setFirstName(const string& firstName) {
		mFirstName = firstName;
	}

	const string& Employee::getFirstName() const {
		return mFirstName;
	}

	void Employee::setLastName(const string& lastName) {
		mLastName = lastName;
	}

	const string& Employee::getLastName() const {
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber) {
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const {
		return mEmployeeNumber;
	}

	void Employee::setSalary(int salary) {
		mSalary = salary;
	}

	int Employee::getSalary() const {
		return mSalary;
	}

	bool Employee::getHired() const {
		return mHired;
	}





}


