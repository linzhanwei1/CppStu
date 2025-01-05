#include <iostream>

using namespace std;

class Test {
private:
	int i;
public:
	Test(int i) {
		this->i = i;
	}
	int value() {
		return i;
	}
	~Test(){}
};

int main(int argc, char* argv[]) {
	for (int i = 0; i < 5; i++) {
		Test* p = new Test(i);
		cout << p->value() << endl;
	}

	// memory leak

	return 0;
}