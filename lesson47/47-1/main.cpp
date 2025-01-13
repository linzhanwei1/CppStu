#include <iostream>

using namespace std;

class Parent {
public:
	int mi;

	Parent() {
		cout << "Parent() : " << "&mi = " << &mi << endl;
	}
};

class Child : public Parent {
public:
	int mi;
	Child() {
		cout << "Child() : " << "&mi = " << &mi << endl;
	}
};

int main(int argc, char* argv[]) {
	Child c;

	c.mi = 100;				// 子类中的成员
	c.Parent::mi = 200;		// 父类中的成员

	cout << "&c.mi = " << &c.mi << endl;
	cout << "c.mi = " << c.mi << endl;

	cout << "&c.Parent::mi = " << &c.Parent::mi << endl;
	cout << "c.Parent::mi = " << c.Parent::mi << endl;

	return 0;
}