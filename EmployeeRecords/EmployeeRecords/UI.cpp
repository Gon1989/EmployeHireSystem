#include <iostream>
#include <stdexcept>
#include <exception>

#include "Database.h" 

using namespace std;
using namespace Records;

//prototypes
int displayMenu();

// & = the original object passed in will be modified by anything done to it in the function.

void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);


int main() { //MAIN
	Database employeeDB; //obj
	bool done = false; //flag to check when to stop displaying menu

	while (!done) { //keep runing the menu
		int choice = displayMenu();

		switch (choice) {
		case 1:
			doHire(employeeDB); //obj acceesor to database
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayPrev();
			break;
		case 0:
			cout << "Goodbye! \n " << endl;
			done = true;
			break;
		default:
			cerr << "Error, not valid command" << endl;
			break;
		}
	}

	return 0;
}

//function to display all menu info
int displayMenu() {
	int choice;
	cout << "\n";
	cout << "Employee Database: " << endl;
	cout << "" << endl;
	cout << "(1) Hire a new employee" << endl;
	cout << "(2) Fire an employee" << endl;
	cout << "(3) Promote an employee" << endl;
	cout << "(4) Show all employees" << endl;
	cout << "(5) Show all current employees" << endl;
	cout << "(6) show all previous employees" << endl;
	cout << "(0) Exit" << endl;
	cout << "\n";
	cout << "--> ";
	cin >> choice;

	return choice;
}

//function to get user input and tell database add that employee
void doHire(Database& db) {
	string firstName;
	string lastName;
	//get input
	cout << "First name? " << endl;
	cin >> firstName;
	cout << "Last name? " << endl;
	cin >> lastName;

	try {
		db.addEmployee(firstName,lastName); //we access databa with db argument that we pass and add the employee

	} catch (const std::exception& exception) {
		cerr << "Error. Unable to add the employee: " << exception.what() << endl;
	}
}

//function to fire an employee asking for his number in the database,
//then use the public method to the Employee obj to make the changes
void doFire(Database& db) {
	int employeeNumber;
	cout << "Employee Number: " << endl;
	cin >> employeeNumber;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.fire(); //fire the employee
		cout << "Employee: " << employeeNumber << " has been Fired. " << endl;
	}
	catch (const std::exception& exception) {
		cerr << "Unable to terminate employee: " << exception.what() << endl;
	}
}

//function to prome an eployee
void doPromote(Database& db) {
	int employeeNumber;
	int raiseAmount;

	cout << "Employee Number? " << endl;
	cin >> employeeNumber;

	cout << "Ammount money that will be raised? " << endl;
	cin >> raiseAmount;

	try {
		Employee& emp = db.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (const std::exception& exception ) {
		cerr << "Unable to promote employee: " << exception.what() << endl;
	}
}




















