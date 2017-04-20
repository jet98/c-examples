#include <iostream>
#include "timeOff.h"
#include "numDays.h"

using namespace std;

void timeOff::setMonthsWorked(double months){
	sickDays(months);
	vacationDays(months);
}

double timeOff::getSickDays() const{
	return sickTime;
}

double timeOff::getVacationDays() const{
	return vacationTime;
}

numDays timeOff::sickDays(const double &monthsWorked){
	numDays temp;
	temp.add(monthsWorked*8);
	sickTime = temp.convertCurrent(temp);
}

numDays timeOff::vacationDays(const double &monthsWorked){
	numDays temp;
	temp.add(monthsWorked*12);
	vacationTime = temp.convertCurrent(temp);
}