#include <iostream>
#include "majorityElement.h"

using namespace std;

majorityElement::majorityElement() : m_size(0){
	for(int i = 0; i < m_size; i++)
		majority[i] = 0;
}

majorityElement::majorityElement(const majorityElement &x){
	m_size = x.m_size;
	for(int i = 0; i < m_size; i++){
		majority[i] = x.majority[i];
	}
	majorityCount = x.majorityCount;
	majorityRep = x.majorityRep;
}

int majorityElement::size() const{
	return m_size;
}

void majorityElement::append(const int &value){
	majority[m_size-1] = value;

	if(findMajority(value) != -1){
		int temp[m_size + 1];
		for(int i = 0; i < m_size; i++){
			temp[i] = majority[i];
		}
		
		for(int i = 0; i < m_size; i++)
			majority[i] = temp[i];
	}
	m_size++;
}

void majorityElement::setAt(const int &index, const int &value){
	if(index > m_size)
		throw "Index Does Not Exist";
	else 
		majority[index] = value;
	findMajority(value);
}
	
void majorityElement::remove(const int &value){
	int temp[m_size];
	for(int i = 0; i < m_size; i++){
			if(majority[i] == value){}
			else
				temp[i] = majority[i];
		}

	if(findMajority(value) == -1)
		throw "Majority Element No Longer Represented";
	else{
		for(int i = 0; i < m_size-1; i++)
			majority[i] = temp[i];
	}
	m_size--;
}

void majorityElement::removeAt(const int &index){
	int temp[m_size];
	for(int i = 0; i < m_size; i++){
			if(i == index){}
			else
				temp[i] = majority[i];
		}

	if(findMajority(majority[index]) == -1){
		throw "Majority Element No Longer Represented";
	}
	else{
		for(int i = 0; i < m_size-1; i++)
			majority[i] = temp[i];
	}
	m_size--;
}

int majorityElement::findMajority(const int &value){
	int tempCount(0);
	if(m_size > 1){
		for(int i = 0; i < m_size; i++){
			for(int j = 0; j < m_size; j++){
				if(majority[i] == majority[j])
					tempCount++;
			}
			if(tempCount > majorityCount){
				majorityCount = tempCount;
				majorityRep = majority[i];
			}
			tempCount = 0;
		}
	}
	else{
		majorityCount = 1;
		majorityRep = majority[m_size-1];
		return 1;
	}

	if(majorityCount < (m_size/2))
		return 1;
	else
		return -1;

	
}

int majorityElement::operator[](const int &index){
	if(index < m_size)
		return majority[index];
	else
		throw "Index is outside the bounds";
}

ostream & operator<<(ostream &os, majorityElement &x){
	os << "The Majority Element is " << x.majorityRep << endl;

	return os;
}
