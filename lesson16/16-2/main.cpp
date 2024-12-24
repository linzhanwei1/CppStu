#include "operator.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
	Operator o;
	double ret;

	o.setOperator('-');
	o.SetParameter(1, 2);
	if (o.result(ret)) {
		printf("result: %f\n", ret);
	}
	else {
		printf("failed.\n");
	}

	return 0;
}