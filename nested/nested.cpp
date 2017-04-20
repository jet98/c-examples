#include <iostream>
#include <string>
using namespace std;

int main(){
	for(int i = 0; i < 6; i++){
		cout << i << " ";
		for(int j = 5; j >= 0; j--){
			cout << j << " ";
			for(int k = 0; k < 1; k++){
				cout << "024" << " ";
			}
		}
		cout << endl;
	}
	return 0;
}