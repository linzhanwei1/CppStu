#include <iostream>

using namespace std;

// 函数模板
template <typename T>
void Swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T>
void Sort(T a[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (a[i] > a[j]) {
				Swap(a[i], a[j]);
			}
		}
	}
}

template <typename T>
void println(T a[], int len) {
	for (int i = 0; i < len; i++) {
		cout << a[i] << ", ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	int a[5] = { 5,3,2,4,1 };
	string s[5] = { "Java", "C++", "Pascal", "Basic", "Ruby" };

	println(a, sizeof(a) / sizeof(a[0]));
	Sort(a, sizeof(a) / sizeof(a[0]));
	println(a, sizeof(a) / sizeof(a[0]));

	println(s, sizeof(s) / sizeof(s[0]));
	Sort(s, sizeof(s) / sizeof(s[0]));
	println(s, sizeof(s) / sizeof(s[0]));

	return 0;
}