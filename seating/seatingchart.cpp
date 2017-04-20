#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "UserInput.h"
using namespace std;

//construct the size of the theatre
const int rows = 15;
const int seats = 30;
string matrix[rows][seats];
//hold the total price
double finalPrice;
//holds name of 'theatre menu' file
string in;

//prints menu for options
void menu(string in);
//determine function dependent on menu option
void sendTo(string in);
//print a list of prices
void prices();
//prompts user where and how many tickest to buy
void tickets();
//show remaining seats in theatre
void remaining();
//prints total for seats purchased
void total();
//initializes empty theatre seats
void build(string matrix[rows][seats]);
//calculate cost of ticket and add to finalPrice
void buyTickets(int x, int y, int z);
//reserve seats in theatre (no reselling allowed)
void takeSeats(int x, int y, int z, double a);
//prints current availability of seats
void printSeats(string matrix[rows][seats]);

int main(){
	UserInput ask;
	cout << "please enter the name of the price file" << endl;
	in = ask.readString();
	build(matrix);
	menu(in);
	
	return 0;
}

void menu(string in){
	UserInput input;

	cout << "----------------------" << endl;
	cout << in << " menu" << endl;
	cout << "----------------------" << endl;
	cout << "s: View Searing Chart" << endl;
	cout << "p: View Prices Chart" << endl;
	cout << "b: Buy tickets" << endl;
	cout << "r: Number of Remaining Seats" << endl;
	cout << "t: Total Sales" << endl;
	cout << "q: Quit" << endl << endl;

	string let = input.readString();
	sendTo(let);
}

void sendTo(string let){
	if(let == "p" || let == "P"){
		prices();
	}
	if(let == "b" || let == "B"){
		tickets();
	}
	if(let == "r" || let == "R"){
		remaining();
	}
	if(let == "t" || let == "T"){
		total();
	}
	if(let == "s" || let == "S"){
		printSeats(matrix);
	}
	if(let == "q" || let == "Q"){
		exit(0);
	}
}

void prices(){
	int x(0);

	string line;
	ifstream fromFile;
	fromFile.open("prices.txt");
	while(getline(fromFile, line)){
		cout << "Price for row " << ++x << ": " << line << endl;
	}
	fromFile.close();

	cout << endl;
	menu(in);
}

void tickets(){
	UserInput input;

	cout << "What row do you want to sit in? ";
	int row = input.readInt();
	while(row > 15 || row < 1){
		cout << "There are only 15 rows" << endl;
		row = input.readInt();
	}
	cout << "How many seats do you want to buy? ";
	int seat = input.readInt();
	while(seat > 30 || seat < 1){
		cout << "There are only 30 seats in this row" << endl;
		seat = input.readInt();
	}
	cout << "What is the first seat you  want to buy? ";
	int start = input.readInt();
	while(start > (30 - seat) || start < 1){
		cout << "Please make space for everyone" << endl;
		start = input.readInt();
	}
	cout << endl;
	buyTickets(row, seat, start);
	menu(in);
}

void buyTickets(int row, int seat, int start){
	int x = 1;
	double getRow = 0;
	double localTotal = 0;

	string line;
	ifstream fromFile;
	fromFile.open("prices.txt");
	while(getline(fromFile, line)){
		if(x == row){
			stringstream ss(line);
			ss >> getRow;
		}
		x++;
	}
	fromFile.close();

	localTotal = (seat * getRow);
	finalPrice = finalPrice + localTotal;
	cout << "Total Cost = $" << localTotal << endl << endl;	

	takeSeats(row, seat, start, localTotal);
}

void remaining(){
	int count(0);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < seats; j++){
			if(matrix[i][j] == "*"){
				count++;
			}
		}
	}
	cout << "there are " << count << " seats left" << endl << endl;
	menu(in);
}

void total(){
	cout << "Total ticket sales = $" << finalPrice << endl << endl;
	menu(in);
}

void takeSeats(int row, int seat, int start, double refund){
	int out(0);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < seats; j++){
			if(row == i + 1 && j >= start - 1){
				if(matrix[i][j] == "#"){
					cout << "Sorry, " << "row " << i + 1;
					cout << " seat " << j + 1 << " is taken" << endl;
					out = 1;
				}
				else if((start + seat) >= j && out == 0){
					matrix[i][j] = "#";
				}
			}
		}
	}
	if(out == 1){
		finalPrice = finalPrice - refund;
	}
	out = 0;
	menu(in);
}

void printSeats(string matrix[rows][seats]){
	cout << "\t" << "abcdefghijklmnopqrstuvwxyz1234" << endl;
	for(int i = 0; i < rows; i++){
		cout << "Row " << i + 1 << "\t";
		for(int j = 0; j < seats; j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	menu(in);
}

void build(string matrix[rows][seats]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < seats; j++){
			matrix[i][j] = "*";
		}
	}
	menu(in);
}
