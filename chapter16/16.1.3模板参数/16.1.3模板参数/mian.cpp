#include <iostream>
#include <Windows.h>
#include "Tep.h"
#include "classmem.h"
using namespace std;

/*
һ��ģ��������Ŀ��÷�Χ����������֮����ģ�������������֮ǰ��
ģ������������������������������ͬ���֡�
�������������������Ĳ�ͬ����ģ���ڲ�������ģ�������
*/
//typedef double A;
//template <typename A,typename B> void f(A a, B b)
//{
//	A tmp = a;
//	double B;
//	cout << tmp << " " << b << endl;
//}

int main()
{

	f(1, 2);

	//���û���������汾��compareʱ�������ṩ�Լ��ıȽϲ��������Ⲣ���Ǳ����
	bool i = compare(0, 42);  //ʹ��less��iΪ-1
	//Sales_data item1(cin), item2(cin);
	//bool j = compare(item1, item2, compareIsbn);



	system("pause");
	return 0;
}