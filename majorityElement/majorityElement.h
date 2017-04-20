#ifndef MAJORITYELEMENT_H
#define MAJORITYELEMENT_H

#include <iostream>

using namespace std;

class majorityElement{
private:
	int majority[0];
	int m_size;
	int majorityCount;
	int majorityRep;
public:
	majorityElement();
	majorityElement(const majorityElement &x);
	int size() const;
	void append(const int &value);
	void setAt(const int &index, const int &value);
	void remove(const int &value);
	void removeAt(const int &index);
	int findMajority(const int &value);
	int operator[](const int &index);
	friend ostream &operator<<(ostream &os, majorityElement &x);
};

ostream &operator<<(ostream &os, majorityElement &x);

#endif