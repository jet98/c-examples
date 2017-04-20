#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "helper.h"

using namespace std;

void getCount();

struct count{
	int juve;
	int adult;
	int dead;
	double total;
};

int main(){
	getCount();

	return 0;
}

void getCount(){
	cout << fixed << setprecision(2);
	count x = {0,0,0,0};
	string line;
	ifstream in;
	in.open("data.txt");

	while(getline(in, line)){
		vector<string> tokens = split(line, ',');
		vector<string>::iterator start = tokens.begin();
		vector<string>::iterator end = tokens.end();
		for (vector<string>::iterator p = start; p != end; p++)
		{
			string token = trim(*p);
			if(token == "A")
				x.adult++;
			if(token == "D")
				x.dead++;
			if(token == "J")
				x.juve++;
			x.total++;
		}
	}

	in.close();

	cout << "Percent of Adults: " << (x.adult / x.total) * 100 << "%" << endl;
	cout << "Percent of Dead: " << (x.dead / x.total) * 100 << "%" << endl;
	cout << "Percent of Juvenile: " << (x.juve / x.total) * 100 << "%" << endl;
}