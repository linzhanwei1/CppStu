#include <iostream>

using namespace std;

class Test;

class Value {
public:
	Value() {}
	explicit Value(const Test& obj) {
		cout << "Value(const Test& obj)" << endl;
	}
};

class Test {
private:
	int mValue;
public:
	Test(int i = 0) {	// 转换构造函数
		mValue = i;
	}
	int value() {
		return mValue;
	}
	explicit operator int () {
		return mValue;
	}
	operator Value() {
		cout << "Test::operator Value()" << endl;
		return Value();
	}
};

int main(int argc, char* argv[]) {
	Test t(123);
	int i = static_cast<int>(t);
	Value v = t;	// 类型转换函数
	Value v1 = t;
	//int i = t.operator int();
	//int i = t;
	cout << "i = " << i << endl;

	return 0;
}