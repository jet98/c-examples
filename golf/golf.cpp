#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "helper.h"

using namespace std;

struct info{
	double total;
	double avg;
};

int main(){
	info data = {0,0};
	string line;
	ifstream in;
	in.open("golf.txt");

	while(getline(in, line)){
		vector<string> temperature = split(line, ',');
		vector<string>::iterator start = temperature.begin();
		vector<string>::iterator end = temperature.end();

		for(vector<string>::iterator p = start; p != end; p++){
			if(p == start){
				stringstream ss(*p);
				ss >> data.month;
				trackMonth.push_back(data.month);
			}
			if(p == end-2){
				stringstream ss(*p);
				ss >> data.year;
				trackYear.push_back(data.year);
			}

			if(p == end-1){
				stringstream ss(*p);
				ss >> data.temp;
				trackTemp.push_back(data.temp);
			}
		}
	}

	in.close();

	getMonth();
	getYear();

	return 0;
}

void getMonth(){
	int countMonth(1);
	info data = {0,trackTemp[0],trackTemp[0],trackTemp[0],trackTemp[0],
		trackTemp[0],trackTemp[0],trackTemp[0],trackTemp[0],trackTemp[0],
		trackTemp[0],trackTemp[0],trackTemp[0],trackTemp[0],0.0};

	cout << fixed << setprecision(2);

	do{
		if(trackMonth[countMonth] == 1){
			data.jan = (data.jan + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 2){
			data.feb = (data.feb + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 3){
			data.mar = (data.mar + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 4){
			data.apr = (data.apr + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 5){
			data.may = (data.may + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 6){
			data.jun = (data.jun + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 7){
			data.jul = (data.jul + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 8){
			data.aug = (data.aug + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 9){
			data.sep = (data.sep + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 10){
			data.oct = (data.oct + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 11){
			data.nov = (data.nov + trackTemp[countMonth]) / 2;
		}
		if(trackMonth[countMonth] == 12){
			data.dec = (data.dec + trackTemp[countMonth]) / 2;
		}
		countMonth++;
	}
	while(countMonth < trackMonth.size());

	cout << "Avg temp for January: " << data.jan << endl;
	cout << "Avg temp for February: " << data.feb << endl;
	cout << "Avg temp for March: " << data.mar << endl;
	cout << "Avg temp for April: " << data.apr << endl;
	cout << "Avg temp for May: " << data.may << endl;
	cout << "Avg temp for june: " << data.jun << endl;
	cout << "Avg temp for July: " << data.jul << endl;
	cout << "Avg temp for August: " << data.aug << endl;
	cout << "Avg temp for September: " << data.sep << endl;
	cout << "Avg temp for October: " << data.oct << endl;
	cout << "Avg temp for November: " << data.nov << endl;
	cout << "Avg temp for December: " << data.dec << endl;
	cout << endl;
}

void getYear(){
	int count(1);
	int countYear;
	info data = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0.0};

	do{
		data.year = trackTemp[count-1];
		countYear = trackYear[count];

		while(countYear == trackYear[count]){
			data.year = (data.year + trackTemp[count]) / 2;
			count++;
		}
		cout << "Avg temp for " << countYear << ": " << data.year << endl;
	}
	while(count < trackYear.size());
}