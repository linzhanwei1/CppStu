#ifndef __HEAP_ARRAY_H__
#define __HEAP_ARRAY_H__

template <typename T>
class HeapArray {
private:
	int m_length;
	T* m_pointer;
	HeapArray(int len);
	bool construct();
public:
	static HeapArray* NewInstance(int len);
	int length();
	bool get(int index, T& value);
	bool set(int index, T value);
	T& operator [] (int i);
	T operator [] (int i) const;
	HeapArray& self();
	~HeapArray();	// 构造函数已经被私有化了，此类不希望被继承，所以不用virtual析构
};

template <typename T>
HeapArray<T>::HeapArray(int len) {
	m_length = len;
}

template <typename T>
bool HeapArray<T>::construct() {
	m_pointer = new T[m_length];
	return m_pointer != nullptr;
}

template <typename T>
HeapArray<T>* HeapArray<T>::NewInstance(int len) {
	HeapArray* ret = new HeapArray(len);

	if (!(ret && ret->construct())) {
		delete ret;
		ret = nullptr;
	}
	return ret;
}

template <typename T>
int HeapArray<T>::length() {
	return m_length;
}

template <typename T>
bool HeapArray<T>::get(int index, T& value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		value = m_pointer[index];
	}
	return true;
}

template <typename T>
bool HeapArray<T>::set(int index, T value) {
	bool ret = (0 <= index) && (index < length());

	if (ret) {
		m_pointer[index] = value;
	}
	return true;
}

template <typename T>
T& HeapArray<T>::operator [] (int i) {
	return m_pointer[i];
}

template <typename T>
T HeapArray<T>::operator [] (int i) const {
	return m_pointer[i];
}

template <typename T>
HeapArray<T>& HeapArray<T>::self() {
	return *this;
}

template <typename T>
HeapArray<T>::~HeapArray() {
	delete[] m_pointer;
	m_pointer = nullptr;
	m_length = 0;
}


#endif /* __HEAP_ARRAY_H__ */
