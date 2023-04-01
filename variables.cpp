#include <iostream>
using namespace std;

int main() {

	int numberOfCats = 956;
	int numberOfDogs = 868;
	int numberOfAnimals = numberOfCats + numberOfDogs;

	cout << "Number of cats: " << numberOfCats << endl;
	cout << "Number of dogs: " << numberOfDogs << endl;

	cout << "Total number of animals: " << numberOfAnimals << endl;

	cout << "UPDATE: New dog acquired." << endl;

	numberOfDogs = numberOfDogs + 1;

	cout << "New number of dogs: " << numberOfDogs << endl;

	return 0;
}
