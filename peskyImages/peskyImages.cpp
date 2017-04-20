#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> RGB;

void comparePesky();

int main(){
	comparePesky();

	return 0;
}

void comparePesky(){
	int x(0);
	int num1(0);
	int num2(0);
	int num3(0);
	string line;
	string line2;
	string line3;
	ifstream in1;
	ifstream in2;
	ifstream in3;
	ofstream out;

	in1.open("PeskyImages/Pesky1.ppm");
	in2.open("PeskyImages/Pesky2.ppm");
	in3.open("PeskyImages/Pesky4.ppm");
	out.open("peskyAll.ppm");
	while(getline(in1, line)){
		if(x > 2){
			stringstream ss(line);
			ss >> num1;
			if(getline(in2, line2)){
				stringstream aa(line2);
				aa >> num2;
				if(getline(in3, line3)){
					stringstream bb(line3);
					bb >> num3;

					if(num1 <= num2 && num1 <= num3){
						if(num2 <= num3)
							out << num2 << endl;
						else if(num3 <= num2)
							out << num3 << endl;
					}
					else if(num2 <= num1 && num2 <= num3){
						if(num1 <= num3)
							out << num1 << endl;
						else if(num3 <= num1)
							out << num3 << endl;
					}
					else if(num3 <= num1 && num3 <= num2){
						if(num1 <= num2)
							out << num1 << endl;
						else if(num2 <= num1)
							out << num2 << endl;
					}
				}
			}
		}
		else{
			out << line << endl;
			getline(in2, line2);
			getline(in3, line3);
		}
		x++;
	}
	in1.close();
	in2.close();
	in3.close();
	out.close();
}