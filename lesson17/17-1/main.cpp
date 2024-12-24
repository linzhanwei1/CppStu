#include <stdio.h>

class Test {
private:
	int i;
	int j;
public:
	int getI() { return i; }
	int getJ() { return j; }

	Test() {
		i = 1;
		j = 2;
	}
};

Test gt;

int main(int argc, char* argv[]) {
	printf("gt.i = %d\n", gt.getI());
	printf("gt.j = %d\n", gt.getJ());

	Test t1;
	printf("t1.i = %d\n", t1.getI());
	printf("t1.j = %d\n", t1.getJ());

	Test* p1 = new Test;
	printf("p1.i = %d\n", p1->getI());
	printf("p1.j = %d\n", p1->getJ());

	delete p1;
	p1 = nullptr;
	return 0;
}