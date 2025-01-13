#include <iostream>

using namespace std;

// 方法1
#define SWAP(t, a, b) \
do                    \
{					  \
	t c = a;		  \
	a = b;			  \
	b = c;			  \
}while(0)		

// 方法2 需要一直添加重载的函数
void Swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void Swap(double& a, double& b) {
	int c = a;
	a = b;
	b = c;
}
void Swap(string& a, string& b) {
	string c = a;
	a = b;
	b = c;
}

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 1;

	//SWAP(int, a, b);
	Swap(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	double m = 2;
	double n = 3;
	//SWAP(double, m, n);
	Swap(m, n);
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;

	string d = "Delphi";
	string t = "Tang";
	Swap(d, t);
	cout << "d = " << d << endl;
	cout << "t = " << t << endl;


	return 0;
}