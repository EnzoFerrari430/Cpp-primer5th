#pragma once
#include <iostream>

template <typename T>
class SP
{
public:
	SP():p(nullptr),use(nullptr){}
	explicit SP(T* pt):p(pt),use(new size_t(1)){}  //��ֹ��ʽת��

	//p587����ģ���Լ�����������ʱ������ʹ��һ����ģ������ʱ�����ñ����ṩģ��ʵ��SP<T>& ��дΪSP&
	SP(const SP &sp):p(sp.p),use(ps.use)
	{
		if (use)
			++(*use);
	}

	//p587����ģ���Լ�����������ʱ������ʹ��һ����ģ������ʱ�����ñ����ṩģ��ʵ��SP<T>& ��дΪSP&
	SP& operator=(const SP&);  //������ֵ�����
	~SP();
	T& operator*() { return *p; }  //�����������
	T& operator*()const { return *p; }  //const�汾

	//δ����
	T* operator->()const { return &this->operator*(); }


private:
	T* p;
	size_t *use;
};

template <typename T>
SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
	//��ֹ�Ը�ֵ
	if (this != &rhs)
	{
		if (rhs.use)
		{
			++*rhs.use;
		}
		if (use && --*use == 0)
		{
			//�ͷű�����
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
	UP(const UP&) = delete;  //��ֹ��������
	explicit UP(T* pt):p(pt){}
	//p587����ģ���Լ�����������ʱ������ʹ��һ����ģ������ʱ�����ñ����ṩģ��ʵ��SP<T>& ��дΪSP&
	UP& operator=(const UP&) = delete;  //��ֹ������ֵ�����
	~UP();

	T* release();  //��������Ȩ
	void reset(T* new_p);  //�ͷŶ���
	T& operator*() { return *p; }
	T& operator*()const { return *p; }  //const��
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