#include <stdio.h>

class Test {
private:
	int mi;
	void init(int i) {
		mi = i;
	}
public:
	Test() {
		init(0);
	}
	Test(int i) {
		mi = i;
	}
	void print() { printf("mi = %d\n", mi); }
};

int main(int argc, char* argv[]) {
	Test t;		

	t.print();

	return 0;
}