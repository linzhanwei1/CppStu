#include <stdio.h>

class Test {
public:
	static int mCount;
public:
	Test() {
		mCount++;
	}

	~Test() {
		--mCount;
	}
	static int getCount() {
		return mCount;
	}
};


// 初始化类的静态成员变量
int Test::mCount = 0;

int main(int argc, char* argv[]) {
	Test t1;
	Test t2;

	printf("count = %d\n", Test::getCount());

	return 0;
}