#pragma once
#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <utility>


template <typename T>
class Vec
{
public:
	Vec():elements(nullptr), first_free(nullptr), cap(nullptr) {};  //默认构造函数

	Vec(const Vec&);  //拷贝构造函数，参数一定是引用。如果不是引用类型，值传递的话。实参传进形参就要进行一次拷贝构造，但是我们这里都还没有完成拷贝构造。这就形成了矛盾。
	Vec& operator=(const Vec&);  //这里参数使用引用  1.防止类没有定义拷贝构造函数之后，使用默认的拷贝构造函数造成的未知影响。2.实参传进形参会进行一次拷贝，需要花费CPU的开销

	~Vec();
	
	T* begin()const { return elements; }
	T* end()const { return first_free; }

	// !!!C++中const 引用的是对象时只能访问该对象的const 函数，因为其他函数有可能会修改该对象的成员，编译器为了避免该类事情发生，会认为调用非const函数是错误的。
	void push_back(const T&);
	size_t size() const { return first_free - elements; }  //注意！！:2个同类型，指向同一个数组的指针相减，结果并不是两个指针数值上的差，而是把这个差除以指针指向类型的大小的结果。
	size_t capacity() const { return cap - elements; }  //返回容量

	bool empty() const { return (first_free - elements) ? false : true; }  //是否为空，是空返回true，否则返回false

private:

	std::allocator<T> alloc;  //分配元素

										//4个工具函数
	void free();  //销毁元素，并释放内存
	void reallocate();  //获得更多的内存并拷贝已有的元素
						//确保StrVec至少有容纳一个新元素的空间.如果没有空间添加新元素，该函数调用reallocate来分配更多的空间
	void chk_n_alloc() {
		if (size() == capacity())
		{
			reallocate();
		}
	}

	//分配内存，并拷贝一个给定范围中的元素,参数1,2表示一个范围中的元素
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);

	T* elements;	//起始位置
	T* first_free;  //尾后位置
	T* cap;			//容量位置
};

template <typename T>
void Vec<T>::reallocate()
{
	//分配当前2倍大小的内存空间
	size_t newcapacity = size() ? 2 * size() : 1;
	//分配新的内存
	T* newdata = alloc.allocate(newcapacity);

	T* dest = newdata;  //指向新内存中的第一个内存地址
	T* elem = elements;  //指向旧内存中的第一个内存地址

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e)
{
	auto data = alloc.allocate(e - b);
	//可以返回花括号列表来对临时量进行初始化。参数一是内存空间的首地址，
	//参数二是一个函数，用b，e表示的一个范围来初始化data为首的内存地址，返回尾后迭代器。这里就是T指针
	return{ data,uninitialized_copy(b,e,data) };
}

//深拷贝
template <typename T>
Vec<T>::Vec<T>(const Vec<T>& item)
{
	auto ret = alloc_n_copy(item.begin(), item.end());
	elements = ret.first;
	first_free = cap = ret.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& item)
{
	if (this != item)
	{
		//free();  //释放自己的内存空间，因为已经证明了这不是自赋值。但是还是不能放在这里，要考虑内存重叠的情况
		auto ret = alloc_n_copy(item.begin(), item.end());
		free();  //释放自己的内存空间，因为已经证明了这不是自赋值
		elements = ret.first;
		first_free = cap = ret.second;
	}
	return *this;
}

template <typename T>
Vec<T>::~Vec<T>()
{
	free();
}

template <typename T>
void Vec<T>::free()
{
	//不能传递给deallocate一个空指针，如果elements为空，函数什么也不做
	if (elements)
	{
		//逆序销毁元素
		for (auto p = first_free; p != elements;)
		{
			//destroy对p指向的元素进行析构函数
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);  //预留的部分不用考虑
	}
}

template <typename T>
void Vec<T>::push_back(const T& v)
{
	chk_n_alloc();

	//在first_free指向的原始内存中构造s的副本
	alloc.construct(first_free++,v);
}

#endif