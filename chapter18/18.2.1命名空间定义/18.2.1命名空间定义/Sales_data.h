#pragma once
#include <iostream>
/*
����⽫���ַ�����ȫ�������ռ��н����������ռ���Ⱦ
ͨ�������ռ��ֹ���ֳ�ͻ�ṩ���ӿɿصĻ���

ֻҪ�ܳ�����ȫ���������е������������������ռ��ڣ�
��Ҫ����:�ࡢ����(�����ʼ������)������(���䶨��)��ģ��������ռ�

�����ռ������Ҳ�����ڶ��������������ڱ���Ψһ:  �����������ռ����ظ�����

�����ռ��ǿ��Բ�������:
	���֮ǰû����ΪPJD�������ռ䣬���������봴��һ���µ������ռ�
	��������������Ѿ����ڵ������ռ䶨�岢Ϊ�����һЩ�³�Ա������


�����ռ����֯��ʽ���������ǹ����Զ����༰�����ķ�ʽ:
	1.ͷ�ļ��е������ռ�������Ƕ����࣬�Լ�������Ϊ��ӿڵĺ���������
	2.�����ռ��Ա�Ķ��岿�������������Դ�ļ���
*/

namespace PJD
{
	class A
	{
	public:
		A() { std::cout << "A: hello world" << std::endl; }
	};
}

namespace PJD
{
	class B
	{
	public:
		B() { std::cout << "B: hello world" << std::endl; }
	};
}

namespace cplusplus_primer
{
	class Sales_data
	{
	public:
		Sales_data(std::string s, unsigned int u, double price) :bookNo(s), units_sold(u), revenue(u * price) {}
		Sales_data() :bookNo(""), units_sold(0), revenue(0) {}
		Sales_data& operator+=(const Sales_data&);
	public:
		//���ݳ�Ա
		std::string bookNo;
		unsigned int units_sold;
		double revenue;
	};
	Sales_data operator+(const Sales_data&, const Sales_data&);


	//�����ռ����Ƕ��

	//��һ��Ƕ�׵������ռ�:�����˿��Query����
	namespace QueryLib
	{
		class Query
		{

		};

		Query operator&(const Query&, const Query&);
	}

	//�ڶ���Ƕ�׵������ռ�:�����˿��Sales_data����
	namespace BookStore
	{
		class Quote
		{

		};

		class Disc_quote : public Quote
		{

		};
	}
}

