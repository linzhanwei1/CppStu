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

template <>
class Test<void*, void*> {	// 当Test类模板的两个类型参数都是void*时，使用这个实现,完全特化
public:
	void add(void* a, void* b) {
		cout << "void add(void* a, void* b)" << endl;
		cout << "Error to add void* param..." << endl;
	}
};


int main(int argc, char* argv[]) {
	Test<int, float> t1;
	Test<long, long> t2;	// 使用局部特化实现
	Test<int, int> t3;		// 使用完全特化实现
	Test<void*, void*> t4;	// 使用完全特化实现

	t1.add(1, 2.5);
	t2.add(1, 1);
	t2.print();
	t3.add(1, 1);
	t4.add(NULL, NULL);

	return 0;
}