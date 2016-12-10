#ifndef H_PATIENT
#define H_PATIENT

#include "Queue.h"
#include "departmentMenu.h"
#include <string>
#include <iostream>


using namespace std;

class Patient {
private:
	string firstName, lastName, SSN;
	bool critical;
public:
	Patient();
	Patient(string fName, string lName, string SSN, bool crit);
	void setFirst(string F);
	void setLast(string L);
	void setSSN(string social);
	void setCritical(bool c);

	string getFirst();
	string getLast();
	string getSSN();
	bool getCritical();
};

#endif H_PATIENT