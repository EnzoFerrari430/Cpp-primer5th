#include <iostream>
#include <Windows.h>

/*
��һ���˽⵽�����ڽ���������ʵ�εĺ�����˵�������ֲ��ҽ���ʵ���������������ռ��н���
������������������ȷ����ѡ������ͬ��Ҳ��Ӱ��
���ǽ���ÿ��ʵ����(�Լ�ʵ����Ļ���)�����������ռ�����Ѱ��ѡ����
*/

namespace NS
{
	class Quote
	{

	};
	void display(const Quote& item)
	{
		std::cout << "function display" << std::endl;
	}

}

class Bulk_item : public NS::Quote
{

};


namespace P1
{
	void print(double d)
	{
		std::cout << "print function in namespace P1 and parameter is double" << std::endl;
	}
}

namespace P2
{
	void print(int a)
	{
		std::cout << "print function in namespace P2 and parameter is int" << std::endl;
	}
}

void print()
{
	std::cout << "print function in global" << std::endl;
}
using namespace P1;
using namespace P2;

int main()
{
	Bulk_item book1;
	display(book1);

	//����usingָʾ��˵������һ�������к����β��б���ȫ��ͬ�ĺ����������������
	//��ʱ��ֻҪ����ָ�����õ��������ռ��еĺ����汾���ǵ�ǰ�������еİ汾����
	print();
	print(3.14);
	print(3);

	system("pause");
	return 0;
}