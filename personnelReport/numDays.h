#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>
#include <string>

using namespace std;

class numDays{
private:
	double current;
	double total;
public:
	numDays();
	void add(const double &hours);
	double convert(const numDays &numDays);
	double convertCurrent(const numDays &numDays);
	numDays operator+(const numDays &other) const;
	numDays operator-(const numDays &other) const;
	numDays operator++();
	numDays operator--();
	numDays operator++(int);
	numDays operator--(int);
	friend ostream & operator <<(ostream & os, numDays &numDays);
};

ostream & operator << (ostream & os, numDays &numDays);

#endif