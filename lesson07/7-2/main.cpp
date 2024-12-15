#include <stdio.h>

// 占位参数
int func(int x, int) {
	return x;
}

int add(int x, int y = 0, int z = 0);

int main(int argc, char* argv[]) {
	printf("%d\n", add(1));			// 1
	printf("%d\n", add(1, 2));		// 3
	printf("%d\n", add(1, 2, 3));	// 6

	func(1, 2);

	return 0;
}

int add(int x, int y, int z) {
	return x + y + z;
}