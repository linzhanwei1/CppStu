#include <stdio.h>

double divide(double a, double b, int* valid) {
	const double delta = 0.000000000000001;
	double ret = 0;
	if (!(-delta < b && b < delta)){
		ret = a / b;
		*valid = 1;
	}
	else {
		// 异常处理
		*valid = 0;
	}
	return ret;
}

int main(int argc, char* argv[]) {
	int valid = 0;
	double r = divide(1, 0, &valid);		// 触发异常
	if (valid) {
		printf("r = %f\n", r);
	}
	else {
		printf("Divided by zero...\n");
	}
	

	return 0;
}