#include <iostream>

using namespace std;

class Demo {
private:
	int mi;
public:
	Demo(int i = 0) {
		mi = i;
	}
	virtual void print() {
		cout << "mi = " << mi << endl;
	}
};

class Test {
public:
	void* p;
	int mi;
};

int main(int argc, char* argv[]) {
	cout << "sizeof(Demo)" << sizeof(Demo) << endl;	// 4=虚函数表
	Demo d = 111;
	Test* t = reinterpret_cast<Test*>(&d);
	t->mi = 222;
	d.print();	// 222

	return 0;
}