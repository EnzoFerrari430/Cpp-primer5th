#pragma once
#ifndef BLOB_H_
#define BLOB_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "sp.h"


/*
为了使用类模板，我们必须在模板名后的尖括号中提供额外的信息----用来代替模板参数的模板实参列表

vector就是一个类模板
*/


//为了引用(类或函数)模板的一个特定实例，我们必须首先声明模板自身。
template <typename> class BlobPtr;
template <typename> class Blob;  //运算符==中的参数所需要的
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);  //==运算符的参数需要用到模板参数列表
template <typename T>
bool operator<(const Blob<T>&, const Blob<T>&);  //==运算符的参数需要用到模板参数列表

//实现12.1.1节中StrBlob的模板版本，命名为Blob
//在类模板的定义中，我们将模板参数当做替身，代替使用模板时用户需要提供的类型或值
template <typename T>
class Blob
{
public:
	//类模板和另一个(类或函数)模板间友好关系的最常见形式是建立对应实例及其友元间的友好关系。
	//每个Blob实例将访问权限赋予用相同类型实例化的BlobPtr和相等运算符
	friend class BlobPtr<T>;
	//如果一个类模板含有非模板友元，则友元被授权可以访问所有模板实例。
	friend bool operator==<T>(const Blob&, const Blob&);  //p242  !!!友元不是类的成员
	friend bool operator< <T>(const Blob&, const Blob&);

	/*
	友好关系的形式：
		1.一对一友好关系:实例化对象的类型参数列表要一致
		2.通过和特定的模板友好关系:一个类可以将另一个类模板的每个实例都声明为自己的友元,就像class C和class Pal的关系一样
		3.令模板自己的类型参数成为友元:可以将访问权限授予用来实例化该类模板的类型，就像class Bar和friend Type一样
	*/

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	//using iterator = BlobPtr<T>;
	//构造函数
	Blob();
	Blob(std::initializer_list<T> il);
	
	//practice16.24
	template <typename IT>
	Blob(IT ib, IT ie);
	
	
	//Blob中元素的数目
	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }
	//添加和删除元素
	void push_back(const T& t) { data->push_back(t); }
	//移动版本
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	//元素访问
	T& back();
	T& operator[](size_type i);

	//迭代器
	BlobPtr<T> begin()
	{
		return BlobPtr<T>(*this);
	}

	BlobPtr<T> end()
	{
		return BlobPtr<T>(*this, size());
	}

private:
	SP<std::vector<T>> data;
	//若data[i]无效则抛出i
	void check(size_type i, const std::string &msg)const;
};
//Blob模板有一个名为T的模板参数类型，用来表示Blob保存的元素的类型
//当用户实例化Blob时，T就会被替换为特定的模板实参类型

//如果一个成员定义在类模板的内部，则该成员函数被隐式声明为内联函数
//类模板的每个实例都有其自己的版本的成员函数。
//因此要求定义在类模板外部的成员函数，必须以关键字template开始，后接类模板参数列表

//定义check成员
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg)const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

//下标运算符和back函数用模板参数指出返回类型，其他不变
template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	//如果i太大会抛出异常，阻止访问一个不存在的元素
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//和其他定义在类模板外的成员一样，类模板的构造函数定义也要以模板参数开始
template <typename T>
Blob<T>::Blob() :data(make_SP<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(make_SP<std::vector<T>>(il)) {}


//practice 16.12
template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.data == *rhs.data;  //Blob类应该比较值
}

template <typename T>
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.data < *rhs.data;  //比较值
}

//practice16.24
template <typename T>
template <typename IT>
Blob<T>::Blob(IT ib, IT ie):data(std::make_shared<vector<T>>(ib, ie))
{
	
}

#endif // !BLOB_H_