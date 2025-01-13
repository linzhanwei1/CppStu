#include <iostream>

using namespace std;

class Parent {
protected:
	int mv;
public:
	Parent() {
		mv = 100;
	}
	int Value() {
		return mv;
	}
};

class Child : public Parent {
public:
	int addValue(int v) {
		mv = mv + v;
		return mv;
	}
};

int main(int argc, char* argv[]) {
	Parent p;
	Child c;

	cout << "p.mv = " << p.Value() << endl;
	cout << "c.mv = " << c.Value() << endl;

	c.addValue(50);
	cout << "c.mv = " << c.Value() << endl;

	return 0;
}