#pragma once
/*
�������������β���ÿ�����������
���������Ҳ������һ�����߶��Ƕ�׵������ռ䣬ֱ��������ȫ�������ռ���ҹ�����ֹ
ֻ��λ�ڿ��ŵĿ�������ʹ�õ�֮ǰ���������ֲű�����
*/

namespace A
{
	int i;
	namespace B
	{
		int i;
		int j;
		int f1()
		{
			int j;  //����ֲ�����������A::B::j
			return i;  //���ص���B::i
		}
	}  //�����ռ�B�������˺�B�ж�������ֲ��ٿɼ�
	//int f2()
	//{
	//	return j;  //��������:  jδ����
	//}
	int j = i;
}


//����λ�������ռ��е�����˵������Ĳ��ҹ�����Ȼ����
namespace AC
{
	int i;
	int k;
	class C1
	{
	public:
		C1():i(0),j(0){}
		int f1() { return k; }  //����AC::k
		//int f2() { return h; }  //����δ����h
		int f3();
	private:
		int i;  //��C1��������AC::i
		int j;
	};
	int h = i;  //��AC::i��ʼ��h
}

int AC::C1::f3() { return h; }  //��ȷ  ����AC::h