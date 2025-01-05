#include <stdio.h>

void func() {
	printf("void func()\n");
}

void func(int i) {
	printf("void func(int i), i = %d\n", i);
}

class Test {
	int i;
public:
	Test() {
		printf("Test::Test()\n");
		this->i = 0;
	}
	Test(int i) {
		printf("Test::Test(int i)\n");
		this->i = i;
	}
	Test(const Test& obj) {
		printf("Test(const Test& obj)\n");
		this->i = obj.i;
	}
	static void func() {
		printf("void Test::func(int i)\n");
	}
	void func(int i) {
		printf("void Test::func(int i), i = %d\n", i);
	}
	int getI() {
		return i;
	}
};

int main() {
	func();
	func(1);

	Test t;
	Test t1(1);
	Test t2(t1);

	t.func();
	t.func(2);

	return 0;
}