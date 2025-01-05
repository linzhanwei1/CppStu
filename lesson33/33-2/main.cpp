#include <iostream>
#include <sstream>

using namespace std;

bool toNumber(const string& s, int& n) {
	istringstream iss(s);
	return bool(iss >> n);
}


int main(int argc, char* argv[]) {
	int n = 0;
	cout << toNumber("234", n) << endl;
	cout << "n: " << n << endl;

	return 0;

	istringstream instr("123.45");
	double num = 0;
	instr >> num;

	cout << "num: " << num << endl;

	ostringstream outStr;
	outStr << 54.321;
	cout << "str: " << outStr.str() << endl;;

}