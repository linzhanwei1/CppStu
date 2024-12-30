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
	 int getCount() {
		return mCount;
	}
};


// 初始化类的静态成员变量
int Test::mCount = 0;

int main(int argc, char* argv[]) {
	printf("count = %d\n", Test::mCount);

	return 0;
}