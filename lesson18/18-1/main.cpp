
class Test {
public:
	Test(){}
	Test(int v) {}
};

int main(int argc, char* argv[]) {
	Test t;							// 调用 Test()
	Test* t0 = new Test();			// 调用 Test()
	Test t1(1);						// 调用 Test(int v)
	Test t2 = 1;					// 调用 Test(int v)

	return 0;
}