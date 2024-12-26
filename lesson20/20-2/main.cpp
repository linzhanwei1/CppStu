#include <stdio.h>

class Value {
private:
	int mi;
public:
	Value(int i) {
		printf("i = %d\n", i);
		mi = i;
	}
	int getI() {
		return mi;
	}
};

class Test {
private:
	Value m2;
	Value m3;
	Value m1;
public:
	Test() :m1(1), m2{ 2 }, m3{ 3 }{ printf("Test::Test()\n"); }
};

int main(int argc, char* argv[]) {
	Test t;

	return 0;
}