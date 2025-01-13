#include <iostream>

using namespace std;

class Demo {
protected:
	int mi;
	int mj;
};

class Derived : public Demo {
private:
	int mk;
public:
	Derived(int i, int j, int k) {
		mi = i;
		mj = j;
		mk = k;
	}
	void print() {
		cout << "mi = " << mi << ", "
			<< "mj = " << mj << ", "
			<< "mk = " << mk << endl;
	}
};

struct Test {
	int mi;
	int mj;
	int mk;
};

int main(int argc, char* argv) {
	cout << "sizeof(Demo) = " << sizeof(Demo) << endl;	// 8
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;	// 12

	Derived d(1, 2, 3);
	Test* p = reinterpret_cast<Test*>(&d);
	d.print();
	
	cout << "==================================\n";

	p->mi = 10;
	p->mj = 20;
	p->mk = 30;
	d.print();



	return 0;
}