#include <iostream>

using namespace std;

class A {
	int i;		// 4
	int j;		// 4
	char c;		// 4
public:
	void print() {
		cout << "i = " << i << ", "
			 << "j = " << j << ", "
			 << "c = " << c << endl;
	}
};

struct B {
	int i;		// 4
	int j;		// 4
	char c;		// 4
};

int main(int argc, char* argv[]) {
	A a;
	cout << "sizeof A = " << sizeof(A) << endl;		// 20
	cout << "sizeof a = " << sizeof(a) << endl;		// 20
	cout << "sizeof B = " << sizeof(B) << endl;		// 20

	a.print();
	B* p = reinterpret_cast<B*>(&a);

	p->i = 1;
	p->j = 2;
	p->c = 'c';
	a.print();

	p->i = 100;
	p->j = 200;
	p->c = 'C';
	a.print();

	return 0;
}