#ifndef PERSONNELREPORT_H
#define PERSONNELREPORT_H

#include <iostream>
#include <string>

using namespace std;

class PersonnelReport{
private:
	string emp;
	string empID;
	double daysOff;
	double sickDays;
public:
	PersonnelReport(const string &name, const string &ID, const int &months);
	friend ostream & operator <<(ostream & os, PersonnelReport &info);
};

ostream & operator << (ostream & os, PersonnelReport &info);

#endif