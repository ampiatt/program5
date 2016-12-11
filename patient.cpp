/*Alexandria Piatt
ampiatt@mail.umkc.edu
12/11/16*/

#include "Patient.h"
#include "departmentMenu.h"
#include "Queue.h"

using namespace std;

Patient::Patient() {}

Patient::Patient(string fName, string lName, int social, bool c) {
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

void Patient::setSSN(int social) {
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

int Patient::getSSN() {
	return SSN;
}

bool Patient::getCritical() {
	return critical;
}

void Patient::addPatient(string Department) {
	//creates pointer to a new patient
	Patient *p = new Patient();
	system("cls");
	cout << "Welcome to the add patient function of Sterling City Hospital." << endl;
	cin.ignore();
		cout << "Please enter the patient's first name." << endl;
		getline(cin, p->firstName);

		cout << "Please enter the patient's last name." << endl;
		getline(cin, p->lastName);

		cout << "Please enter the patient's social security number." << endl;
		cin >> p->SSN;
		//sets critical condition to false as it is just a regular patient
		p->critical = false; 
		//checks the department and adds it to the appropriate array
		if (Department == "Heart Clinic") {
			Heart[hCount] = p;
			hCount++;
			HeartQ.push(p->SSN);

		}
		if (Department == "Lung Clinic") {
			Lung[lCount] = p;
			lCount++;
			LungQ.push(p->SSN);
		}
		if (Department == "Plasic Surgery") {
			Plastic[pCount] = p;
			pCount++;
			PlasticQ.push(p->SSN);
		}
		//outputs the patient's info for confirmation.
		system("cls");
		cout << "Patient's first name: " << p->firstName << endl;
		cout << "Patient's last name: " << p->lastName << endl;
		cout << "Patient's social security number: " << p->SSN << endl;
		system("pause");
}

void Patient::addCritical(string Department) {
	Patient *p = new Patient();
	system("cls");
	cout << "Welcome to the add patient function of Sterling City Hospital." << endl;
	cin.ignore();
	cout << "Please enter the patient's first name." << endl;
	getline(cin, p->firstName);

	cout << "Please enter the patient's last name." << endl;
	getline(cin, p->lastName);

	cout << "Please enter the patient's social security number." << endl;
	cin >> p->SSN;
	//sets critical condition to true because it is a critical patient
	p->critical = true;
	// checks department and adds to the appropriate queue and array
	if (Department == "Heart Clinic") {
		Heart[hCount] = p;
		hCount++;
		HeartQ.pushToTop(p->SSN);

	}
	if (Department == "Lung Clinic") {
		Lung[lCount] = p;
		lCount++;
		LungQ.pushToTop(p->SSN);
	}
	if (Department == "Plasic Surgery") {
		Plastic[pCount] = p;
		pCount++;
		PlasticQ.pushToTop(p->SSN);
	}

	//outputs for confirmation
	system("cls");
	cout << "Patient's first name: " << p->firstName << endl;
	cout << "Patient's last name: " << p->lastName << endl;
	cout << "Patient's social security number: " << p->SSN << endl;
	system("pause");
}

void Patient::removeForOperation(string Department) {
	cout << "Removing completed patient from surgical queue..." << endl;
	int tempSocial;
	if (Department == "Heart Clinic") {
		//sets the temp variable = to the popped item from queue
		tempSocial = HeartQ.pop();
		cout << tempSocial;
		for (int i = 0; i < hCount; i++)
		{
			//checks if temp social matches any in heart array, deletes if yes
			if (tempSocial == Heart[i]->SSN) {
				cout << "Patient removed." << endl;
				delete Heart[i];
				hCount--;
				system("pause");
				return;
			}
			else {
				cout << "Patient does not exist." << endl;
				system("pause");
				return;
			}
		}
	}
	if (Department == "Lung Clinic") {
		tempSocial = LungQ.pop();
		for (int i = 0; i < lCount; i++)
		{
			if (tempSocial == Lung[i]->getSSN()) {
				cout << "Patient removed.  Press any key to continue." << endl;
				delete Lung[i];
				lCount--;
				system("pause");
			}
			else {
				cout << "Patient does not exist.  Press any key to continue." << endl;
				system("pause");
			}
		}
	}
	if (Department == "Plastic Surgery") {
		tempSocial = PlasticQ.pop();
		for (int i = 0; i < pCount; i++)
		{
			if (tempSocial == Plastic[i]->getSSN()) {
				cout << "Patient removed.  Press any key to continue." << endl;
				delete Plastic[i];
				pCount--;
				system("pause");
			}
			else {
				cout << "Patient does not exist.  Press any key to continue." << endl;
				system("pause");
			}
		}
	}
	cout << "Press any key ";
}
void Patient::cancelPatient(string department) {
	string first, last;
	int tsocial;
	cout << "Please enter the first name of the patient you want to cancel." << endl;
	getline(cin, first);
	cin.ignore();
	cout << "Please enter the last name of the patient you want to cancel." << endl;
	getline(cin, last);
	cout << "Please enter the social security number of the patient you want to cancel." << endl;
	cin >> tsocial;
	//searchs the appropriate department arrays to find the SSN and delete that patient.
	if (department == "Heart Clinic") {
		for (int i = 0; i < hCount; i++) {
			if (tsocial == Heart[i]->getSSN()) {
				delete Heart[i];
				hCount--;
			}
			else {
				cout << "Patient does not exist" << endl;
			}
		}
	}

	if (department == "Lung Clinic") {
		for (int i = 0; i < lCount; i++) {
			if (tsocial == Lung[i]->getSSN()) {
				delete Lung[i];
				lCount--;
			}
			else {
				cout << "Patient does not exist" << endl;
			}
		}
	}

	if (department == "Plastic Surgery") {
		for (int i = 0; i < pCount; i++) {
			if (tsocial == Plastic[i]->getSSN()) {
				delete Plastic[i];
				pCount--;
			}
			else {
				cout << "Patient does not exist" << endl;
			}
		}
	}
}

void Patient::printPatientList(string department) {
	cout << "Non-critical patients in queue: " << endl;
	//checks department
	if (department == "Heart Clinic") {
		//prints the non critical patients in the array
		for (int i = 0; i < hCount; i++) {
			if (!Heart[i]->getCritical()) {
				cout << "Patient's first name: " << Heart[i]->firstName << endl;
				cout << "Patient's last name: " << Heart[i]->lastName << endl;
				cout << "Patient's social security number: " << Heart[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	if (department == "Lung Clinic") {
		for (int i = 0; i < lCount; i++) {
			if (!Lung[i]->getCritical()) {
				cout << "Patient's first name: " << Lung[i]->firstName << endl;
				cout << "Patient's last name: " << Lung[i]->lastName << endl;
				cout << "Patient's social security number: " << Lung[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	if (department == "Plastic Surgery") {
		for (int i = 0; i < pCount; i++) {
			if (!Plastic[i]->getCritical()) {
				cout << "Patient's first name: " << Plastic[i]->firstName << endl;
				cout << "Patient's last name: " << Plastic[i]->lastName << endl;
				cout << "Patient's social security number: " << Plastic[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	//system("pause"); 
}


void Patient::printCritical(string department) {
	cout << "Critical Patient's in Queue: " << endl;
	//checks department
	if (department == "Heart Clinic") {
		//prints critical patients
		for (int i = 0; i < hCount; i++) {
			if (Heart[i]->getCritical()) {
				cout << "Patient's first name: " << Heart[i]->firstName << endl;
				cout << "Patient's last name: " << Heart[i]->lastName << endl;
				cout << "Patient's social security number: " << Heart[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	if (department == "Lung Clinic") {
		for (int i = 0; i < lCount; i++) {
			if (Lung[i]->getCritical()) {
				cout << "Patient's first name: " << Lung[i]->firstName << endl;
				cout << "Patient's last name: " << Lung[i]->lastName << endl;
				cout << "Patient's social security number: " << Lung[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	if (department == "Plastic Surgery") {
		for (int i = 0; i < pCount; i++) {
			if (Plastic[i]->getCritical()) {
				cout << "Patient's first name: " << Plastic[i]->firstName << endl;
				cout << "Patient's last name: " << Plastic[i]->lastName << endl;
				cout << "Patient's social security number: " << Plastic[i]->SSN << endl;
				cout << endl;
			}
		}
	}
	//system("pause");
}