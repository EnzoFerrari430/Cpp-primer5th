#pragma once
#include <memory>
#include <vector>
/*
������ģ�壬����Ҳ����Ϊ�䶨���Աģ�塣
�ڴ�����£���ͳ�Ա�������Լ��Ķ�����ģ�����
*/
template <typename T>
class Blob
{
public:
	//�˹��캯�����Լ���ģ���������It����Ϊ����������������������
	template <typename It> Blob(It b, It e);
private:
	std::shared_ptr<std::vector<T>> data;
};

//��ģ��ĺ���ģ�������ⶨ��ʱ������ͬʱΪ��ģ��ͳ�Աģ���ṩģ������б�
//��ģ�������ǰ������Լ���ģ���б�
template <typename T>
template <typename It>
Blob<T>::Blob(It b,It e):data(std::make_shared<std::vector<T>>(b,e)){}