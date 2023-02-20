#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	float fValue = 123.456789;

	cout << "Size of float: " << sizeof(float) << endl;
	cout << setprecision(20) << fixed << fValue << endl;

	double dValue = 123.456789;
	cout << setprecision(20) << fixed << dValue << endl;

	long double lValue = 123.45678987654321;
	cout << setprecision(20) << fixed << lValue << endl;
	cout << "Size of long double: " << sizeof(lValue) << endl;

	return 0;
}
