#pragma once
#include <iostream>
/*
���������ռ��е����ֿ���ֱ�ӱ���������ռ�ֱ��ʹ�á�
�������������������ռ������ǰ��ӱ�ʾ�������ռ��ǰ׺��
ͨ����������ռ�����־Ϳ���ֱ�ӷ�����

*/

//�ؼ���inline��������������ռ��һ�ζ���ĵط��������ٴ������ռ��ʱ�����дinlineҲ���Բ�д
namespace inspace
{
	inline namespace FifthEd
	{
		class Query_base
		{
		public:
			Query_base() { std::cout << "inspace::FifthEd::Query_base: hello world" << std::endl; }
		};
	}

	namespace FourthEd
	{
		class Item_base
		{
		public:
			Item_base() { std::cout << "inspace::FourthEd::Item_base: hello world" << std::endl; }
		};
		class Query_base
		{
		public:
			Query_base() { std::cout << "inspace::FourthEd::Query_base: hello world" << std::endl; }
		};
	}
}
