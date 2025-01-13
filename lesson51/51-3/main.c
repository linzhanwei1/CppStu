#include "demo.h"
#include <stdio.h>

void run(Demo* p, int v) {
	int r =DemoAdd(p, v);
	printf("r = %d\n", r);
}

int main(int argc, char* argv[]) {
	Demo* pb = DemoCreate(1, 2);
	Derived* pd = DerivedCreate(1, 22, 333);

	printf("pb->add(3) = %d\n", DemoAdd(pb, 3));
	printf("pd->add(3) = %d\n", DerivedAdd(pd, 3));

	run(pb, 3);
	run(pd, 3);

	DemoFree(pb);
	DemoFree(pd);

	return 0;
}