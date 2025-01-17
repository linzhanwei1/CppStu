#include <iostream>

using namespace std;

// catch 没有自动类型转换
void Demo1() {
	try {
		throw 1;
	}
	catch (char c) {
		cout << "catch (char c) " << c << endl;
	}
	catch (short c) {
		cout << "catch (short c) " << c << endl;
	}
	catch (double c) {
		cout << "catch (double c) " << c << endl;
	}
	catch (int c) {
		cout << "catch (int c) " << c << endl;
	}
	catch (...) {
		cout << "兜底" << endl;
	}
}

int main(int argc, char* argv[]) {
	Demo1();

	return 0;
}