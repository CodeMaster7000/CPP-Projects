#include <iostream>
using namespace std;

int main() {

	int numberCats = 956;
	int numberDogs = 868;
	int numberAnimals = numberCats + numberDogs;

	cout << "Number of cats: " << numberCats << endl;
	cout << "Number of dogs: " << numberDogs << endl;

	cout << "Total number of animals: " << numberAnimals << endl;

	cout << "UPDATE: New dog acquired." << endl;

	numberDogs = numberDogs + 1;

	cout << "New number of dogs: " << numberDogs << endl;

	return 0;
}
