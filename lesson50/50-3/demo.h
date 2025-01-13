#ifndef _DEMO_H__
#define _DEMO_H__

typedef void Demo;

Demo* DemoCreate(int i, int j);
int DemoGetI(Demo* this);
int DemoGetJ(Demo* this);
int DemoAdd(Demo* this, int value);
void DemoFree(Demo* this);

#endif /* _DEMO_H__ */