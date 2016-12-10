/*Alexandria Piatt
12/11/16
Program 7*/

#include "Queue.h"
#include "departmentMenu.h"
#include "Patient.h"
#include <iostream>

using namespace std;

void main() {
	char exit_option = 'j';
	string dChoice;
	int choice;
	DepartmentMenu* chosenMenu = NULL;
	Queue <Patient> aPatient();
	while (exit_option != 'n') {
		system("cls");
		cout << "      Welcome to Sterling City Hospital." << endl;
		cout << "1. Heart Clinic\n" << "2. Lung Clinic\n" << "3. Plastic Surgery\n" << "4. Exit\n";
		cout << "Please enter your choice." << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			dChoice = "Heart Clinic";
			chosenMenu = new DepartmentMenu(dChoice, aPatient);
			system("cls");
			chosenMenu->displayMenu();
			break;
		}
		case 2: {
			dChoice = "Lung Clinic";
			chosenMenu = new DepartmentMenu(dChoice, aPatient);
			system("cls");
			chosenMenu->displayMenu();
			break;
		}
		case 3: {
			dChoice = "Plastic Surgery";
			chosenMenu = new DepartmentMenu(dChoice, aPatient);
			system("cls");
			chosenMenu->displayMenu();
			break;
		}
		case 4:
			exit_option = 'n';
			break;
		}
	}
}


