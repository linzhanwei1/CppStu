#include <iostream>
#include <cstdlib>

using namespace std;

class Test {
private:
	static unsigned int c_count;
	static char* c_buffer;
	static char* c_map;

	int m_value;
public:
	static bool SetMemorySource(char* memory, unsigned int size) {
		bool ret = false;

		c_count = size / sizeof(Test);
		ret = (c_count && (c_map = reinterpret_cast<char*>(calloc(c_count, sizeof(char)))));
		if (ret) {
			c_buffer = memory;
		}
		else {
			free(c_map);
			c_map = nullptr;
			c_buffer = nullptr;
			c_count = 0;
		}

		return ret;
	}
	void* operator new(unsigned int size) {
		void* ret = NULL;

		if (c_count > 0) {
			for (int i = 0; i < c_count; i++) {
				if (!c_map[i]) {
					c_map[i] = 1;
					ret = c_buffer + i * sizeof(Test);
					cout << "succed to allocate memory: " << ret << endl;
					break;
				}
			}
		}
		else {
			ret = malloc(size);
		}
		return ret;
	}

	void operator delete(void* p) {
		if (p != NULL) {
			if (c_count > 0) {
				char* mem = reinterpret_cast<char*>(p);
				int index = (mem - c_buffer) / sizeof(Test);
				int flag = (mem - c_buffer) % sizeof(Test);		// 指针不合法
				if ((flag == 0) && (0 <= index) && (index < c_count)) {
					c_map[index] = 0;
					cout << "succeed to free memory: " << p << endl;
				}
			}
			else {
				free(p);
			}
		}
	}
};

unsigned int Test::c_count = 0;
char* Test::c_buffer = nullptr;
char* Test::c_map = nullptr;
// 在静态存储器创建动态对象  N例模式
int main(int argc, char* argv[]) {
	// 定义一片空间
	char buffer[12] = { 0 };
	Test::SetMemorySource(buffer, sizeof(buffer));

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