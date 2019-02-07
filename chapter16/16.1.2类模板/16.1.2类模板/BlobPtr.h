#pragma once
#ifndef BLOBPTR_H_
#define BLOBPTR_H_


#include "Blob.h"

template <typename T> class BlobPtr;
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T>
bool operator<(const BlobPtr<T>&, const BlobPtr<T>&);
//在类代码内简化模板类名的使用

//当我们使用一个类模板类型时必须提供实参，但是这一规则有一个例外
//在类模板自己的作用域中，我们可以直接使用模板名而不提供实参。



template <typename T>
class BlobPtr
{
	//friend bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
	friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
	friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);
	friend bool operator< <T>(const BlobPtr&, const BlobPtr&);
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T> &a,size_t sz = 0):wptr(a.data),curr(sz){}
	T& operator*()const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];  //*p为本对象的vector
	}

	//递增和递减
	//！！！！！这里返回的是BlobPtr&而不是BlobPtr<T>&
	//当我们处于一个类模板的作用域中时，编译器处理模板自身引用时就好像我们已经提供了与模板参数匹配的实参一样。
	BlobPtr& operator++();//前置递增
	BlobPtr& operator--();


	BlobPtr operator++(int);  //后置递增不返回引用
	//BlobPtr operator--(int);

private:
	//若检查成功，check返回一个指向vector的shared_ptr
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	//保存一个weak_ptr，表示底层vector可能被销毁
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;  //数组中当前的位置
};


//在类模板外使用类模板名
//当在类模板外定义其成员时，我们并不在类的作用域中，直到遇到类名才表示进入类的作用域

//后置递增
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//这里无需检查；调用前置递增时会进行检查
	BlobPtr ret = *this;  //保存当前值
	//因为已经进入了类的作用域，所以这里可以不提供实参。
	//编译器将假定我们使用的类型与成员实例化所用的类型一致。
	//等价于  BlobPtr<T> ret = *this;


	++*this;  //推进一个元素；前置递增会检查递增是否合法
	return ret;  //返回保存的状态
}
//由于返回类型位于类的作用域之外，我们必须指出返回类型是一个实例化的BlobPtr，它所用类型与类实例化所用的类型一致。
//在函数体内，我们已经进入了类的作用域，因此在定义ret时，无需重复模板实参。


//practice 16.12
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t pos, const std::string& msg) const
{
	std::shared_ptr<std::vector<T>> ret = wptr.lock();
	if (!ret)
	{
		throw std::runtime_error("unbound BlobPtr");
	}
	else if (ret->size() < pos)
	{
		throw std::out_of_range(msg);
	}
	return ret;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	//先check
	check(curr + 1, "BlobPtr increament pass the end");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(curr - 1, "BlobPtr decreament pass the beginning");
	--curr;
	return *this;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	if (lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr)
	{
		return true;
	}
	else
		return false;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;  //先判断指向的是同一个对象
}



#endif // !BLOBPTR_H_