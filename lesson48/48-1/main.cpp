#include <iostream>

using namespace std;

class Parent {
public:
	int mi=0;
	int add(int i) {
		mi += i;
		return mi;
	}
	int add(int a, int b) {
		mi += a + b;
		return mi;
	}
};

class Child :public Parent {
public:
	int mv=0;
	int add(int x, int y, int z) {
		mv += x + y + z;
		return mv;
	}
};

int main(int argc, char* argv[]) {
	Parent p;
	Child c;

	p = c;
	Parent p1(c);

	Parent& rp = c;
	Parent* pp = &c;
	Child cc;

	rp.mi = 100;
	rp.add(5);			// 没有发生同名覆盖
	rp.add(10, 10);		// 没有发生同名覆盖


	return 0;
}