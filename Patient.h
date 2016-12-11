/*Alexandria Piatt
ampiatt@mail.umkc.edu
12/11/16*/

#ifndef H_PATIENT
#define H_PATIENT

#include "Queue.h"
#include "departmentMenu.h"
#include <string>
#include <iostream>


using namespace std;

class Patient {
private:
	string firstName, lastName;
	int SSN;
	bool critical;
	Patient *Heart[100];
	Patient *Lung[100];
	Patient *Plastic[100];
	int hCount = 0;
	int lCount = 0;
	int pCount = 0;

	Queue HeartQ;
	Queue LungQ;
	Queue PlasticQ;

public:
	Patient();
	//sets first, last, social and condition
	Patient(string fName, string lName, int SSN, bool crit);
	//mutators
	void setFirst(string F);
	void setLast(string L);
	void setSSN(int social);
	void setCritical(bool c);

	string getFirst();
	string getLast();
	int getSSN();
	bool getCritical();
	
	//all take department as parameter

	void addPatient(string department);
	//adds patients to both array and queue for appropriate department

	void addCritical(string department);
	//adds critical condition patients

	void removeForOperation(string department);
	//pops the top patient from the queue and removes them for surgery/deletes them from the array

	void cancelPatient(string department);
	//allows user to cancel a patient

	void printCritical(string department);
	//prints critical condition patients

	void printPatientList(string department);
	//prints non critical patients
};

#endif H_PATIENT