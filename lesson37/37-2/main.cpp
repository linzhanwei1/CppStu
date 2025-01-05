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
	~Test() {}
};

class Pointer {
private:
	Test* mp;
public:
	Pointer(Test* p = nullptr) {
		cout << "Pointer(Test* p = nullptr)" << endl;
		mp = p;
	}
	Test* operator->() {
		return mp;
	}
	Test& operator*() {
		return *mp;
	}
	~Pointer() {
		cout << "~Pointer()" << endl;
		delete mp;
		mp = nullptr;
	}
};

int main(int argc, char* argv[]) {
	for (int i = 0; i < 5; i++) {
		Pointer p = new Test(i);
		cout << p->value() << endl;
	}

	// memory leak

	return 0;
}