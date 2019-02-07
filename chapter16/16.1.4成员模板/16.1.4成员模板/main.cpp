#include <iostream>
#include <Windows.h>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include "debugdelete.h"
#include "Blob.h"
using namespace std;
int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);  //����Debug::operator()(double *),�ͷ�p
	int *ip = new int;
	//��һ����ʱDebugDelete�����ϵ���operator()(int*)
	DebugDelete()(ip);

	//����Ҳ������DebugDelete����unique_ptr��ɾ������
	//Ϊ������unique_ptr��ɾ����������Ҫ�ڼ������ڸ���ɾ����������
	//���ṩһ���������͵Ķ����unique_ptr�Ĺ��캯��

	//����upָ��Ķ���
	//ʵ����DebugDelete::operator()<int>(int*)
	//����ΪDebugDelete�Ŀɵ��ö������ͷ�����ָ��
	unique_ptr<int, DebugDelete> up(new int, DebugDelete());//��up�Ĺ��캯�����ṩ�˸����͵�һ��δ��������

	//����uspָ��Ķ���
	//ʵ����DebugDelete::operator()<string>(string*)
	//����ΪDebugDelete�Ŀɵ��ö������ͷ�����ָ��
	unique_ptr<string, DebugDelete>usp(new string, DebugDelete());

	//ʵ����һ����ģ��ĳ�Աģ�塣���Ǳ����ṩ��ͺ���ģ���ʵ�Ρ�
	//���������ݸø���������������ƶ���ģ�������ʵ��
	//������ͨ�����ݴ��ݸ���Աģ��ĺ���ʵ�����ƶ�����ģ��ʵ��
	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<long> vi = { 0,1,2,3,4,5,6,7,8,9 };
	list<const char*> w = { "now","is","the","time" };
	//ʵ����Blob<int>���Լ���������int*�����Ĺ��캯��
	Blob<int> a1(begin(ia), end(ia));
	cout << typeid(a1).name() << endl;
	//ʵ����Blob<int>�����2��vector<long>::iterator�Ĺ��캯��
	Blob<int> a2(vi.begin(), vi.end());
	cout << typeid(a2).name() << endl;
	//ʵ����Blob<string>���Լ���������list<const char*>::iterator�����Ĺ��캯��
	Blob<string> a3(w.begin(), w.end());
	cout << typeid(a3).name() << endl;


	system("pause");
	return 0;
}