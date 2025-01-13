#include <iostream>

using namespace std;

// 函数模板
template <typename T>
void Swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}


int main(int argc, char* argv[]) {
	int a = 0;
	int b = 1;

	//SWAP(int, a, b);
	Swap(a, b);			// 自动推导
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double m = 2;
	double n = 3;
	//SWAP(double, m, n);
	Swap(m, n);			// 自动推导
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;

	string d = "Delphi";
	string t = "Tang";
	Swap<string>(d, t);	// 显示调用模板参数
	cout << "d = " << d << endl;
	cout << "t = " << t << endl;


	return 0;
}