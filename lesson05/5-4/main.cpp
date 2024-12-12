#include <stdio.h>

int& demo() {	// int* const
	int d = 0;
	printf("demo: d = %d\n", d);

	return d;	// 局部变量
}

int& func() {
	static int s = 0;
	printf("func: s = %d\n", s);

	return s;	// return &s
}

int main(int argc, char* argv[]) {
	int& rd = demo();
	int& rs = func();

	printf("\n");
	printf("main: rd = %d\n", rd);
	printf("main: rs = %d\n", rs);	// 0
	printf("\n");

	rd = 10;	// 栈中的值，非法修改
	rs = 11;	// 静态引用的变量

	demo();
	func();

	printf("\n");
	printf("main: rd = %d\n", rd);
	printf("main: rs = %d\n", rs);	// 11
	printf("\n");

	return 0;
}