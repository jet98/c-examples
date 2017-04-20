#include <iostream>
#include "UserInput.h"
using namespace std;

int main(){
	cout << "enter number of days" << endl;
	UserInput input;
	int in = input.readInt();
	cout << "days " << " " << " salary" << endl; 
	cout << "--------------------" << endl;

	int dub = 1;

	for(int i = 0; i < in; i++){
		if(i == 0){
			cout << i << "       " << dub << endl;
		}
		else{
			cout << i << "       " << dub << endl;
		}
		dub = dub * 2;
	}
	return 0;
}