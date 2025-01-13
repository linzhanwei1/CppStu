#include "demo.h"
#include "malloc.h"

static int DemoAddVirtual(Demo* this, int value);
static int DemoSubVirtual(Demo* this, int value);

struct VTable {					// 2.定义虚函数表数据结构
	int (*pAdd)(Demo*, int);	// 3.虚函数表里面存什么东西
	int (*pSub)(Demo*, int);
};

struct ClassDemo
{
	struct VTable* vptr;		//	1.定义虚函数表指针 =>指针的类型
	int mi;
	int mj;
};

struct ClassDerived {
	struct ClassDemo d;
	int mk;
};

static struct VTable gDemoVtbl = {	// 父类虚函数表实例
	DemoAddVirtual,
	DemoSubVirtual
};

Demo* DemoCreate(int i, int j) {
	struct ClassDemo* ret = malloc(sizeof(struct ClassDemo));
	if (ret) {
		ret->vptr = &gDemoVtbl;	// 4.关联对象和虚函数表
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

// 6.定义虚函数表中指针所指向的具体函数
static int DemoAddVirtual(Demo* this, int value) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->mi + ret->mj + value;
}

// 5.分析具体的虚函数
int DemoAdd(Demo* this, int value) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->vptr->pAdd(this, value);
}

static int DemoSubVirtual(Demo* this, int value) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->mi + ret->mj - value;
}

int DemoSub(Demo* this, int value) {
	struct ClassDemo* ret = (struct ClassDemo*)this;
	return ret->vptr->pSub(this, value);
}
void DemoFree(Demo* this) {
	free(this);
}

static int DerivedAddVirtual(Derived* this, int value);
static int DerivedSubVirtual(Derived* this, int value);
static struct VTable gDerivedVtbl = {	// 子类虚函数表实例
	DerivedAddVirtual,
	DerivedSubVirtual
};
Derived* DerivedCreate(int i, int j, int k) {
	struct ClassDerived* ret = malloc(sizeof(struct ClassDerived));
	if (ret) {
		ret->d.vptr = &gDerivedVtbl;
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

static int DerivedAddVirtual(Derived* this, int value) {
	struct ClassDerived* ret = this;
	return ret->mk + value;
}
int DerivedAdd(Derived* this, int value) {
	struct ClassDerived* ret = this;
	return ret->d.vptr->pAdd(this, value);
}

static int DerivedSubVirtual(Derived* this, int value) {
	struct ClassDerived* ret = this;
	return ret->mk - value;
}
int DerivedSub(Derived* this, int value) {
	struct ClassDerived* ret = this;
	return ret->d.vptr->pSub(this, value);
}
