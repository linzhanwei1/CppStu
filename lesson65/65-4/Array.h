#pragma once
#include <stdexcept>

template <typename T, int N>
class Array {
private:
	T m_array[N];
public:
	int length();
	bool set(int index, T value);
	bool get(int index, T& value);
	T& operator[](int index);
	T operator[](int index) const;	// const返回值不能是引用
	virtual ~Array();
};

template <typename T, int N>
int Array<T, N>::length() {
	return N;
}

template <typename T, int N>
bool Array<T, N>::set(int index, T value) {
	bool ret = (0 <= index) && (index < N);
	if (ret) {
		m_array[index] = value;
	}
	return ret;
}

template <typename T, int N>
bool Array<T, N>::get(int index, T& value) {
	bool ret = (0 <= index) && (index < N);
	if (ret) {
		value = m_array[index];
	}
	return ret;
}

template <typename T, int N>
T& Array<T, N>::operator[](int index) {
	if ((0 <= index) && (index < N)) {
		return m_array[index];
	}
	else {
		throw std::out_of_range("T& Array<T, N>::operator[](int index)");
	}
}

template <typename T, int N>
T Array<T, N>::operator[](int index) const{
	if ((0 <= index) && (index < N)) {
		return m_array[index];
	}
	else {
		throw std::out_of_range("T Array<T, N>::operator[](int index) const");
	}
}

template <typename T, int N>
Array<T, N>::~Array() {

}