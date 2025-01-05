#include <iostream>

using namespace std;

class Test {
public:
	int operator [](int i) {
		return 0;
	}
	int operator [](const char* s) {
		return 0;
	}
};

int main(int argc, char* argv[]) {
	Test t;

	cout << t[1] << endl;

	return 0;
}