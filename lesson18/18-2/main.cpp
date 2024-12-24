#include <stdio.h>

class Test {
private:
	int mValue;
public:
	Test() { printf("Test()\n"); mValue = 0; }
	Test(int v) { printf("Test(int v), v = %d\n", v); mValue = v; }

	int getValue() { return mValue; };
};

int main(int argc, char* argv[]) {
	//Test ta[3] = { 0,1,2 };
	Test ta[3] = { Test(0), Test(1), Test(2) };	// 手动调用构造函数

	for (int i = 0; i < 3; ++i) {
		printf("ta[%d].getValue() = %d\n", i, ta[i].getValue());
	}

	Test t = Test();	// 手动调用构造函数初始化对象
	printf("t:%d\n", t.getValue());

	return 0;
}