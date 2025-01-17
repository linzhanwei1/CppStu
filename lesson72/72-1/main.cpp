#include <iostream>

using namespace std;

void func() throw(int) {
	cout << "func()";
	cout << endl;

	throw 'c';
}


int main(int argc, char* argv[]) {
	try {
		func();
	}catch(int) {
		cout << "catch(int)";
		cout << endl;
	}
	catch (char) {
		cout << "catch(char)";
		cout << endl;
	}

	return 0;
}