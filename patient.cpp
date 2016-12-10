#include "Patient.h"
#include "departmentMenu.h"
#include "Queue.h"

using namespace std;

Patient::Patient() {}

Patient::Patient(string fName, string lName, string social, bool c) {
	firstName = fName;
	lastName = lName;
	SSN = social;
	critical = c;
}

void Patient::setFirst(string f) {
	firstName = f;
}

void Patient::setLast(string l) {
	lastName = l;
}

void Patient::setSSN(string social) {
	SSN = social;
}

void Patient::setCritical(bool critikal) {
	critical = critikal;
}

string Patient::getFirst() {
	return firstName;
}

string Patient::getLast() {
	return lastName;
}

string Patient::getSSN() {
	return SSN;
}

bool Patient::getCritical() {
	return critical;
}