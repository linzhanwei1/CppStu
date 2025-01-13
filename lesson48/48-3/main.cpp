#include <iostream>

using namespace std;

class Parent {
public:
	int mi = 0;
	int add(int i) {
		mi += i;
		return mi;
	}
	int add(int a, int b) {
		mi += a + b;
		return mi;
	}
	void print() {
		cout << "I'm Parent." << endl;
	}
};

class Child :public Parent {
public:
	int mv = 0;
	int add(int x, int y, int z) {
		mv += x + y + z;
		return mv;
	}
	void print() {
		cout << "I'm Child." << endl;
	}
};

void how_to_print(Parent* p) {
	p->print();
}

int main(int argc, char* argv[]) {
	Parent p;
	Child c;

	how_to_print(&p);
	how_to_print(&c);

	return 0;
}