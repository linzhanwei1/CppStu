#include "demo.h"
#include "malloc.h"

struct ClassDemo
{
	int mi;
	int mj;
};

struct ClassDerived {
	struct ClassDemo d;
	int mk;
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


Derived* DerivedCreate(int i, int j, int k) {
	struct ClassDerived* ret = malloc(sizeof(struct ClassDerived));
	if (ret) {
		ret->d.mi = i;
		ret->d.mj = j;
		ret->mk = k;
	}
	return ret;
}
int DerivedGetK(Derived* this) {
	struct ClassDerived* ret = this;
	return ret->mk;
}
int DerivedAdd(Derived* this, int value) {
	struct ClassDerived* ret = this;
	return ret->mk + value;
}
