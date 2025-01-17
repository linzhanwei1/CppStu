#ifndef __SINGLETON_H__
#define __SINGLETON_H__

template <typename T>
class Singleton {
private:
	static T* c_instance;
public:
	static T* GetInstance();
};


template <typename T>
T* Singleton<T>::c_instance = nullptr;

template <typename T>
T* Singleton<T>::GetInstance() {
	if (c_instance == nullptr) {
		c_instance = new T();
	}
	return c_instance;
}


#endif /* __SINGLETON_H__ */