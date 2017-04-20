#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "UserInput.h"
#include "FileReader.h"
#include "helper.h"
#include "numDays.h"
#include "timeOff.h"
#include "personnelReport.h"

using namespace std;

int main(){
	//testing the different classes
	numDays temp;
	temp.add(12);
	temp.add(12);
	numDays temp2;
	temp2.add(21);
	cout << temp << endl << "Days: " << temp.convert(temp) << endl;
	cout << temp2 << endl << "Days: " << temp2.convert(temp2) << endl;
	temp2--;
	cout << temp2 << endl << "Days: " << temp2.convert(temp2) << endl;
	numDays temp3 = temp + temp2;
	cout << temp3 << endl << "Days: " << temp3.convert(temp3) << endl;
	++temp3;
	cout << temp3 << endl << "Days: " << temp3.convert(temp3) << endl;
	cout << endl << endl;

	timeOff guest;
	guest.setMonthsWorked(13);
	cout << "SIC: " << guest.getSickDays() << endl << "VAC: " << guest.getVacationDays() << endl;
	cout << endl;

	//running the assignment
	try{
		/*	everytime I try to run the fileReader I get a
			file not found, but it works with fstream  */
		//UserInput i;
		//FileReader in(i.readString("employee.txt"));
		ifstream in;
		string line;
		in.open("employee.txt");
		while(getline(in, line)){
			vector<string> tokens = split(line, ',');
			PersonnelReport rpt(tokens[0], tokens[1], atof(tokens[2].c_str()));
			cout << rpt << endl;
		}
		in.close();
	}
	catch(const char * msg){
		cout << msg << endl;
	}
}