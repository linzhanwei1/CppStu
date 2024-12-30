#include <stdio.h>

class Test {
private:
	int mi;
	void init(int i) {
		mi = i;
	}
public:
	Test() {
		printf("Test()\n");
		init(0);
	}
	Test(int i) {
		printf("Test(int i)\n");
		mi = i;
	}
	void print() { printf("mi = %d\n", mi); }
	~Test() {
		printf("~Test()\n");
	}
};

int main(int argc, char* argv[]) {
	printf("main begin\n");

	Test().print();		// 临时对象的生命周期和作用域都是一行
	Test(10).print();	// 临时对象的生命周期和作用域都是一行

	printf("main end\n");

	return 0;
}