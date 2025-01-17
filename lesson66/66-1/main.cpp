#include <iostream>

using namespace std;

class Base {
public:
	virtual string type() {
		return "Base";
	}
};

class Derived : public Base {
public:
	string type() override {
		return "Derived";
	}
	void print() {
		cout << "I am a Derived." << endl;
	}
};

class Child : public Base {
public:
	string type() override {
		return "Child";
	}
};

void test(Base* b) {
	// 危险的转换方式
	//Derived* d = static_cast<Derived*>(b);
	cout << b->type() << endl;
	//if (b->type() == "Derived") {
	//	Derived* d = static_cast<Derived*>(b);
	//	d->print();
	//}

	cout << dynamic_cast<Derived*>(b) << endl;
}

int main(int argc, char* argv[]) {
	Base b;
	Derived d;
	Child c;

	test(&b);
	test(&d);
	test(&c);

	return 0;
}