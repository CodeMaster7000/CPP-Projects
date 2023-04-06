#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	fstream outFile;
	string outputFileName = "Hello_world.txt";
	 outFile.open(outputFileName, ios::out);
	if(outFile.is_open()) {
		outFile << "Hello world!" << endl;
		outFile << 1234567890 << endl;
		outFile.close();
	}
	else {
		cout << "Could not create file " << outputFileName << endl;
	}
	return 0;
}
