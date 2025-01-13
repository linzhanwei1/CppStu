#include <iostream>

using namespace std;

class Test {
private:
	Test(const Test&);	// 不能拷贝构造了
public:
	Test(){}
};

template <typename T>
void Swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

typedef void(FuncI)(int&, int&);
typedef void(FuncD)(double&, double&);
typedef void(FuncT)(Test&, Test&);

int main(int argc, char* argv[]) {
	FuncI* pi = Swap;	// 编译器自动推导 T 为 int
	FuncD* pd = Swap;	// 编译器自动推导 T 为 double
	//FuncT* pt = Swap;	// 编译器自动推导 T 为 Test 第二次编译是，发现无法拷贝构造初始化化形参

	cout << "pi = " << pi << endl;
	cout << "pd = " << pd << endl;
	//cout << "pt = " << pt << endl;

	return 0;
}