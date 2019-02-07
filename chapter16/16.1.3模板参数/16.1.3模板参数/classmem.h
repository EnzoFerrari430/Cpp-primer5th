#pragma once
#ifndef CLASSMEM_H_
#define CLASSMEM_H_
#include <functional>
/*
����ͨ�������������:: ������static��Ա�����ͳ�Ա
�ڷ�ģ��Ĵ����У�������֪����Ķ��塣�����֪��ͨ����������������ʵ����������ͻ���static��Ա
���磺string::size_type,��������string���壬�Ӷ�֪��size_type��һ������

���ǵ�T��һ��ģ�����Ͳ���ʱ��������������T::mem�����Ĵ���ʱ�����±��ˡ�
��Ϊ��������֪��mem��һ�����ͳ�Ա����һ��static���ݳ�Ա

����:
	T::size_type *p;
	���size_type��T�����ͳ�Ա����p��һ��ָ��
	���size_type��T�ľ�̬��������ñ��ʽ��һ��size_type����Ϊp�ı��������
Ϊ�˽���������⣬���Ǿͱ�����ʾ�ĸ��߱�������������һ������
*/

template <typename T>
typename T::size_type top(const T& c)
{
	if (!c.empty())
	{
		return c.back();
	}
	else
		return typename T::value_type();
}

/*
����������Ϊ���������ṩĬ��ʵ��һ��������Ҳ�����ṩĬ��ģ��ʵ�Ρ�
��C++11�±�׼�У����ǿ���Ϊ��������ģ���ṩĬ��ʵ�Ρ�
��汾ֻ����Ϊ��ģ���ṩĬ��ʵ�Ρ�
*/
//��дcompare
template <typename T,typename F = less<T>>  //F�Ǻ�������
int compare(const T& v1, const T& v2, F f = F())
{
	if (f(v1, v2))
		return -1;
	if (f(v2, v1))
		return 1;
	return 0;
}
#endif