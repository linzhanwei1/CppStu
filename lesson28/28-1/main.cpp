#include <stdio.h>

class Point {
private:
	double x;
	double y;
public:
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	friend void func(Point& p);	// 将全局域的函数func声明为class Point的友元
};

void func(Point& p) {
	printf("p.x:%f p.y:%f\n", p.x, p.y);
}

int main(int argc, char* argv[]) {
	Point p1(1,1);
	Point p2(2,2);

	func(p1);
	func(p2);

	return 0;
}