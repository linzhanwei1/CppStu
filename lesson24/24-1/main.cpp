#include <stdio.h>

class Member {
private:
	const char* ms;
public:
	Member(const char* s) {
		printf("Member(const char* s): %s\n", s);
		ms = s;
	}
	~Member() {
		printf("~Member(): %s\n", ms);
	}
};

class Test {
private:
	Member mA;
	Member mB;
public:
	Test() : mB("mB"), mA("mA") {
		printf("Test()\n");
	}
	~Test() {
		printf("~Test()\n");
	}
};

int main() {
	Test t;

	return 0;
}