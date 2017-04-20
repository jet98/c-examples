#include <iostream>
#include "numDays.h"

using namespace std;

numDays::numDays(){}

void numDays::add(const double &hours){
	total = total + hours;
	current = hours;
}

double numDays::convert(const numDays &numDays){
	double d(0);
	return d = numDays.total/8;
}

double numDays::convertCurrent(const numDays &numDays){
	double d(0);
	return d = numDays.current/8;
}

numDays numDays::operator+(const numDays &other) const{
	numDays ret;
	ret.total = total + other.total;
	return ret;
}

numDays numDays::operator-(const numDays &other) const{
	numDays ret;
	ret.total = total - other.total;
	return ret;
}

numDays numDays::operator++(){
	total++;
	return *this;
}

numDays numDays::operator++(int){
	total++;
	return *this;
}

numDays numDays::operator--(){
	total--;
	return *this;
}

numDays numDays::operator--(int){
	total--;
	return *this;
}

ostream & operator<< (ostream & os, numDays &numDays){
	os << "Hours: " << numDays.total;
	return os;
}