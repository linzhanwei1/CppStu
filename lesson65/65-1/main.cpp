#include <iostream>

using namespace std;

void Demo() {
	try {
		try {
			throw 'c';
		}
		catch (int i) {
			cout << "Inner: catch(int i)" << endl;
			throw i;
		}
		catch (...) {
			cout << "Inner: catch(...)" << endl;
			throw;
		}
	}
	catch (...) {
		cout << "Outer: catch(...)" << endl;
	}
}

/*
	假设：当前的函数是第三放库中的函数，因此，我们无法修改源码
	函数名： void func(int i)
	抛出异常的类型 int 
	-1 : 参数异常
	-2 : 运行异常
	-3 ：超时异常
*/
void func(int i) {
	if (i < 0) {
		throw -1;
	}
	if (i > 100) {
		throw -2;
	}
	if (i == 11) {
		throw -3;
	}
	cout << "Run func..." << endl;
}

// 重解释异常,将第三方库进行封装
void MyFunc(int i) {
	try {
		func(i);
	}
	catch (int i) {
		switch (i) {
		case -1:
			throw "Invalid Parameter";
			break;
		case -2:
			throw "Runtime Exception";
			break;
		case -3:
			throw "Timeout Exception";
			break;
		}
	}
}

int main(int arg, char* argv[]) {
	Demo();

	try {
		MyFunc(11);
	}
	catch (const char* cs) {
		cout << "Exception Info: " << cs << endl;
	}

	return 0;
}