#include <iostream>

using namespace std;

class Fib {
private:
	int a0;
	int a1;
public:
	Fib():a0(0),a1(1) {}
	Fib(int n):a0(0), a1(1) {
		for (int i = 2; i <= n; i++) {
			int t = a1;
			a1 = a0 + a1;
			a0 = t;
		}
	}
	int operator()() {
		int ret = a1;
		a1 = a0 + a1;
		a0 = a1;
		return ret;
	}
};

int main(int argc, char* argv[]) {
	Fib fib;
	for (int i = 0; i < 10; i++) {
		cout << fib() << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++) {
		cout << fib() << endl;
	}
	cout << endl;
	
	Fib fib2(10);
	for (int i = 0; i < 5; i++) {
		cout << fib2() << endl;
	}

	return 0;
}