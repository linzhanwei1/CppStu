#include <iostream>

using namespace std;

class Shape {
public:
	virtual double area() = 0;	// 纯虚函数
};

class Rect : public Shape {
private:
	int ma;
	int mb;
public:
	Rect(int a=0, int b=0) {
		ma = a;
		mb = b;
	}
	double area() override {
		return ma * mb;
	}
};

class Circle : public Shape {
private:
	int mr;
public:
	Circle(int r = 0) {
		mr = r;
	}
	double area() override {
		return mr * mr * 3.14;
	}
};

double  area(Shape& p) {
	return p.area();
}

double  area(Shape* p) {
	return p->area();
}

int main(int argc, char* argv[]) {
	Rect r(1,2);
	Circle c(10);

	cout << "Rect's area() = " << area(r) << endl;
	cout << "Circle area() = " << area(c) << endl;

	cout << "Rect's area() = " << area(&r) << endl;
	cout << "Circle area() = " << area(&c) << endl;

	return 0;
}