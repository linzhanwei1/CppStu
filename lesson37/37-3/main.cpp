#include <iostream>

using namespace std;

class Test {
private:
	int i;
public:
	Test(int i) {
		cout << "Test(int i)" << endl;
		this->i = i;
	}
	int value() {
		return i;
	}
	~Test() {
		cout << "~Test()" << endl;
	}
};

class Pointer {
private:
	Test* mp;
public:
	Pointer(Test* p = nullptr) {
		mp = p;
	}
	Pointer(const Pointer& obj) {
		mp = obj.mp;
		const_cast<Pointer&>(obj).mp = nullptr;
	}
	Pointer& operator=(const Pointer& obj) {
		if (this != &obj) {
			delete mp;
			mp = obj.mp;
			const_cast<Pointer&>(obj).mp = nullptr;
		}
		return *this;
	}
	bool isNull() {
		return (mp == nullptr);
	}
	Test* operator->() {
		return mp;
	}
	Test& operator*() {
		return *mp;
	}
	~Pointer() {
		delete mp;
		mp = nullptr;
	}
};

int main(int argc, char* argv[]) {
	Pointer p1 = new Test(0);

	cout << p1->value() << endl;
	Pointer p2 = p1;

	cout << p1.isNull() << endl;
	cout << p2->value() << endl;

	return 0;
}