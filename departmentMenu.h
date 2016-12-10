#ifndef H_DEPARTMENTMENU
#define H_DEPARTMENTMENU

#include "Queue.h"
#include <string>

using namespace std;

class DepartmentMenu {
private:
	string departmentChoice;
public:
	DepartmentMenu();
	DepartmentMenu(string department);
	bool displayMenu();
	//void addPatient();
	//void addCriticallyIllPatient();
	//void removePatient();
	//void cancelPatient();
	//void printPatientQueue();
};

#endif