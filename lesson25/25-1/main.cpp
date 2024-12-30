#include <stdio.h>

class Test {
private:
	static int mCount;
public:
	Test() {
		mCount++;
	}

	~Test() {
		--mCount;
	}
	int getCount() {
		return mCount;
	}
};

// 全局
Test gTest;

// 初始化类的静态成员变量
int Test::mCount = 0;

int main(int argc, char* argv[]) {
	Test t1;
	Test t2;

	printf("count = %d\n", gTest.getCount());
	printf("count = %d\n", t1.getCount());
	printf("count = %d\n", t2.getCount());

	return 0;
}