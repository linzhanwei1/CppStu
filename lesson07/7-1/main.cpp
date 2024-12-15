#include <stdio.h>

int mul(int x = 0);

int main(int argc, char* argv[]) {
	printf("%d\n", mul());		// 0
	printf("%d\n", mul(-1));	// 1
	printf("%d\n", mul(2));		// 4

	return 0;
}

int mul(int x) {
	return x * x;
}