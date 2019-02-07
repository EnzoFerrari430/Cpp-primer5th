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
//��������ڼ�ģ��������ʹ��

//������ʹ��һ����ģ������ʱ�����ṩʵ�Σ�������һ������һ������
//����ģ���Լ����������У����ǿ���ֱ��ʹ��ģ���������ṩʵ�Ρ�



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
		return (*p)[curr];  //*pΪ�������vector
	}

	//�����͵ݼ�
	//�������������ﷵ�ص���BlobPtr&������BlobPtr<T>&
	//�����Ǵ���һ����ģ�����������ʱ������������ģ����������ʱ�ͺ��������Ѿ��ṩ����ģ�����ƥ���ʵ��һ����
	BlobPtr& operator++();//ǰ�õ���
	BlobPtr& operator--();


	BlobPtr operator++(int);  //���õ�������������
	//BlobPtr operator--(int);

private:
	//�����ɹ���check����һ��ָ��vector��shared_ptr
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	//����һ��weak_ptr����ʾ�ײ�vector���ܱ�����
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;  //�����е�ǰ��λ��
};


//����ģ����ʹ����ģ����
//������ģ���ⶨ�����Աʱ�����ǲ���������������У�ֱ�����������ű�ʾ�������������

//���õ���
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	//���������飻����ǰ�õ���ʱ����м��
	BlobPtr ret = *this;  //���浱ǰֵ
	//��Ϊ�Ѿ��������������������������Բ��ṩʵ�Ρ�
	//���������ٶ�����ʹ�õ��������Աʵ�������õ�����һ�¡�
	//�ȼ���  BlobPtr<T> ret = *this;


	++*this;  //�ƽ�һ��Ԫ�أ�ǰ�õ�����������Ƿ�Ϸ�
	return ret;  //���ر����״̬
}
//���ڷ�������λ�����������֮�⣬���Ǳ���ָ������������һ��ʵ������BlobPtr����������������ʵ�������õ�����һ�¡�
//�ں������ڣ������Ѿ��������������������ڶ���retʱ�������ظ�ģ��ʵ�Ρ�


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
	//��check
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
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;  //���ж�ָ�����ͬһ������
}



#endif // !BLOBPTR_H_