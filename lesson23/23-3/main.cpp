#include <stdio.h>

class Test {
private:
	int mi;
public:
	Test(int i) {
		printf("Test(int i) : %d\n", i);
		mi = i;
	}
	Test(const Test& t) {
		printf("Test(const Test& t) : %d\n", t.mi);
		mi = t.mi;
	}
	Test() {
		printf("Test()\n");
		mi = 0;
	}
	void print() {
		printf("mi = %d\n", mi);
	}
	~Test() {
		printf("~Test()\n");
	}
};

Test func() {
	return Test(20);
}

int main(int argc, char* argv[]) {
	Test t = Test(10);	// 1.生成临时对象 2.用临时对象初始化t对象 ==> Test t = 10
	Test tt = func();	// ==> Test tt = 20

	t.print();
	tt.print();

	return 0;
}