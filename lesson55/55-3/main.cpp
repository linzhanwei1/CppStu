#include <iostream>

using namespace std;

class Base {
public:
	Base() { cout << "Base::Base()" << endl; }
	virtual ~Base() { cout << "Base::~Base()" << endl; }
};

class Derived : public Base {

};

int main(int argc, char* argv[]) {
	Base* p = new Derived;
	Derived* pd = dynamic_cast<Derived*>(p);
	if (pd != nullptr) {
		cout << "pd = " << pd << endl;
	}
	else {
		cout << "Cast error!" << endl;
	}
	
	delete p;

	return 0;
}