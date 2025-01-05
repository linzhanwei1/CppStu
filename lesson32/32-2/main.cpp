#if 0
#include <stdio.h>	// C兼容库
#include <string.h>	// C兼容库
#include <stdlib.h>	// C兼容库
#include <math.h>	// C兼容库
#endif
#include <cstdio>	// C++标准库兼容模块
#include <cstring>	// C++标准库兼容模块
#include <cstdlib>	// C++标准库兼容模块
#include <cmath>	// C++标准库兼容模块

using namespace std;

int main(int argc, char* argv[]) {
	printf("Hello world.\n");
	char* p = (char*)malloc(16);
	//strcpy_s(p, "D.T.Software");
	double a = 3;
	double b = 4;
	double c = sqrt(a * a + b * b);
	printf("c = %f\n", c);

	free(p);
	return 0;
}
