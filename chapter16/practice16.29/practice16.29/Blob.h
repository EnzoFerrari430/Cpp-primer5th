#pragma once
#ifndef BLOB_H_
#define BLOB_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "sp.h"


/*
Ϊ��ʹ����ģ�壬���Ǳ�����ģ������ļ��������ṩ�������Ϣ----��������ģ�������ģ��ʵ���б�

vector����һ����ģ��
*/


//Ϊ������(�����)ģ���һ���ض�ʵ�������Ǳ�����������ģ������
template <typename> class BlobPtr;
template <typename> class Blob;  //�����==�еĲ�������Ҫ��
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);  //==������Ĳ�����Ҫ�õ�ģ������б�
template <typename T>
bool operator<(const Blob<T>&, const Blob<T>&);  //==������Ĳ�����Ҫ�õ�ģ������б�

//ʵ��12.1.1����StrBlob��ģ��汾������ΪBlob
//����ģ��Ķ����У����ǽ�ģ�����������������ʹ��ģ��ʱ�û���Ҫ�ṩ�����ͻ�ֵ
template <typename T>
class Blob
{
public:
	//��ģ�����һ��(�����)ģ����Ѻù�ϵ�������ʽ�ǽ�����Ӧʵ��������Ԫ����Ѻù�ϵ��
	//ÿ��Blobʵ��������Ȩ�޸�������ͬ����ʵ������BlobPtr����������
	friend class BlobPtr<T>;
	//���һ����ģ�庬�з�ģ����Ԫ������Ԫ����Ȩ���Է�������ģ��ʵ����
	friend bool operator==<T>(const Blob&, const Blob&);  //p242  !!!��Ԫ������ĳ�Ա
	friend bool operator< <T>(const Blob&, const Blob&);

	/*
	�Ѻù�ϵ����ʽ��
		1.һ��һ�Ѻù�ϵ:ʵ������������Ͳ����б�Ҫһ��
		2.ͨ�����ض���ģ���Ѻù�ϵ:һ������Խ���һ����ģ���ÿ��ʵ��������Ϊ�Լ�����Ԫ,����class C��class Pal�Ĺ�ϵһ��
		3.��ģ���Լ������Ͳ�����Ϊ��Ԫ:���Խ�����Ȩ����������ʵ��������ģ������ͣ�����class Bar��friend Typeһ��
	*/

public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	//using iterator = BlobPtr<T>;
	//���캯��
	Blob();
	Blob(std::initializer_list<T> il);
	
	//practice16.24
	template <typename IT>
	Blob(IT ib, IT ie);
	
	
	//Blob��Ԫ�ص���Ŀ
	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }
	//��Ӻ�ɾ��Ԫ��
	void push_back(const T& t) { data->push_back(t); }
	//�ƶ��汾
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	//Ԫ�ط���
	T& back();
	T& operator[](size_type i);

	//������
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
	//��data[i]��Ч���׳�i
	void check(size_type i, const std::string &msg)const;
};
//Blobģ����һ����ΪT��ģ��������ͣ�������ʾBlob�����Ԫ�ص�����
//���û�ʵ����Blobʱ��T�ͻᱻ�滻Ϊ�ض���ģ��ʵ������

//���һ����Ա��������ģ����ڲ�����ó�Ա��������ʽ����Ϊ��������
//��ģ���ÿ��ʵ���������Լ��İ汾�ĳ�Ա������
//���Ҫ��������ģ���ⲿ�ĳ�Ա�����������Թؼ���template��ʼ�������ģ������б�

//����check��Ա
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg)const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

//�±��������back������ģ�����ָ���������ͣ���������
template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
	//���i̫����׳��쳣����ֹ����һ�������ڵ�Ԫ��
	check(i, "subscript out of range");
	return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

//��������������ģ����ĳ�Աһ������ģ��Ĺ��캯������ҲҪ��ģ�������ʼ
template <typename T>
Blob<T>::Blob() :data(make_SP<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(make_SP<std::vector<T>>(il)) {}


//practice 16.12
template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.data == *rhs.data;  //Blob��Ӧ�ñȽ�ֵ
}

template <typename T>
bool operator<(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return *lhs.data < *rhs.data;  //�Ƚ�ֵ
}

//practice16.24
template <typename T>
template <typename IT>
Blob<T>::Blob(IT ib, IT ie):data(std::make_shared<vector<T>>(ib, ie))
{
	
}

#endif // !BLOB_H_