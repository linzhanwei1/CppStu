#include <iostream>

using namespace std;

class Test {
private:
	int mValue;
public:
	explicit Test(int i=0):mValue(i){  }
	Test operator + (const Test& p) {
		Test ret(mValue + p.mValue);
		return ret;
	}
	int value() {
		return mValue;
	}
};

int main(int argc, char* argv[]) {
	Test t;

	t = static_cast<Test>(5);	// t = Test(5);

	Test r;
	r = t + static_cast < Test>(10);	// t + Test(10) 隐式类型转换
	cout << r.value() << endl;

	return 0;
}