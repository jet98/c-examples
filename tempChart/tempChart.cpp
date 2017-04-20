#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "helper.h"

using namespace std;

void populate(vector<double> &high, vector<double> &low);
void chart(const vector<double> &high, const vector<double> &low);

int main(){
	vector<double> high;
	vector<double> low;
	populate(high, low);
	chart(high, low);

	return 0;
}

void populate(vector<double> &high, vector<double> &low){
	string line;
	ifstream in;
	double temp;
	in.open("tempChart_april2003.txt");

	while(getline(in, line)){
		vector<string> values = split(line, ',');
		vector<string>::iterator start = values.begin();
		vector<string>::iterator end = values.end();

		for(vector<string>::iterator p = start; p != end; p++){
			if(p == start+1){
				stringstream ss(*p);
				ss >> temp;
				high.push_back(temp);
			}
			if(p == end-1){
				stringstream ss(*p);
				ss >> temp;
				low.push_back(temp);
			}
		}
	}
	in.close();
}

void chart(const vector<double> &high, const vector<double> &low){
	int x(40);
	int y(50);
	cout << "\t<= " << x << ": ";
	for(int i = 0; i < low.size(); i++){
		if(low[i] <= x){
			cout << "-";
		}
	}
	for(int i = 0; i < high.size(); i++){
		if(high[i] <= x){
			cout << "+";
		}
	}

	while(x <= 60){
		cout << endl << ">40 and <= 50: ";
		for(int i = 0; i < low.size(); i++){
			if(low[i] > x && low[i]<= y){
				cout << "-";
			}
		}
		for(int i = 0; i < high.size(); i++){
			if(high[i] > x && high[i]<= y){
				cout << "+";
			}
		}
		x += 10;
		y += 10;
	}

	cout << endl << "\t > " << y - 10 << ": ";
	for(int i = 0; i < low.size(); i++){
		if(low[i] > y - 10){
			cout << "-";
		}
	}
	for(int i = 0; i < high.size(); i++){
		if(high[i] > y - 10){
			cout << "+";
		}
	}
	cout << endl;
}