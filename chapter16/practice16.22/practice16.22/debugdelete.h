#pragma once
#include <iostream>
#include <typeinfo>
/*
һ����(��������ͨ����������ģ��)���԰���������ģ��ĳ�Ա������
���ֳ�Ա����Ϊ��Աģ�塣
������Աģ�岻�����麯��
*/

//��ͨ(��ģ��)��ĳ�Աģ��
class DebugDelete
{
public:
	DebugDelete(std::ostream& s = std::cerr):os(s){}
	//���κκ���ģ����ͬ,T�������б������ƶ�
	template <typename T>
	void operator()(T* p)const
	{
		os << "deleting unique_ptr: " << typeid(T).name() << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};