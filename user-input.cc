#include <iostream>
using namespace std;

int main() {

	cout << "Enter your name: " << flush;
	string input;
	cin >> input;
	cout << "Your name is: " << input << endl;

	cout << "Enter a number of your choice: " << flush;
	int value;
	cin >> value;
	cout << "Number you chose: " << value << endl;

	return 0;
}
