#ifndef H_DEPARTMENTMENU
#define H_DEPARTMENTMENU

#include "Queue.h"
#include "Patient.h"
#include <string>

using namespace std;

class DepartmentMenu {
private:
	string departmentChoice;
	Queue <Patient*> aPatient = new Queue<Patient*>;
public:
	DepartmentMenu();
	DepartmentMenu(string department, Queue<Patient> another);
	void displayMenu();
	void addPatient();
	void addCriticallyIllPatient();
	void removePatient();
	void cancelPatient();
	void printPatientQueue();
};

#endif