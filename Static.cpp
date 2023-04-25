#include <iostream>
using namespace std;

class Test {
public:
	static int const MAX = 99;

private:
	int id;
	static int count;

public:
	Test() {
		id = count++;
	}

	int getId() {
		return id;
	}

	static void showInfo() {
		cout << count << endl;
	}
};

int Test::count = 0;

int main() {

	cout << Test::MAX << endl;

	Test test1;
	cout << "Object 1 ID: " << test1.getId() << endl;

	Test test2;
	cout << "Object 2 ID: " << test2.getId() << endl;;

	Test::showInfo();

	return 0;
}
