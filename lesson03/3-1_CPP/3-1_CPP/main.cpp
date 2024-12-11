#include <stdio.h>

int main() {
	const int c = 0;
	int* p = (int*)&c;

	printf("Begin...\n");
	*p = 5;
	printf("c = %d\n", c);		// 从符号表中获得值
	printf("*p = %d\n", *p);
	printf("End...\n");

	return 0;
}