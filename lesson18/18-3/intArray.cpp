#include "intArray.h"

IntArray::IntArray(int len) {
	m_pointer = new int[len];
	m_length = len;
	// 初始化
	for (int i = 0; i < len; ++i) {
		m_pointer[i] = 0;
	}

}
int IntArray::length() {
	return m_length;
}
bool IntArray::get(int index, int& value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		value = m_pointer[index];
	}
	return true;
}
bool IntArray::set(int index, int value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		m_pointer[index] = value;
	}
	return true;
}

void IntArray::free() {
	delete[] m_pointer;
	m_pointer = nullptr;
	m_length = 0;
}