/*Alexandria Piatt
12/11/16
Program 7*/

#include "Queue.h"
#include "departmentMenu.h"
#include <iostream>

using namespace std;

void main() {
	char exit_option = 'j';
	string dChoice;
	int choice;
	DepartmentMenu* chosenMenu = NULL;
	while (exit_option != 'n') {
		cout << "      Welcome to Sterling City Hospital." << endl;
		cout << "1. Heart Clinic\n" << "2. Lung Clinic\n" << "3. Plastic Surgery\n" << "4. Exit\n";
		cout << "Please enter your choice." << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			dChoice = "Heart Clinic";
			chosenMenu = new DepartmentMenu(dChoice);
			exit_option = 'n';
			break;
		}
		case 2: {
			dChoice = "Lung Clinic";
			chosenMenu = new DepartmentMenu(dChoice);
			exit_option = 'n';
			break;
		}
		case 3: {
			dChoice = "Plastic Surgery";
			chosenMenu = new DepartmentMenu(dChoice);
			exit_option = 'n';
			break;
		}
		case 4:
			exit_option = 'n';
			break;
		}
	}
	if (!chosenMenu->displayMenu()) {
		exit_option = 'l';
	}


}


