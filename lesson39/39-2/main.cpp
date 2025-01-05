#include <iostream>

using namespace std;

class Test {
private:
	int mValue;
public:
	Test(int i) {
		mValue = i;
	}
	int value() {
		return mValue;
	}
};

Test& operator ,(const Test& a, const Test& b) {
	return const_cast<Test&>(b);
}

Test func(Test& i) {
	cout << "func() : i = " << i.value() << endl;
	return i;
}

int main(int argc, char* argv[]) {
	Test t0(0);
	Test t1(1);
	Test tt = (func(t0), func(t1));	// 从右向左计算，结果一样

	func(tt);

	return 0;
}