#include <iostream>
#include "personnelReport.h"
#include "timeOff.h"

using namespace std;

PersonnelReport::PersonnelReport(const string &name, const string &ID, const int &months){
	timeOff temp;
	emp = name;
	empID = ID;
	temp.setMonthsWorked(months);
	daysOff = temp.getVacationDays();
	sickDays = temp.getSickDays();
}

ostream & operator<< (ostream & os, PersonnelReport &info){
	os << info.emp << " (" << info.empID << ") ";
	os << "Days Off: " << info.daysOff;
	os << " Sick Days: " << info.sickDays;
	return os;
}