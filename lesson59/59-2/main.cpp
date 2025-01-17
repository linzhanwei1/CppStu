#include <iostream>

using namespace std;

template <typename T1, typename T2>
class Test {
public:
	void add(T1 a, T2 b) {
		cout << "void add(T1 a, T2 b)" << endl;
		cout << a + b << endl;
	}
};

template <typename T>
class Test<T, T> {	// 当Test类模板的两个类型参数完全相同时，使用这个实现,局部特化
public:
	void add(T a, T b) {
		cout << "void add(T a, T b)" << endl;
		cout << a + b << endl;
	}
	void print() {
		cout << "==void add(T a, T b)==" << endl;
	}
};

template <>
class Test<int, int> {	// 当Test类模板的两个类型参数都是Int时，使用这个实现,完全特化
public:
	void add(int a, int b) {
		cout << "void add(int a, int b)" << endl;
		cout << a + b << endl;
	}
};

// 重新定义新类
class TestVoid {
public:
	void add(void* a, void* b) {
		cout << "void add(void* a, void* b)" << endl;
		cout << "Error to add void* param..." << endl;
	}
};

//template <>
//class Test<void*, void*> {	// 当Test类模板的两个类型参数都是void*时，使用这个实现,完全特化
//public:
//	void add(void* a, void* b) {
//		cout << "void add(void* a, void* b)" << endl;
//		cout << "Error to add void* param..." << endl;
//	}
//};

// 函数模板的特化
template <typename T>
bool Equal(T a, T b) {
	cout << "Equal(T a, T b)" << endl;
	return a == b;
}

// 浮点数应该被完全特化
template < >
bool Equal<double>(double a, double b) {
	const double delta = 0.00000000000001;
	double r = a - b;
	cout << "Equal<double>(double a, double b)" << endl;
	return (-delta < r) && (r < delta);
}

int main(int argc, char* argv[]) {
	cout << Equal(1, 1) << endl;
	cout << Equal(0.01, 0.01) << endl;

	return 0;
}