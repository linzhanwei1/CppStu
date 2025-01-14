#include <iostream>

using namespace std;

class Test {
private:
	int mValue;
public:
	Test(int v) {
		mValue = v;
	}
	int value() const {
		return mValue;
	}
};

bool operator &&(const Test& l, const Test& r) {
	return l.value() && r.value();
}

bool operator ||(const Test& l, const Test& r) {
	return l.value() || r.value();
}

Test func(Test i) {
	cout << "int func(Test i) : i.value() = " << i.value() << endl;
	return i;
}

int main() {
	Test t0(0);
	Test t1(1);

	if ( operator &&(func(t0), func(t1))) {
		cout << "Result is true" << endl;
	}
	else {
		cout << "Result is false" << endl;
	}
	cout << endl;
	if (operator ||(func(t0), func(t1))) {
		cout << "Result is true" << endl;
	}
	else {
		cout << "Result is false" << endl;
	}

	return 0;
}