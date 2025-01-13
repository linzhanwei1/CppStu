#include <iostream>

using namespace std;

class Base {
protected:
	int mi;
public:
	Base(int i) {
		mi = i;
	}
	int GetI() {
		return mi;
	}
	bool equal(Base* obj) {
		return (this == obj);
	}
};

class Interface01 {
public:
	virtual void add(int i) = 0;
	virtual void minus(int i) = 0;
};

class Interface02 {
public:
	virtual void multiply(int i) = 0;
	virtual void divide(int i) = 0;
};

class Derived : public Base, public Interface01, public Interface02 {
public:
	Derived(int i) : Base(i) { }
	void add(int i) {
		mi += i;
	}
	void minus(int i) {
		mi -= i;
	}
	void multiply(int i) {
		mi *= i;
	}
	void divide(int i) {
		if (i) {
			mi /= i;
		}
	}
};

int main(int argc, char* argv[]) {
	Derived d(100);
	Derived* p = &d;
	Base* pBase = &d;
	Interface01* pInt1 = &d;
	Interface02* pInt2 = &d;

	//cout << "p->getI() = " << p->GetI() << endl;	// 100
	//pInt1->add(10);
	//pInt2->divide(11);
	//pInt1->minus(5);
	//pInt2->multiply(8);
	//cout << "p->getI() = " << p->GetI() << endl;	// 40

	cout << endl;
	cout << "p = : " << p << endl;
	cout << "pBase = : " << pBase << endl;
	cout << "pInt1 = : " << pInt1 << endl;
	cout << "pInt2 = : " << pInt2 << endl;
	cout << "dynamic_cast<Base*>(pInt1) = " << dynamic_cast<Base*>(pInt1) << endl;
	cout << "dynamic_cast<Base*>(pInt2) = " << dynamic_cast<Base*>(pInt2) << endl;
	cout << "pInt1 == p : " << p->equal(dynamic_cast<Base*>(pInt1)) << endl;	// 1
	cout << "pInt2 == p : " << p->equal(dynamic_cast<Base*>(pInt2)) << endl;	// 1

	return 0;
}
