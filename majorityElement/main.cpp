#include <iostream>
#include "majorityElement.h"

using namespace std;

int main(){
	majorityElement test;
	test.append(10);
	cout << test.size() << endl;
	test.remove(10);
	test.append(15);
	test.append(15);
	test.append(10);
	test.setAt(1, 10);
	cout << test << endl;

	//test.removeAt(2);
	//majorityElement test2(test);

	cout << test << endl;

	return 0;
}