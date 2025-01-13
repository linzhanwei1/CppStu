#include <iostream>

using namespace std;

class BaseA {
public:
	virtual void funcA() {
		cout << "BaseA::funcA()" << endl;
	}
};

class BaseB {
public:
	virtual void funcB() {
		cout << "BaseB::funcB()" << endl;
	}
};

class Derived : public BaseA, public BaseB {

};

int main(int argc, char* argv[]) {
	Derived d;
	BaseA* pa = &d;
	BaseB* pb = &d;
	BaseB* pbe = (BaseB*)pa;	// oops!
	BaseB* pbb = dynamic_cast<BaseB*>(pa);

	cout << "sizeof(d) = " << sizeof(d) << endl;	// 2个虚函数表
	cout << "Using pa to call funcA()..." << endl;
	pa->funcA();
	cout << "Using pb to call funcB()..." << endl;
	pb->funcB();
	pbb->funcB();

	cout << "pa = " << pa << endl;
	cout << "pb = " << pb << endl;
	cout << "pbe = " << pbe << endl;
	cout << "pbb = " << pbb << endl;

	return 0;
}