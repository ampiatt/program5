/*Alexandria Piatt
ampiatt@mail.umkc.edu
12/11/16*/

#ifndef H_DEPARTMENTMENU
#define H_DEPARTMENTMENU

#include "Queue.h"
#include "Patient.h"
#include <string>

using namespace std;

class DepartmentMenu {
private:
	string departmentChoice;
public:
	DepartmentMenu();
	DepartmentMenu(string department);
	//takes no parameters
	int displayMenu();
	//displays secondary menu
};

#endif