#include <stdio.h>

class C {
	const char* n;
public:
	C(const char* n) {
		this->n = n;
	}
	friend class B;
};

class B {
	const char* n;
public:
	B(const char* n) {
		this->n = n;
	}
	void getClassCName(C& c) {
		printf("c.n = %s\n", c.n);
	}
	friend class A;
};

class A {
	const char* n;
public:
	A(const char* n) {
		this->n = n;
	}
	void getClassBName(B& b) {
		printf("b.n = %s\n", b.n);
	}
	//void getClassCName(C& c) {
	//	printf("c.n = %s\n", c.n);
	//}
};

int main(int argc, char* argv[]) {
	A a("A") ;
	B b("B");
	C c("C");

	a.getClassBName(b);
	b.getClassCName(c);
	//a.getClassCName(c);

	return 0;
}