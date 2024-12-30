#include <stdio.h>

class Test {
public:
	Test() {
		printf("Test()\n");
	}
	~Test() {
		printf("~Test()\n");
	}
};

int main(int argc, char* argv[]) {
	Test t;
	Test* pt = new Test;

	delete pt;

	return 0;
}