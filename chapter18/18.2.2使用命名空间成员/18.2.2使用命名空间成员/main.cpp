#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;
/*
usingָʾʾ��
*/

namespace blip
{
	int i = 16, j = 15, k = 23;
}

int j = 0;

void manip()
{
	//usingָʾ,blip�е����ֱ�"���"��ȫ����������
	//usingָʾ�������������ռ���������ݱ����Ч��
	//���usingָʾһ�㱻�����ǳ���������������������
	using namespace blip;  //���ʹ����j,����::j��blip::j֮�������ͻ
	++i;
	/*
	blip�ĳ�Ա�����������Ƕ�����blip��manip���ڵ�������һ��.
	�������ռ䱻ע�뵽�������������֮�󣬺ܿ��ܸ������ռ��ж�������ֻ���������������еĳ�Ա��ͻ
	���ֳ�ͻ��������ڵģ�������Ҫʹ�ó�ͻ�����֣����Ǿͱ�����ȷָ�����ֵİ汾
	*/
	//++j;
	++::j;
	++blip::j;
	/*
	usingָʾһ�㱻�����ǳ���������������������
	���blip::k������һ��ȫ�ֱ���
	��manip�����ڲ���k����ֲ���������������
	*/
	int k = 97;
	++k;

	cout << i << endl;
	cout << ::j << endl;
	cout << blip::j << endl;
	cout << blip::k << endl;
	cout << k << endl;
}


int main()
{
	manip();
	system("pause");
	return 0;
}