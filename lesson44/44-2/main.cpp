#include <iostream>
#include <sstream>

using namespace std;

class Object {
protected:
	string mName;
	string mInfo;
public:
	Object() {
		mName = "Object";
		mInfo = "";
	}
	string name() {
		return mName;
	}
	string info() {
		return mInfo;
	}
};

class Point : public Object {
private:
	int mx;
	int my;
public:
	Point(int x, int y) : mx(x),my(y) {
		ostringstream s;
		mName = "Point";
		s << "P(" << mx << ", " << my << ")";
		mInfo = s.str();
	}
	int x() { return mx; }
	int y() { return my; }
};

class Line : public Object {
private:
	Point mP1;
	Point mP2;
public:
	Line(Point p1, Point p2): mP1(p1), mP2(p2){
		ostringstream s;
		mName = "Line";
		s << "Line from " << mP1.info() << ", " << mP2.info() << ")";
		mInfo = s.str();
	}
};

int main(int argc, char* argv[]) {
	Object o;
	Point p1(1, 2);
	Point p2(3, 4);
	Line l(p1, p2);

	cout << o.name() << endl;
	cout << o.info() << endl;

	cout << p1.name() << endl;
	cout << p1.info() << endl;

	cout << l.name() << endl;
	cout << l.info() << endl;

	return 0;
}