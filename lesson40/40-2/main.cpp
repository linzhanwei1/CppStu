#include <iostream>

using namespace std;

class Test {
private:
	int mValue;
public:
	Test(int i) : mValue(i) {}
	int value() { return mValue; }
	Test& operator ++() {		// 前置 效率较高
		++mValue;
		return *this;
	}
	Test operator ++(int) {	// 后置 返回值[临时对象]不能是引用 效率较低需要生成临时变量
		Test t(this->mValue);
		mValue++;
		return t;
	}
};

int main(int argc, char* argv[]) {
	Test t(0);

	cout << "t.mValue: " << t++.value() << endl;
	cout << "t.mValue: " << t.value() << endl;

	return 0;
}