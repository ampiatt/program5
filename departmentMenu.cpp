#include "departmentMenu.h"
#include "Queue.h"

DepartmentMenu::DepartmentMenu() {
	departmentChoice = "";
}

DepartmentMenu::DepartmentMenu(string dChoice) {
	departmentChoice = dChoice;
}

bool DepartmentMenu::displayMenu() {
	char exitC = 'j';
	int menuChoice;
	while (exitC != 'n') {
		cout << "Welcome to the " << departmentChoice << " menu." << endl;
		cout << "1. Add a Patient\n" << "2. Add Critically Ill Patient\n" << "3. Remove Patient\n" << "4. Cancel Patient\n"
			<< "5. Show the queue of patients\n" << "6. exit or change department\n";
		cin >> menuChoice;
		if (menuChoice == 6) {
			return false;
		}
	}

}