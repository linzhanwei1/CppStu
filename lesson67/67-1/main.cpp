#include <iostream>

using namespace std;

//void test(int i) {
//	cout << "void test(int i)" << endl;
//}

//template <typename T>
//void test(T v) {
//	cout << "void test(T v)" << endl;
//}

//void test(...) {
//	cout << "void test(...)" << endl;
//}

// 判断一个变量是否是指针
template <typename T>
bool IsPtr(T* v) {	// match pointer
	return true;
}

bool IsPtr(...) {	// match non-pointer
	return false;
}

class Test {
public:
	Test() {

	}
	~Test() {

	}
};

int main(int argc, char* argv[]) {
	int i = 0;
	int* p = &i;

	cout << "p is a pointer: " << IsPtr(p) << endl;		// true
	cout << "i is a pointer: " << IsPtr(i) << endl;		// false

	Test t;
	Test* pt = &t;

	cout << "pt is a pointer: " << IsPtr(pt) << endl;		// true
	cout << "t is a pointer: " << IsPtr(t) << endl;		// false


	return 0;
}