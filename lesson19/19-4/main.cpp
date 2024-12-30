#include <stdio.h>

class Test {
private:
	int i;
public:
	//Test() :i{ 0 } { printf("Test()\n"); }
	int geti() { return i; }
};

int main(int argc, char* argv[]) {
	Test* p1 = new Test;
	Test* p2 = new Test();

	printf("*p1.i = %d\n", (*p1).geti());
	printf("*p2.i = %d\n", (*p2).geti());

	return 0;
}