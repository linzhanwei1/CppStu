#include <iostream>

using namespace std;

class Demo {
private:
	int mi;
	int mj;
public:
	Demo(int i, int j) {
		mi = i;
		mj = j;
	}
	int getI() { return mi; }
	int getJ() { return mj; }
	int add(int value) {
		return mi + mj + value;
	}
};

int main(int argc, char* argv[]) {
	Demo d(1, 2);

	cout << "sizeof(d) = " << sizeof(d) << endl;
	cout << "d.getI() = " << d.getI() << endl;
	cout << "d.getJ() = " << d.getJ() << endl;
	cout << "d.add(3) = " << d.add(3) << endl;

	return 0;
}