#include <iostream>

using namespace std;

class Base {
public:
	Base() { cout << "Base::Base()" << endl; }
	virtual void func() { cout << "Base::func()" << endl; }
	virtual ~Base() { cout << "Base::~Base()" << endl; }	// 保证调用子类的析构
};

class Derived : public Base {
public:
	Derived() { cout << "Derived::Derived()" << endl; }
	void func() override { cout << "Derived::func()" << endl; }
	~Derived() { cout << "Derived::~Derived()" << endl; }
};

int main(int argc, char* argv[]) {
	Base* p = new Derived();
	delete p;

	return 0;
}