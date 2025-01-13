#include <iostream>

using namespace std;

class Parent {
public:
	void print() {
		cout << "I'm Parent." << endl;
	}
};

class Child : public Parent {
public:
	void print() {	// 函数重写，有一定意义
		cout << "I'm Child." << endl;
	}
};

int main(int argc, char* argv[]) {
	Parent().print();
	Child().print();

	return 0;
}