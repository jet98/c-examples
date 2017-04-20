#ifndef TIMEOFF_H
#define TIMEOFF_H

#include <iostream>
#include "numDays.h"

using namespace std;

class timeOff{
private:
	double sickTime;
	double vacationTime;
public:
	void setMonthsWorked(double months);
	double getSickDays() const;
	double getVacationDays() const;
	numDays sickDays(const double &monthsWorked);
	numDays vacationDays(const double &monthsWorked);	
};

#endif