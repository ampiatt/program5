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
	int aMenuOption = 0;
	bool mainMenu = true;

	DepartmentMenu* chosenMenu = NULL; 
	Patient nPatient;

	//displays the main menu
	while (exit_option != 'n') {
		system("cls");
		cout << "      Welcome to Sterling City Hospital." << endl;
		cout << "1. Heart Clinic\n" << "2. Lung Clinic\n" << "3. Plastic Surgery\n" << "4. Exit\n";
		cout << "Please enter your choice." << endl;
		//user chooses which department to access
		cin >> choice;
		//creates the appropriate secondary menu/accesses the correct queue
		switch (choice) {
		case 1: {
			dChoice = "Heart Clinic";
			chosenMenu = new DepartmentMenu(dChoice);
			system("cls");
			aMenuOption = chosenMenu->displayMenu();
			mainMenu = false;
			break;
		}
		case 2: {
			dChoice = "Lung Clinic";
			chosenMenu = new DepartmentMenu(dChoice);
			system("cls");
			aMenuOption = chosenMenu->displayMenu();
			mainMenu = false;
			break;
		}
		case 3: {
			dChoice = "Plastic Surgery";
			chosenMenu = new DepartmentMenu(dChoice);
			system("cls");
			aMenuOption = chosenMenu->displayMenu();
			mainMenu = false;
			break;
		}
		case 4:
		{
			exit_option = 'n';
			break;
		}
		}
		//controls the secondary menu and calls the appropriate functions
		while (!mainMenu) {
			switch (aMenuOption) {
				//calls to add a patient
			case 1: {
				nPatient.addPatient(dChoice);
				mainMenu = true;
				break;
			}
					//adds critical patient
			case 2: {
				nPatient.addCritical(dChoice);
				mainMenu = true;
				break;
			}
					//removes patient from queue due to having their surgery
			case 3: {
				nPatient.removeForOperation(dChoice);
				mainMenu = true;
				break;
			}
					//user cancels specific appointment
			case 4: {
				nPatient.cancelPatient(dChoice);
				mainMenu = true;
				break;
			}
					//prints the current queue
			case 5:{
				nPatient.printCritical(dChoice);
				nPatient.printPatientList(dChoice);
				system("pause");
				mainMenu = true;
				break;
			}
				   //returns to main menu
			case 6: {
				mainMenu = true;
				break;
			}
			}
		}
	}
}


