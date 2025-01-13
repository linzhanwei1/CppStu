#include "demo.h"
#include "malloc.h"

struct ClassDemo
{
	int mi;
	int mj;
};

Demo* DemoCreate(int i, int j) {
	struct ClassDemo* ret = malloc(sizeof(struct ClassDemo));
	if (ret) {
		ret->mi = i;
		ret->mj = j;
	}
	return ret;
}
int DemoGetI(Demo* this) {
	struct ClassDemo* ret = (struct ClassDemo*) this;
	return ret->mi;

}
int DemoGetJ(Demo* this) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->mj;
}
int DemoAdd(Demo* this, int value) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->mi + ret->mj + value;
}
void DemoFree(Demo* this) {
	free(this);
}