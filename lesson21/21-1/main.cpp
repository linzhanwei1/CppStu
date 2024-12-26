#include <stdio.h>

class Test {
private:
	int mi;
public:
	Test(int i) {
		mi = i;
		printf("Test(int i): %d\n", mi);
	}
	Test(const Test& obj) {
		mi = obj.mi;
		printf("Test(const Test& obj): %d\n", mi);
	}
};

int main(int argc, char* argv[]) {
	int i = 0;
	Test a1 = i;		// Test(int i): 0

	while (i < 3) {
		Test a2 = ++i;	// Test(const Test& obj): 1
						// Test(const Test& obj): 2
						// Test(const Test& obj): 3
	}

	if (i < 4) {
		Test a = a1;	// Test(const Test& obj): 0
	}
	else {
		Test a(100);
	}

	return 0;
}