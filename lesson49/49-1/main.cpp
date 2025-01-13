#include <iostream>

using namespace std;

class Parent {
public:
	virtual void print() {
		cout << "I'm Parent." << endl;
	}
};

class Child :public Parent {
public:
	void print() override {
		cout << "I'm Child." << endl;
	}
};

void how_to_print(Parent* p) {
	p->print();		// 展现多态行为
}

int main(int argc, char* argv[]) {
	Parent p;
	Child c;

	how_to_print(&p);
	how_to_print(&c);

	return 0;
}