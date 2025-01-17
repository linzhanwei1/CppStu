#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Operator {
public:
	T add(T a, T b) {
		return a + b;
	}
	T minus(T a, T b) {
		return a - b;
	}
	T multiply(T a, T b) {
		return a * b;
	}
	T divide(T a, T b) {
		return a / b;
	}
};


int main(int argc, char* argv[]) {
	Operator<int> op1;
	cout << op1.add(1, 2) << endl;
	
	Operator<string> op2;
	cout << op2.add("D.T.", "Software") << endl;

	return 0;
}