#include <iostream>

using namespace std;

int func(int i) {
	cout << "int func(int i) : i " << i << endl;
	return i;
}

int main() {
	int a = 0;
	int b = 1;

	if (func(0) && func(1)) {
		cout << "Result is true" << endl;
	}
	else {
		cout << "Result is false" << endl;
	}
	cout << endl;

	if (func(0) || func(1)) {
		cout << "Result is true" << endl;
	}
	else {
		cout << "Result is false" << endl;
	}

	return 0;
}