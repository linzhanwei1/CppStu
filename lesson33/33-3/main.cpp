#include <iostream>

using namespace std;

string right_func(const string& s, unsigned int n) {
	string ret = "";
	unsigned int pos = 0;
	n = n % s.length();
	pos = s.length() - n;
	ret = s.substr(pos);
	ret += s.substr(0, pos);
	return ret;
}

int main(int argc, char* argv[]) {
	string src = "abcdefg";
	cout << right_func(src, 8) << endl;

	return 0;
}