#pragma once
#include <iostream>
#include <string>
/*
��ģ���������static��Ա
*/


template <typename T>
class Foo
{
public:
	static std::size_t count() { return ctr; }
private:
	static std::size_t ctr;
};
//�������������X������һ��Foo<X>::ctr��һ��Foo<X>::count
//����Foo<X>���͵Ķ�������ͬ��ctr�����count����

//��ģ���ÿ��static���ݳ�Ա�������ҽ���һ������
template <typename T>
size_t Foo<T>::ctr = 0;  //���岢��ʼ��0

//ʵ����static��ԱFoo<std::string>::ctr��һ��Foo<std::string>::count
Foo<std::string> fs;
//����������������ͬ��Foo<int>::ctr��һ��Foo<int>::count
Foo<int> fi1, fi2, fi3;

//����ģ����ľ�̬��Ա1.ͨ�������Ͷ���������һ����ģ���static��Ա	2.ʹ�������������ֱ�ӷ��ʳ�Ա
Foo<int> fi;
auto ct1 = Foo<int>::count();  //ͨ�����������������
auto ct2 = fi.count();		//ͨ�������Ͷ������
//ct = Foo::count();  û��ָ����ģ��Foo��ģ������б�
