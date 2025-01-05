#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	// 小类型初始化大类型是安全的，可以进行隐士转换
	short s = 'a';
	unsigned int ui = 1000;
	int i = -2000;
	double d = i;

	cout << "d = " << d << endl;
	cout << "ui = " << ui << endl;
	cout << "ui + i = " << ui + i << endl;	// 4294966296

	if ((ui + i) > 0) {
		cout << "Positive" << endl;
	}
	else {
		cout << "Negative" << endl;
	}

	cout << "sizeof(s + 'b') = " << sizeof(s + 'b') << endl;	// sizeof(s + 'b') = 4

	return 0;
}