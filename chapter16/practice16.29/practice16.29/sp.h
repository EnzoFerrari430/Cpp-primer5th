#pragma once
#include <iostream>

template <typename T>
class SP
{
public:
	SP():p(nullptr),use(nullptr){}
	explicit SP(T* pt):p(pt),use(new size_t(1)){}  //阻止隐式转换

	//p587在类模板自己的作用域中时，我们使用一个类模板类型时，不用必须提供模板实参SP<T>& 简写为SP&
	SP(const SP &sp):p(sp.p),use(ps.use)
	{
		if (use)
			++(*use);
	}

	//p587在类模板自己的作用域中时，我们使用一个类模板类型时，不用必须提供模板实参SP<T>& 简写为SP&
	SP& operator=(const SP&);  //拷贝赋值运算符
	~SP();
	T& operator*() { return *p; }  //解引用运算符
	T& operator*()const { return *p; }  //const版本

	//未掌握
	T* operator->()const { return &this->operator*(); }


private:
	T* p;
	size_t *use;
};

template <typename T>
SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
	//防止自赋值
	if (this != &rhs)
	{
		if (rhs.use)
		{
			++*rhs.use;
		}
		if (use && --*use == 0)
		{
			//释放本对象
			delete p;
			delete use;
		}
		p = rhs.p;
		use = rhs.use;
	}
	return *this;
}

template <typename T>
SP<T>::~SP()
{
	if (use && --*use == 0)
	{
		delete p;
		delete use;
	}
}

template <typename T,class... Args>
SP<T> make_SP(Args&&... args)
{
	return SP<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
class UP
{
public:
	UP():p(nullptr){}
	UP(const UP&) = delete;  //禁止拷贝构造
	explicit UP(T* pt):p(pt){}
	//p587在类模板自己的作用域中时，我们使用一个类模板类型时，不用必须提供模板实参SP<T>& 简写为SP&
	UP& operator=(const UP&) = delete;  //禁止拷贝赋值运算符
	~UP();

	T* release();  //交出控制权
	void reset(T* new_p);  //释放对象
	T& operator*() { return *p; }
	T& operator*()const { return *p; }  //const版
private:
	T *p;
};

template <typename T>
UP<T>::~UP()
{
	if(p)
		delete p;
}

template <typename T>
T* UP<T>::release()
{
	T* tmp = p;
	p = nullptr;
	return tmp;
}

template <typename T>
void UP<T>::reset(T* new_P)
{
	if(p)
		delete p;
	p = new_p;
}