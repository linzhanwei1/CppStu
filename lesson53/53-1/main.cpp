#include <iostream>

using namespace std;

class BaseA {
private:
	int ma;
public:
	BaseA(int a = 0) {
		ma = a;
	}
	int GetA() { return ma; }
};

class BaseB {
private:
	int mb;
public:
	BaseB(int b = 0) {
		mb = b;
	}
	int GetB() { return mb; }
};

class Derived : public BaseA, public BaseB {
private:
	int mc;
public:
	Derived(int a = 0, int b = 0, int c = 0): BaseA(a), BaseB(b) {
		mc = c;
	}
	int GetC() {
		return mc;
	}
	void print() {
		cout << "ma = " << GetA() << ", "
			 << "mb = " << GetB() << ", "
			 << "mc = " << mc << endl;
	}
};

int main(int argc, char* argv[]) {
	cout << "sizeof(Derived) = " << sizeof(Derived) << endl;	// 12
	Derived d(1, 2, 3);
	d.print();

	cout << "d.getA() = " << d.GetA() << endl;
	cout << "d.getB() = " << d.GetB() << endl;
	cout << "d.getV() = " << d.GetC() << endl;

	BaseA* pa = &d;
	BaseB* pb = &d;
	cout << "pa->getA() = " << pa->GetA() << endl;
	cout << "pb->getB() = " << pb->GetB() << endl << endl;

	void* paa = pa;
	void* pbb = pb;
	if (paa == pbb) {
		cout << "Pointer to the same object!" << endl;
	}
	else {
		cout << "Error" << endl;
	}

	cout << "pa = " << pa << endl;
	cout << "pb = " << pb << endl;
	cout << "paa = " << paa << endl;
	cout << "pbb = " << pbb << endl;

	return 0;
}