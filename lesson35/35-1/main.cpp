#include <iostream>

using namespace std;

int fib() {
	static int a0 = 0;
	static int a1 = 1;
	int ret = a1;

	a1 = a0 + a1;
	a0 = a1;

	return ret;
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < 10; i++) {
		cout << fib() << endl;
	}

	return 0;
}