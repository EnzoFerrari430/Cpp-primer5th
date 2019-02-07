#include <iostream>
#include <string>
#include <cstring>
#include <Windows.h>
using namespace std;

/*
һ�������Ͳ�����ʾһ��ֵ����һ�����͡�
����ͨ��һ���ض������������ǹؼ���class��typename��ָ�������Ͳ���

�ڵ���compare("hi", "mom")ʱ
��������ʵ�������°汾
int compare(const char (&p1)[3],const char (&p2)[4])
*/

template <int N, int M>
int compare(const char(&p1)[N], const char(&p2)[M])
{
	cout << N << " " << M << endl;
	return strcmp(p1, p2);
}


//�����Ͳ��ö������βδ���һ��ָ����С���β���
template <int N, int M>
int compareInt(const int(&p1)[N], const int(&p2)[M])
{
	cout << N << " " << M << endl;
	return 0;
}

/*
����ģ�����������inline����constexpr�ģ���ͬ��ģ�庯��һ����
inline��constexpr˵��������ģ������б�֮�󣬷�������֮ǰ��
*/
//��ȷ��inline˵��������ģ������б�֮��
template <typename T> inline T Mymin(const T&, const T&);
//����inline˵������λ�ò���ȷ
//inline template<typename T> T min2(const T&, const T&);


/*
��д�����޹صĴ���:ģ�����Ӧ�þ������ٶ�ʵ�����͵�Ҫ��
	1.ģ���еĺ���������const������
		ͨ�������������趨Ϊconst�����ã����Ǳ�֤�˺����������ڲ��ܿ��������͡�
	2.�������е������жϽ�ʹ��<�Ƚ�����
		ֻʹ��<�жϽ�����compare������Ҫ��������͵�Ҫ��

���Ҫ��Ŀ��������޹غͿ���ֲ�ԣ�������Ҫ�õ�less
*/
template <typename T> int compare2(const T &v1, const T &v2)
{
	if (less<T>()(v1, v2))
		return -1;
	if (less<T>()(v2, v1))
		return 1;
	return 0;
}

/*
����ģ�����ģ���Ա�����Ķ���ͨ������ͷ�ļ���
*/

int main()
{
	compare("hi", "mom");

	compareInt({ 1, 2, 3 }, { 4, 5, 6 });
	int a[10] = { 1,2,3,4,5 };
	int b[5] = { 1,3,5,7,9 };
	compareInt(a,b);

	system("pause");
	return 0;
}
