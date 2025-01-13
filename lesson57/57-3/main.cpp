#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b) {
	cout << "T Max(T a, T b)" << endl;
	return a>b?a:b;
}

template <typename T>
T Max(T a, T b, T c) {
	cout << "T Max(T a, T b, T c)" << endl;
	return Max(Max(a, b),c);
}

int Max(int a, int b) {
	cout << "int Max(int a, int b)" << endl;
	return a > b ? a : b;
}

int main(int argc, char* argv[]) {
	int a = 1;
	int b = 2;
	int c = 3;

	cout << Max(a, b) << endl;			// int Max(int a, int b) 2
	cout << Max<>(a, b) << endl;		// 函数模板 Max<int>(int,int)
	cout << Max(3.0, 4.0) << endl;		// T Max(T a, T b) 4.0
	cout << Max(5.0, 6.0, 7.0) << endl;	// T Max(T a, T b, T c) 7.0
	cout << Max('a', 100) << endl;		// int Max(int a, int b) 100		函数模板不支持隐式类型转换

	return 0;
}