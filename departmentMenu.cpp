#include "departmentMenu.h"
#include "Queue.h"

DepartmentMenu::DepartmentMenu() {
}

DepartmentMenu::DepartmentMenu(string dChoice, Queue <Patient> aPat) {
	departmentChoice = dChoice;
	aPatient = aPat;
	
}

void DepartmentMenu::displayMenu() {
	char exitC = 'j';
	int menuChoice;
	while (exitC != 'n') {
		cout << "Welcome to the " << departmentChoice << " menu." << endl;
		cout << "1. Add a Patient\n" << "2. Add Critically Ill Patient\n" << "3. Remove Patient\n" << "4. Cancel Patient\n"
			<< "5. Show the queue of patients\n" << "6. exit or change department\n";
		cin >> menuChoice;
		switch (menuChoice) {
		case 1: {
			cout << "working" << endl;
			addPatient();
			break;
		}
		case 2: {
			cout << "working" << endl;
		/*	addCriticallyIllPatient();*/
			break;
		}
		case 3: {
			cout << "working" << endl;
		/*	removePatient();*/
			break;
		}
		case 4: {
			cout << "working" << endl;
			/*cancelPatient();*/
			break;
		}
		case 5: {
			cout << "working" << endl;
			/*printPatientQueue();*/
			break;
		}
		case 6: 
			exitC = 'n';
			return;
		}
		}
	}
void DepartmentMenu::addPatient() {
	string first, last, SSN;
	char choice;
	bool status;

	cout << "Please enter the patient's first name." << endl;
	getline(cin, first);
	
	cout << "Please enter the patient's last name." << endl;
	getline(cin, last);

	cout << "Please enter the patient's social security number." << endl;
	getline(cin, SSN);

	cout << "Is this a critically ill patient? (y/n)" << endl;
	cin.ignore();
	cin >> choice;

	if ((choice == 'Y') || (choice == 'y')) {
		status = true;
	}
	else if ((choice = 'N') || (choice == 'n')) {
		status = false;
	}

	cout << first << "  " << last << "  " << SSN << endl;

	if (status) {
		cout << "deads" << endl;
	}
	else
		cout << "not deads." << endl;
}