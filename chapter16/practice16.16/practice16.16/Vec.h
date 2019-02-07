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
	Vec():elements(nullptr), first_free(nullptr), cap(nullptr) {};  //Ĭ�Ϲ��캯��

	Vec(const Vec&);  //�������캯��������һ�������á���������������ͣ�ֵ���ݵĻ���ʵ�δ����βξ�Ҫ����һ�ο������죬�����������ﶼ��û����ɿ������졣����γ���ì�ܡ�
	Vec& operator=(const Vec&);  //�������ʹ������  1.��ֹ��û�ж��忽�����캯��֮��ʹ��Ĭ�ϵĿ������캯����ɵ�δ֪Ӱ�졣2.ʵ�δ����βλ����һ�ο�������Ҫ����CPU�Ŀ���

	~Vec();
	
	T* begin()const { return elements; }
	T* end()const { return first_free; }

	// !!!C++��const ���õ��Ƕ���ʱֻ�ܷ��ʸö����const ��������Ϊ���������п��ܻ��޸ĸö���ĳ�Ա��������Ϊ�˱���������鷢��������Ϊ���÷�const�����Ǵ���ġ�
	void push_back(const T&);
	size_t size() const { return first_free - elements; }  //ע�⣡��:2��ͬ���ͣ�ָ��ͬһ�������ָ��������������������ָ����ֵ�ϵĲ���ǰ���������ָ��ָ�����͵Ĵ�С�Ľ����
	size_t capacity() const { return cap - elements; }  //��������

	bool empty() const { return (first_free - elements) ? false : true; }  //�Ƿ�Ϊ�գ��ǿշ���true�����򷵻�false

private:

	std::allocator<T> alloc;  //����Ԫ��

										//4�����ߺ���
	void free();  //����Ԫ�أ����ͷ��ڴ�
	void reallocate();  //��ø�����ڴ沢�������е�Ԫ��
						//ȷ��StrVec����������һ����Ԫ�صĿռ�.���û�пռ������Ԫ�أ��ú�������reallocate���������Ŀռ�
	void chk_n_alloc() {
		if (size() == capacity())
		{
			reallocate();
		}
	}

	//�����ڴ棬������һ��������Χ�е�Ԫ��,����1,2��ʾһ����Χ�е�Ԫ��
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);

	T* elements;	//��ʼλ��
	T* first_free;  //β��λ��
	T* cap;			//����λ��
};

template <typename T>
void Vec<T>::reallocate()
{
	//���䵱ǰ2����С���ڴ�ռ�
	size_t newcapacity = size() ? 2 * size() : 1;
	//�����µ��ڴ�
	T* newdata = alloc.allocate(newcapacity);

	T* dest = newdata;  //ָ�����ڴ��еĵ�һ���ڴ��ַ
	T* elem = elements;  //ָ����ڴ��еĵ�һ���ڴ��ַ

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
	//���Է��ػ������б�������ʱ�����г�ʼ��������һ���ڴ�ռ���׵�ַ��
	//��������һ����������b��e��ʾ��һ����Χ����ʼ��dataΪ�׵��ڴ��ַ������β����������������Tָ��
	return{ data,uninitialized_copy(b,e,data) };
}

//���
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
		//free();  //�ͷ��Լ����ڴ�ռ䣬��Ϊ�Ѿ�֤�����ⲻ���Ը�ֵ�����ǻ��ǲ��ܷ������Ҫ�����ڴ��ص������
		auto ret = alloc_n_copy(item.begin(), item.end());
		free();  //�ͷ��Լ����ڴ�ռ䣬��Ϊ�Ѿ�֤�����ⲻ���Ը�ֵ
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
	//���ܴ��ݸ�deallocateһ����ָ�룬���elementsΪ�գ�����ʲôҲ����
	if (elements)
	{
		//��������Ԫ��
		for (auto p = first_free; p != elements;)
		{
			//destroy��pָ���Ԫ�ؽ�����������
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);  //Ԥ���Ĳ��ֲ��ÿ���
	}
}

template <typename T>
void Vec<T>::push_back(const T& v)
{
	chk_n_alloc();

	//��first_freeָ���ԭʼ�ڴ��й���s�ĸ���
	alloc.construct(first_free++,v);
}

#endif