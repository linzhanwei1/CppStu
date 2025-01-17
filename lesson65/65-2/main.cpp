#include <iostream>

using namespace std;

class Base {

};

class Exception : public Base {
private:
	int m_id;
	string m_desc;
public:
	Exception(int id, string desc) {
		m_id = id;
		m_desc = desc;
	}
	int id() const {
		return m_id;
	}
	string description() const {
		return m_desc;
	}
};

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
		throw - 1;
	}
	if (i > 100) {
		throw - 2;
	}
	if (i == 11) {
		throw - 3;
	}
	cout << "Run func..." << endl;
}

// 重解释异常,将第三方库进行封装
void MyFunc(int i) {
	try {
		func(i);
	}
	//catch(const Base & e) {	// 赋值兼容性原则，截获了异常，应该将父类catch放到下面
	//	cout << "catch(const Base& e)" << endl;
	//}
	catch (int i) {
		switch (i) {
		case -1:
			throw Exception(-1, "Invalid Parameter");
			break;
		case -2:
			throw Exception(-2, "Runtime Exception");
			break;
		case -3:
			throw Exception(-3, "Timeout Exception");
			break;
		}
	}
}

int main(int arg, char* argv[]) {
	try {
		MyFunc(11);
	}
	catch (const Exception& e) {
		cout << "Exception Info: " << endl;
		cout << "	ID: " << e.id() << endl;
		cout << "	desc: " << e.description() << endl;
	}

	return 0;
}