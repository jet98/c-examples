#include <iostream>
#include <vector>
#include "helper.h"

using namespace std;

void printResult(const vector<int> &vitA, const vector<int> &vitC, const vector<int> &vitD);
int findBest(const vector<int> &vitA, const vector<int> &vitC, const vector<int> &vitD);

struct vitamin{
	int vitA;
	int vitC;
	int vitD;
};

int main(){
	vitamin data = {0,0,0};
	vector<int> totalVitA;
	vector<int> totalVitC;
	vector<int> totalVitD;

	for(int i = 0; i < 100; i++){
		data.vitA++;
		for(int j = 0; j < 100; j++){
			data.vitC++;
			if(data.vitC == 100)
				data.vitC = 0;
			for(int k = 0; k < 100; k++){
				if(((2*data.vitC*data.vitC) - (3*data.vitD) + (10*data.vitA*data.vitA) + 43) == 0){
					totalVitD.push_back(data.vitD);
					totalVitC.push_back(data.vitC);
					totalVitA.push_back(data.vitA);
				}
				data.vitD++;
				if(data.vitD == 100)
					data.vitD = 0;
			}
		}
	}
	printResult(totalVitA, totalVitC, totalVitD);

	return 0;
}

void printResult(const vector<int> &vitA, const vector<int> &vitC, const vector<int> &vitD){
	int best = 0;

	cout << "Found " << vitA.size() << " Solutions:" << endl;
	for(int i = 0; i < vitA.size(); i++){
		cout << "Vitamin A = " << vitA[i] << " ";
		cout << "Vitamin C = " << vitC[i] << " ";
		cout << "Vitamin D = " << vitD[i] << " ";
		cout << endl;
	}
	best = findBest(vitA, vitC, vitD);

	cout << endl << "Best Solution:" << endl;
	cout << "Vitamin A = " << vitA[best] << " ";
	cout << "Vitamin C = " << vitC[best] << " ";
	cout << "Vitamin D = " << vitD[best] << " ";
	cout << endl;

}

int findBest(const vector<int> &vitA, const vector<int> &vitC, const vector<int> &vitD){
	int best = vitA[0] + vitC[0] + vitD[0];

	for(int i = 1; i < vitD.size(); i++){
		if((vitA[i] + vitC[i] + vitD[i] < best))
			best = i;
	}
}