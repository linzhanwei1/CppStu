#include <stdio.h>

class Test {
private:
	const int ci;
public:
	int getCI() { return ci; }
};


int main(int argc, char* argv[]) {
	Test t;
	printf("Test.ci:%d\n", t.getCI());

	return 0;
}