#include <iostream>
#include <Windows.h>
#include <string>
#include "tmp.h"
#include "friend.h"
/*
ʵ����صĲ��Һ�����������β�
std::string s;
std::cin>>s;
��������֪�ģ��õ��õȼ���
operator>>(std::cin,s);
operator>>���������ڱ�׼��string�У�string�ֶ����������ռ�std��
��������Ӧ��Ҫ���µ���
std::operator>>(std::cin,s);
����
using std::operator>>
operator>>(std::cin,s);
�������ﶼ����Ҫ!!!


���������ռ������ֵ����ع�����˵��һ����Ҫ�����⣬��ʹ�����ǿ���ֱ�ӷ�����������������
��������ǣ������Ǹ���������һ�������͵Ķ���ʱ�������ڳ�������������֮�⻹�����ʵ���������������ռ�
��һ������ڴ���������û�ָ��ĵ���ͬ����Ч

*/

using namespace A;
int main()
{

	//std::cout << f2() << std::endl;

	std::string s;
	operator >> (std::cin, s);
	//�����������ֶ�operator>>�ĵ���ʱ�������ڵ�ǰ����������Ѱ�Һ��ʵĺ���
	//���Ų�������������������
	//�����Ϊ>>���ʽ���β��������ͣ����Ա������������cin��s���������������ռ�
	operator<<(std::cout, s);
	std::cout << std::endl;


	FRIEND::C obj;
	//�����������ֶ�f�ĵ���ʱ�������ڵ�ǰ����������Ѱ�Һ��ʵĺ���
	//���Ų������������
	//�����Ϊf�������β��������ͣ����Ա������������obj���������������ռ�
	f(obj);
	//f2();


	system("pause");
	return 0;
}