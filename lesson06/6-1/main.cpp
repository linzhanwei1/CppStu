#include <stdio.h>

#define FUNC(a, b) ((a) < (b) ? (a) : (b))

#if 0
// 宏代码块的副作用
inline int func(int a, int b) {
	return a < b ? a : b;
}

int main(int argc, char* argv[]) {
	int a = 1;
	int b = 3;
	int c = FUNC(++a, b);	// (2) < 3 ? 3 : 1

	printf("a = %d\n", a);	// 3
	printf("b = %d\n", b);	// 3
	printf("c = %d\n", c);	// 3

	return 0;
}
#endif
// 内联函数示例
inline int func(int a, int b) {
	return a < b ? a : b;
}

int main(int argc, char* argv[]) {
	int a = 1;
	int b = 3;
	int c = func(++a, b);	// 2 < 3 ? 2 : 3

	printf("a = %d\n", a);	// 2
	printf("b = %d\n", b);	// 3
	printf("c = %d\n", c);	// 2

	return 0;
}