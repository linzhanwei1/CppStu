#include <stdio.h>

class Complex {
private:
	int a;
	int b;
public:
	Complex(int a = 0, int b = 0) {
		this->a = a;
		this->b = b;
	}
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}

	friend Complex add(const Complex& p1, const Complex& p2);
};

Complex add(const Complex& p1, const Complex& p2) {
	Complex ret;

	ret.a = p1.a + p2.a;
	ret.b = p1.b + p2.b;

	return ret;
}

int main(int argc, char* argv[]) {
	Complex c1 = { 1,2 };
	Complex c2 = { 3,4 };
	Complex c3 = add(c1, c2);

	printf("c3.a=%d c3.b=%d\n", c3.getA(), c3.getB());

	return 0;
}