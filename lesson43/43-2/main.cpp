#include <iostream>
#include <string>

using namespace std;

class Parent {
private:
	int mv;
public:
	Parent() {
		cout << "Parent()" << endl;
		mv = 100;
	}
	void method() {
		cout << "mv = " << mv << endl;
	}
};

class Child : public Parent {
public:
	void hello() {
		cout << "I'm Child class!" << endl;
	}
};

int main(int argc, char* argv[]) {
	Child c;
	Parent p1 = c;
	Parent p2;
	

	c.hello();
	c.method();

	return 0;
}