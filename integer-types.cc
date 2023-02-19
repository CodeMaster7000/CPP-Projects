#include <iostream>
#include <limits>

using namespace std;

int main() {

	int value = -12345;
	cout << value << endl;

	cout << "Maximum integer value: "<< INT_MAX << endl;
	cout << "Minimum integer value: "<< INT_MIN << endl;

	long int lValue = 23473298472984;
	cout << lValue << endl;

	short int sValue = 23473;
	cout << sValue << endl;

	cout << "Size of integer: " << sizeof(int) << endl;
	cout << "Size of short integer: " << sizeof(short int) << endl;

	unsigned int uValue = 234234;
	cout << uValue << endl;
	return 0;
}
