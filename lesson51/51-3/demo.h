#ifndef _DEMO_H__
#define _DEMO_H__

typedef void Demo;
typedef void Derived;

Demo* DemoCreate(int i, int j);
int DemoGetI(Demo* this);
int DemoGetJ(Demo* this);
int DemoAdd(Demo* this, int value);
void DemoFree(Demo* this);

Derived* DerivedCreate(int i, int j, int k);
int DerivedGetK(Derived* this);
int DerivedAdd(Derived* this, int value);

#endif /* _DEMO_H__ */