#include <iostream>

using namespace std;

class Parent {
public:
	virtual void func() {	// 被同名覆盖
		cout << "void func()" << endl;
	}
	virtual void func(int i) {	// 被同名覆盖
		cout << "void func(int i) : " << i << endl;
	}
	virtual void func(int i, int j) {	// 被同名覆盖
		cout << "void func(int i, int j) : " << "(" << i << ", " << j << ")" << endl;
	}
};

class Child : public Parent {
public:
	void func(int i, int j) override {	// 重写
		cout << "void func(int i, int j) : " << i + j << endl;
	}
	void func(int i, int j, int k) {	// 同名覆盖
		cout << "void func(int i, int j, int k) : " << i + j + k << endl;	
	}
};

void run(Parent* p) {
	p->func(1, 2);
}

int main(int argc, char* argv[]) {
	Parent p;

	p.func();		// 静态联编
	p.func(1);		// 静态联编
	p.func(1, 2);	// 静态联编

	cout << endl;

	Child c;

	c.func(1, 2);	// 静态联编
	cout << endl;

	run(&p);		// 动态联编
	run(&c);		// 动态联编

	return 0;
}