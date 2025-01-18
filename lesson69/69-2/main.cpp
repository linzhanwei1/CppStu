#include <iostream>

using namespace std;

class Test {
private:
	static const unsigned int COUNT = 4;
	static char c_buffer[];
	static char c_map[];

	int m_value;
public:
	void* operator new(unsigned int size) {
		void* ret = NULL;

		for (int i = 0; i < COUNT; i++) {
			if (!c_map[i]) {
				c_map[i] = 1;
				ret = c_buffer + i * sizeof(Test);
				cout << "succed to allocate memory: " << ret << endl;
				break;
			}
		}
		return ret;
	}

	void operator delete(void* p) {
		if (p != NULL) {
			char* mem = reinterpret_cast<char*>(p);
			int index = (mem - c_buffer) / sizeof(Test);
			int flag = (mem - c_buffer) % sizeof(Test);		// 指针不合法
			if ((flag == 0) && (0 <= index) && (index < COUNT)) {
				c_map[index] = 0;
				cout << "succeed to free memory: " << p << endl;
			}
		}
	}
};

char Test::c_buffer[sizeof(Test) * Test::COUNT] = { 0 };
char Test::c_map[COUNT] = { 0 };
// 在静态存储器创建动态对象  N例模式
int main(int argc, char* argv[]) {
	cout << "===== Test Single Object =====" << endl;
	Test* pt = new Test;
	delete pt;
	cout << "===== Test Object Array =====" << endl;

	Test* pa[5] = { 0 };

	for (int i = 0; i < 5; i++) {
		pa[i] = new Test;
		cout << "pa[" << i << "] = " << pa[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << "delete " << pa[i] << endl;
		delete pa[i];
	}

	return 0;
}