#pragma once
#include "Sales_data.h"
using namespace cplusplus_primer;
/*
	ģ�����������붨����ԭʼģ�������������ռ��С�
	ֻҪ�����������ռ����������������������������ռ��ⲿ������
*/

//���Ǳ��뽫ģ��������������std�ĳ�Ա
namespace std
{
	//ʹ��ģ����������Ҫ�������ռ�������
	template <> struct hash<Sales_data>;
}