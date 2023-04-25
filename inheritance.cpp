#include <iostream>
using namespace std;

class Machine {
private:
	int id;

protected:
	int getId() { return id; }

public:
	Machine(): id(0) {};

};

class Vehicle: public Machine {
public:
	void info() { cout << "ID: " << getId() << endl; }
};

class Car: public Vehicle {
};

int main() {
	Car car;
	car.info();
	return 0;
}
