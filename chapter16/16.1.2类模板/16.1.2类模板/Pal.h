#pragma once
#include <string>
/*
һ����Ҳ���Խ���һ��ģ���ÿ��ʵ��������Ϊ�Լ�����Ԫ�������޶��ض���ʵ��Ϊ��Ԫ
*/

//ǰ���������ڽ�ģ���һ���ع�ʵ������Ϊ��ԪʱҪ�õ�
template <typename T> class Pal;
class C  //C��һ����ͨ�ķ�ģ����
{
	friend class Pal<C>;  //����Cʵ������Pal��C��һ����Ԫ
	//Pal2������ʵ������C����Ԫ�������������ǰ������
	template <typename T> friend class Pal2;
};

template <typename T>
class C2  //C2��һ����ģ��
{
	//C2��ÿ��ʵ������ͬʵ������Pal����Ϊ��Ԫ
	friend class Pal<T>;  //Pal��ģ��������������������
	//Pal2������ʵ������C2��ÿ��ʵ������Ԫ������Ҫǰ������
	template <typename X> friend class Pal2;
	//Pal3��һ����ģ���࣬����C2����ʵ������Ԫ
	friend class Pal3;
};

//��ģ���Լ������Ͳ�����Ϊ��Ԫ
//��C++11�±�׼�У����ǿ��Խ�ģ�����Ͳ�������Ϊ��Ԫ
template <typename Type>
class Bar
{
	friend Type;  //������Ȩ����������ʵ����Bar������
};

//��Ȼ���ǲ��ܶ���һ��typedef����һ��ģ�塣����typedef Blob<T>
//����C++11�±�׼��������Ϊ��ģ�嶨��һ�����ͱ���
template <typename T> using twin = pair<T, T>;
twin<std::string> authors;  //authors��һ��pair<string,string>

//�����Ƕ���һ��ģ�����ͱ���ʱ�����Թ̶�һ������ģ�����
template <typename T> using partNo = pair<T, unsigned>;
partNo<std::string> books;  //books��һ��pair<std::string,unsigned>